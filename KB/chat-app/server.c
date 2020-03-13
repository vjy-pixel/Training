///////////// Server //////////////
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MSG_LEN 1024

/*To add coloures in output*/

/*Colour of Server Chat*/
void cyn();

/*Colour of Client Chat*/
void yellow();
void red();
void reset();

void main(){
	
	struct sockaddr_in serverAdd,clientAdd;
	
	int iServerSkt, iClientSkt;
	char cMsg[MSG_LEN];
	
	char *serverIP = "127.0.0.1";
	short serverPort = 8080;
	char *clientIP = "127.0.0.1";
	short clientPort = 8081;
	
	int iClientLen;
	int iTemp;

	iServerSkt = socket(AF_INET, SOCK_DGRAM, 0);

	serverAdd.sin_family = AF_INET;
	serverAdd.sin_port = htons(serverPort);
	serverAdd.sin_addr.s_addr = inet_addr(serverIP);

	bind(iServerSkt,(struct sockaddr*) &serverAdd, sizeof(serverAdd));

	printf("\nServer Ready, Waiting for Client!!!\n");

	while(1){
		
		iClientSkt = socket(AF_INET,SOCK_DGRAM,0);
		clientAdd.sin_family = AF_INET;
		clientAdd.sin_port = htons(clientPort);
		clientAdd.sin_addr.s_addr = inet_addr(clientIP);

		cyn();
		printf("\nServer:");
		
		bzero(cMsg, MSG_LEN);
		fgets(cMsg, MSG_LEN, stdin);

		/*Here 10 is used as fgets don't go to new line itself*/
		/*So there will be diff of ascii of new line which is 10*/
		if(strcmp(cMsg,"X--X")==10){
			sendto(iClientSkt, cMsg, strlen(cMsg), 0,(struct sockaddr *) &clientAdd, sizeof(clientAdd));
			red();
			printf("\n------ Chat Terminated!!! --------\n");
			break;
		}
	
		sendto(iClientSkt, cMsg, strlen(cMsg), 0,(struct sockaddr *) &clientAdd, sizeof(clientAdd));
		
		close(iClientSkt);

		bzero(cMsg, MSG_LEN);
		
		iTemp = recvfrom(iServerSkt, cMsg, MSG_LEN, 0,(struct sockaddr *)&clientAdd, &iClientLen);
		
		
		/*Here 10 is used as fgets don't go to new line itself*/
		/*So there will be diff of ascii of new line which is 10*/
		if(strcmp(cMsg,"X--X")==10){
			red();
			printf("\n------ Chat Terminated!!! -------\n");
			break;
		}
		cMsg[iTemp] = 0;
		yellow();
		printf("\nClient:%s",cMsg);
		

	}
	close(iServerSkt);
}

void cyn() {
  printf("\033[1;36m");
}

void yellow() {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}
void reset () {
  printf("\033[0m");
}


