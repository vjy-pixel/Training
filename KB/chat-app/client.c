////////////// Client ///////////////
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MSG_LEN 1024

/*To add Colours in output*/

/*Colour of Server Chat*/
void cyn();

/*Colour of Client Chat*/
void yellow();

void red();
void reset();

void main(){
	
	int iServerSkt,iClientSkt;
	int iServerLen;
	
	int iTemp;
	
	struct sockaddr_in serverAdd, clientAdd;

	char cMsg[MSG_LEN];

	char *serverIP = "127.0.0.1";
	short serverPort = 8080;
	char *clientIP = "127.0.0.1";
	short clientPort = 8081;

	iClientSkt = socket(AF_INET, SOCK_DGRAM, 0);
	
	clientAdd.sin_family = AF_INET;
	clientAdd.sin_port = htons(clientPort);
	clientAdd.sin_addr.s_addr = inet_addr(clientIP);

	printf("\nClient Ready!!!\n");
	
	bind(iClientSkt, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	while(1){

		iServerSkt = socket(AF_INET, SOCK_DGRAM, 0);
		serverAdd.sin_family = AF_INET;
		serverAdd.sin_port =htons(serverPort);
		serverAdd.sin_addr.s_addr = inet_addr(serverIP);

		bzero(cMsg,MSG_LEN);
		iTemp = recvfrom(iClientSkt, cMsg, MSG_LEN, 0, (struct sockaddr *)&serverAdd, &iServerLen);
		
		/*Here 10 is used as fgets don't go to new line itself*/
		/*So there will be diff of ascii of new line which is 10*/
		if(strcmp(cMsg,"X--X")==10){
			red();
			printf("\n------- Chat Terminated!!! --------\n");
			break;
		}
		cMsg[iTemp] = 0;

		
		cyn();
		printf("\nServer:%s", cMsg);
		
		yellow();
		printf("\nClient:");

		bzero(cMsg, MSG_LEN);
		fgets(cMsg, MSG_LEN, stdin);

		/*Here 10 is used as fgets don't go to new line itself*/
		/*So there will be diff of ascii of new line which is 10*/		
		if(strcmp(cMsg,"X--X")==10){
			sendto(iServerSkt, cMsg, strlen(cMsg), 0,(struct sockaddr *) &serverAdd, sizeof(serverAdd));
			red();
			printf("\n------ Chat Terminated!!! -------\n");
			break;
		}
		
		

		sendto(iServerSkt, cMsg, strlen(cMsg), 0,(struct sockaddr *) &serverAdd, sizeof(serverAdd));
		close(iServerSkt);
		
	}
	close(iClientSkt);
}

		
void cyn () {
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