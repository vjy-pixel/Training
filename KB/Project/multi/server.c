#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define BUFLEN 1024
#define PORT 8080
int main(void)  
 {  
 struct sockaddr_in my_addr, cli_addr[10],cli_temp;  
 int sockfd;  
 socklen_t slen[10],slen_temp;

 slen_temp = sizeof(cli_temp);
 char buf[BUFLEN];  
 int clients = 0;
 int client_port[10];

 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0))==-1)
 {
     printf("test\nsocket");
     //err("socket");  
 }else{  
     printf("Server : Socket() successful\n");  
 }   
 bzero(&my_addr, sizeof(my_addr));  
 my_addr.sin_family = AF_INET;  
 my_addr.sin_port = htons(PORT);  
 my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  

 if (bind(sockfd, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
 {
     printf("bind");  
 }else{
     printf("Server : bind() successful\n");  
 }

 int num_clients = 0;

 sockaddr_in temp_addr;
 while(1)  
 {
     //receive
     printf("Receiving...\n");
     if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_temp, &slen_temp)==-1)  
         printf("recvfrom()");

    if(temp_addr != cli_temp){
        temp_addr = cli_temp;
        printf("%d.%d.%d.%d",cli_temp.sin_addr.s_addr & 0xff,(cli_temp.sin_addr.s_addr & 0xff00) >> 8,(cli_temp.sin_addr.s_addr & 0xff0000) >> 16,(cli_temp .sin_addr.s_addr & 0xff000000) >> 24);
        printf(" added\n");
    }
    
    printf("client:%s\n",buf);

    for(int i=0;i< clients;i++) {
            bzero(buf,BUFLEN);
            fgets(buf,BUFLEN,stdin);
            sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr[i], sizeof(cli_addr[i]));

    }

     if (clients <= 10) {
        cli_addr[clients] = cli_temp;
        client_port[clients] = ntohs(cli_addr[clients].sin_port);
        clients++;
        printf("Client added\n");
        //printf("%d",clients);
        //int i;
        
     }
 }  

 close(sockfd);  
 return 0;  
}