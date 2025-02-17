#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit, atoi, malloc, free */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <errno.h>
#include <netinet/in.h>
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h>

#define PORT 53
#define MAXLINE 1000 

enum QueryType {
   QT_A = 1,     //IPv4 
   QT_NS = 2,    //Nameserver
   QT_CNAME = 5, //Canonical name
   QT_SOA = 6,   //Start of authority zone
   QT_PTR = 12,  //Domain name pointer
   QT_MX = 15,   //Mail server
};

//Define new alignment and push old onto the stack
#pragma pack(push, 1)
struct R_DATA {
   unsigned short type;
   unsigned short _class;
   unsigned int ttl;
   unsigned short data_len;
};
#pragma pack(pop)
//Pop previously pushed alignment onto the stack

struct RES_RECORD {
   unsigned char *name;
   struct R_DATA *resource;
   unsigned char *rdata;
};

struct QUESTION
{
   unsigned short qtype;
   unsigned short qclass;
};

typedef struct
{
   unsigned char *name;
   struct QUESTION *ques;
} QUERY;


//DNS header structure
//bit field
//Flags: 0x8180 Standard query response, No error
struct DNS_HEADER
{
    unsigned short id; // Transaction ID: e.g 0x4bab (2 bytes (short))
    unsigned char rd :1; // recursion desired        (flag, 1 bit)
    unsigned char tc :1; // truncated message        (flag, 1 bit)
    unsigned char aa :1; // authoritive answer       (flag, 4 bits)
    unsigned char opcode :4; // purpose of message   (flag, 1 bit)
    unsigned char qr :1; // query/response flag      (flag, 1 bit)
    unsigned char rcode :4; // response code         (flag, 4 bits)
    unsigned char cd :1; // checking disabled        (flag, 1 bit)
    unsigned char ad :1; // authenticated data       (flag, 1 bit)
    unsigned char z :1; // its z! reserved           (flag, 1 bit)
    unsigned char ra :1; // recursion available      (flag, 1 bit)
   //Flag portion of our DNS_HEADER structure.       16 bits total

    unsigned short q_count; // number of question entries 
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};

void ExitEventHandler(void);
void Resolve(unsigned char*,int,void*);

int sfd;
int main()
{

   atexit(ExitEventHandler);

   /**
    * 4.1.2. Question section format  
    * QNAME   
    a domain name represented as a sequence of labels, where
    each label consists of a length octet followed by that
    number of octets.  The domain name terminates with the
    zero length octet for the null label of the root....
    */

   //Resovle domain to IPv4 address (QT_A)

   unsigned char buffer[65536];
   Resolve("4zive2sk", QT_A,(void*)&buffer);

   struct DNS_HEADER *dns = (struct DNS_HEADER*)buffer;

   printf("\nTransaction ID: 0x%x", dns->id);
   printf("\nThe response contains : \n");
   printf("%d Questions.\n", ntohs(dns->q_count));
   printf("%d Answers.\n",ntohs(dns->ans_count));
   printf("%d Authoritative Servers.\n",ntohs(dns->auth_count));
   printf("%d Additional records.\n",ntohs(dns->add_count));


}

void Resolve(unsigned char *hostname, int query_type, void *extBuffer) {
   
   //Utilize public DNS
   char *server = "8.8.8.8";
   unsigned char buf[65536], *qname, *reader;

   //for now, pass hostname in this format 3www6google3com
   qname = hostname;

   int i, j, stop, sfd;

   struct sockaddr_in src,dest;

   //Replies from the server
   struct RES_RECORD answers[20],auth[20],addit[20];

   struct DNS_HEADER *dns = NULL;
   struct QUESTION *qinfo = NULL;

   sfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
   printf("Opened socket. Descriptor -> %d\n", sfd);

   //setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR)
   dest.sin_family = AF_INET;
   dest.sin_port = htons(PORT);
   dest.sin_addr.s_addr = inet_addr(server);

   //cast pointer to a  buffer of bytes
   //to struct DNS_HEADER
   dns = (struct DNS_HEADER*)&buf;

   dns->id = (unsigned short) htons(getpid());
   dns->qr = 0; // query 0, response 1
   dns->opcode = 0; // standard query
   dns->aa = 0; // not authoritative
   dns->tc = 0; // not truncated
   dns->rd = 1; // recursion 
   dns->ra = 0; // recursion not available
   dns->z = 0;
   dns->ad = 0; // authenticated data
   dns->cd = 0; // checking disabled
   dns->rcode = 0;
   dns->q_count = htons(1);
   dns->ans_count = 0;
   dns->auth_count = 0;
   dns->add_count = 0;

   //point to the query portion
   qname = (unsigned char*)&buf[sizeof(struct DNS_HEADER)];

   qinfo =(struct QUESTION*)&buf[sizeof(struct DNS_HEADER) + (strlen((const char*)qname) + 1)]; //fill it

   qinfo->qtype = htons(query_type); // query type A,MX,AAAA,CNAME,NS
   qinfo->qclass = htons(1); // internet
   
   printf("Sending request packet\n");

   //UDP is a stateless transport layer protocol. 
   //Just fire a request and handle possible failures
   if( sendto(sfd,(char*)buf,sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION),0,(struct sockaddr*)&dest,sizeof(dest)) < 0)
    {
        perror("Sending request packet failed\n");
    } else {
        printf("Packet sent\n");
    }

    //No block until we receive answer
    i = sizeof(dest);
    printf("Receiving answer packet...\n");

    if(recvfrom(sfd, (char*)buf, sizeof(buf), 0, (struct sockaddr*)&dest, (socklen_t*)&i) < 0)
    {
      perror("Receiving answer packet failed\n");
    } else {
      printf("Packet received\n");
    }

    dns = (struct DNS_HEADER*)buf;

    memcpy(extBuffer,buf,65536);


   
}

void ExitEventHandler() {
   printf("Closing file descriptor %d\n",sfd);
   //shutdown(sfd, SHUT_RD);
}