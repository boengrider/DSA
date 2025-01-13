#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit, atoi, malloc, free */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */


int main() {
    
   struct hostent *dnsEntry = gethostbyname("zive.sk");
   
   printf("%d.",255 & dnsEntry->h_addr_list[0][0]);

   printf("%d.",255 & dnsEntry->h_addr_list[0][1]);

   printf("%d.",255 & dnsEntry->h_addr_list[0][2]);

   printf("%d\n",255 & dnsEntry->h_addr_list[0][3]);



   
}