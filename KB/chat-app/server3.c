#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFLEN 1024
#define PORT 8080

void err(char *s)  
{  
perror(s);  
exit(1);  
}

int main(void)  
 {  
 struct sockaddr_in my_addr, cli_addr[10],cli_temp;  
 int sockfd;  
 socklen_t slen[10],slen_temp;

 slen_temp = sizeof(cli_temp);
 char buf[BUFLEN];  
 int clients = 0;
 int client_port[10];

 if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
 {
     printf("test\n");
     err("socket");  
 }else{  
     printf("Server : Socket() successful\n");  
 }   
 bzero(&my_addr, sizeof(my_addr));  
 my_addr.sin_family = AF_INET;  
 my_addr.sin_port = htons(PORT);  
 my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  

 if (bind(sockfd, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
 {
     err("bind");  
 }
 else{
     printf("Server : bind() successful\n");  
 }

 //int num_clients = 0;
 while(1)  
 {
     //receive
     printf("Receiving...\n");
     if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_temp, &slen_temp)==-1)  
         err("recvfrom()");

     if (clients <= 10) {
        cli_addr[clients] = cli_temp;
        client_port[clients] = ntohs(cli_addr[clients].sin_port);
        clients++;
        printf("Client added\n");
        //printf("%d",clients);
        int i;
        for(i=0;i<clients;i++) {
            sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr[i], sizeof(cli_addr[i]));

        }
     }
 }  

 close(sockfd);  
 return 0;  
}