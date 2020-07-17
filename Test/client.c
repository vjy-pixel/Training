// Client side implementation of UDP client-server model 
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
	
	struct sockaddr_in	 servaddr; 

	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	int n, len; 
	while(1){
		fflush(stdin);
		printf("\nClient:");
		fgets(buffer2, MAXLINE, stdin);
		sendto(sockfd, (const char *)buffer2, strlen(buffer2), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
		//printf("Hello message sent.\n"); 
		if(strcmp(buffer2,"EndChat")==0)
			break;
		recvfrom(sockfd, (char *)buffer1, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len); 
	 
		printf("Server : %s\n", buffer1); 

		close(sockfd);
	} 
	return 0; 
} 
