#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit, atoi, malloc, free */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <errno.h>
#include <netinet/in.h>
#include <ctype.h>

int getSystemDnsServers(char*,size_t);

int main() {


   /** 
   char *addrs[] = {"zive.sk", "dsl.sk", "swiss-point.eu"};

   for(int i = 0; i < 3; i++) {
      
      struct hostent *dnsEntry = gethostbyname("zive.sk");
   
      printf("%d.",255 & dnsEntry->h_addr_list[0][0]);
      printf("%d.",255 & dnsEntry->h_addr_list[0][1]);
      printf("%d.",255 & dnsEntry->h_addr_list[0][2]);
      printf("%d\n",255 & dnsEntry->h_addr_list[0][3]);

   }

   **/

   //struct hostent *dnsEntry = gethostbyname("fulfillment.swiss-point.eu");

   struct hostent *dnsEntry = gethostbyname("sme.sk");
   
    switch(dnsEntry->h_addrtype) {
        case AF_INET:
            printf("IPv4 address(es):\n");
            break;

        case AF_INET6:
            printf("IPv6 address(es):\n");
            break;

    }
    
    int addr = 0;

    while(dnsEntry->h_addr_list[addr] != NULL) {
    
        printf("%d.",255 & dnsEntry->h_addr_list[addr][0]);
        printf("%d.",255 & dnsEntry->h_addr_list[addr][1]);
        printf("%d.",255 & dnsEntry->h_addr_list[addr][2]);
        printf("%d ",255 & dnsEntry->h_addr_list[addr][3]);
        printf("(%s)\n",dnsEntry->h_name);

        addr++;

    }

    char dnsList[200];

    int serversFound = 0;
    serversFound = getSystemDnsServers(dnsList, sizeof(dnsList));
        

    printf("Servers found %d\n", serversFound);
   

  
    for(int i = 0; i < serversFound; i++)
        printf("Nameserver found in the /etc/resolv.conf %s\n", dnsList + (16 * i));
    

}



/**
 * Return int specifying number of nameservers found
 * in the /etc/resolv.conf
 * 
 * Fills the provided buffer with string representations
 * of ip addresses of nameservers found
 * 
 * If error occurs negative value is returned
 */
int getSystemDnsServers(char *buffer, size_t size) {

    FILE *fd = fopen("/etc/resolv.conf", "r"); // handle
    size_t pos = 0; //position into the buffer

    if(fd == NULL)
        return -1;

    char __buffer[100], *line;
    
    while((line = fgets(__buffer, sizeof(__buffer), fd)) != NULL) {
       if(line[0] == '#') {
            // skip comment
            continue;
       } else {
            strcpy(buffer + pos, line + 10); //skips 'nameserver' part. Also copies terminating null char
            pos += 16; // adjust position
            
       }

    }

    return pos / 16; // number of entries found
    
}