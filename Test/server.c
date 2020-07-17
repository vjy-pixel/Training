// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd; 
	char buffer1[MAXLINE],buffer2[MAXLINE]; 
	
	struct sockaddr_in servaddr, cliaddr; 
	
	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	printf("Server Ready!!, Waiting for Client!!\n");
	int len, n; 

	len = sizeof(cliaddr); //len is value/resuslt 

	while(1){
		//printf("again");
		fflush(stdin);
		recvfrom(sockfd, (char *)buffer1, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
		
		if(strcmp(buffer1,"EndChat")==0)
			break; 

		printf("Client : %s\n", buffer1); 
		printf("Server:");
		fgets(buffer2, MAXLINE, stdin);
		sendto(sockfd, (const char *)buffer2, strlen(buffer2), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
		close(sockfd); 
		//printf("Hello message sent.\n"); 
	}
	return 0; 
} 
