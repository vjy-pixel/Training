#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define BUFLEN 1024
#define PORT 8080


/********************************************************************
	* Here, as server gets connected with diff clients,
	*
	* Port number of each client is stored in CIRCULAR LINEKD LIST
	*
	* Now whenever server terminates from its side it will broadcast
	*
	* the ":exit:" commmand to all the client which are conneted 
	*
	* By Referring LINKED LIST
	*
	* Here it is ASSUMED that server and client are on same machine
	*
	* That's why LOCALHOST 127.0.0.1 is used
*********************************************************************/


void main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <server-addr>",argv[0]);
		exit(1);
	}

	int sockfd; // socket file descriptor
	int iTemp; // temp variable for acknowledgement of recvfrom function
	int length; // length of server address

	struct sockaddr_in server;//server address
	
	char buffer[BUFLEN];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd<0)
	{
		printf("Error in Socket Creation\n");
		close(sockfd);
		exit(1);
	}

	memset(&server, '\0', sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	
	while(1)
	{

		bzero(buffer, BUFLEN);
		
		printf("Type \":exit:\" to Terminate!!!!!\n");
		printf("Client:");
		fgets(buffer, BUFLEN, stdin);
		if(strcmp(buffer,":exit:")==10)
		{
			sendto(sockfd, buffer, BUFLEN,0, (struct sockaddr *)&server, sizeof(server));
			printf("Terminated!!!\n");
			close(sockfd);
			exit(1);
		}

		sendto(sockfd, buffer, BUFLEN,0, (struct sockaddr *)&server, sizeof(server));
		printf("Message sent!!!\n");

		
		bzero(buffer, BUFLEN);
		iTemp = recvfrom(sockfd, buffer, BUFLEN,0, (struct sockaddr *)&server, &length);
		
		if(iTemp < 0)
		{	
			printf("Error: Receiving Msg from server!!!\n");
			close(sockfd);
			exit(1);
		}
		else if(strcmp(buffer,":exit:")==0)
		{
			printf("\":exit:\" command got from Server. Server Disconnected!!!\n");
			close(sockfd);
			exit(1);
		}
		else
		{
			printf("Server:%s\n",buffer);
		}		
		
	}
}
