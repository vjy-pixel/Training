#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

#define BUFLEN 1024
#define TOTAL_CLIENTS 20
#define PORT 8080

int clientIndex=0;

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


/*******************************************************************************
	* A method to add port number in LINKED LIST as new client gets connected
	*
	* @param int (which is port number of newly connected client)
	*
	* @return void
********************************************************************************/
void add2List(int);

/*******************************************************************************
	* A method to check whether the client is new or old by referring its port
	*
	* @param int (which is port number of client)
	*
	* @return void
********************************************************************************/
bool checkList(int);

/*******************************************************************************
	* A method to remove port number from LINKED LIST if client gets terminated
	*
	* @param int (which is port number of client)
	*
	* @return void
********************************************************************************/
void removeClient(int);

/*******************************************************************************
	* A method to add port number in LINKED LIST as new client gets connected
	*
	* @param int (which is port number of newly connected client)
	*
	* @return void
********************************************************************************/
void showList();

/*******************************************************************************
	* A method to broadcast termination command among all connected clients
	*
	* By referring LINKED LIST
	*
	* @param int (socket file descriptor), struct sockadddr_in (client address)
	*
	* @return void
********************************************************************************/
void broadcastTermination(int,struct sockaddr_in);

struct Node{
	int data;
	struct Node *next;
}*head;

void main(int argc, char *argv[])
{	

	int sockfd, len, iTemp;
	
	int port;//as parameter to pass port number to the functions of LINKED LIST

	struct sockaddr_in server; // server address
	struct sockaddr_in client; // client address
	socklen_t addr_size;
	
	char buffer[BUFLEN];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd<0)
	{
		printf("Error in Socket Creation\n");
		exit(1);
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	if(bind(sockfd, (struct sockaddr *)&server,sizeof(server)) < 0)
	{
		printf("Error in binding!!!\n");
		close(sockfd);
		exit(1);
	}
	printf("Binding Complete!!!!\n");

	len = sizeof(client);
	while(1)
	{
		/*Receiving from Client*/
		bzero(buffer, BUFLEN);
		iTemp = recvfrom(sockfd, buffer, BUFLEN, 0, (struct sockaddr *)&client, &len);
		port= ntohs(client.sin_port);
		if(iTemp < 0)
		{	
			printf("Error: Receiving Msg from client!!!\n");
			close(sockfd);
			exit(1);
		}

		if(strcmp(buffer,":exit:")==10)
		{
			
			removeClient(port);
			printf("Client: %s:%d\n disconnected!!\n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
			showList();
			continue;
		}
		else
		{
			int check = checkList(port);
			
			if(check == 0)
			{
				add2List(port);
				showList();
			}
			printf("\nMsg from: %s:%d\n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
			printf("Client(%d):%s\n",ntohs(client.sin_port),buffer);	
		}	

		/*Sending to Client*/
		bzero(buffer, BUFLEN);
		printf("Server:");
		fgets(buffer, BUFLEN, stdin);
		
		if(strcmp(buffer,":exit:")==10)
		{
			broadcastTermination(sockfd,client);
			printf("Server Termiated!!!!\n");
			close(sockfd);
			exit(1);
		}
		
		if(sendto(sockfd, buffer, BUFLEN,0, (struct sockaddr *)&client, sizeof(client))<0)
			printf("Error: in Sending\n");
		printf("Msg sent to: %s:%d\n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
	}
}


void add2List(int port)
{
	clientIndex++;
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp;
	if(clientIndex <= 20)
	{
			node->data = port;
			if(clientIndex==1)
			{
				head = node;
				head->next = head;
			}
			else
			{
				temp = head;
				for(int i=0; i<clientIndex; i++)
				{
					if(temp->next == head)
					{
						temp->next = node;
						node->next = head;
					}
					temp = temp->next;
				}
			}

	}
	else
		exit(1);
}

bool checkList(int port)
{
	struct Node *temp;

	temp = head;
	for(int i=0; i<clientIndex; i++)
	{
		if(temp->data == port)
			return 1;
		else
			temp = temp->next;
	}
	return 0;
}

void removeClient(int port)
{
	printf("fdsfdsfsdfsdf\n");
	struct Node *temp,*prev;

	temp = head;
	for(int i=0; i<clientIndex; i++)
	{
		if(head->data == port)
		{
			head = head->next;
			temp = head;
			
			return;
		}
		else if(temp->data == port)
		{
			prev->next = temp->next;
			clientIndex--;
			temp = head;
			return;
		}

		else
		{
			prev = temp;
			temp = temp->next;
		}
	}

	
}

void showList()
{
	struct Node *temp;

	temp = head;
	printf("\n");
	printf("Total Clients:%d\n",clientIndex);
	printf("ll:");
	for(int i=0; i<clientIndex; i++)
	{
		printf("%d--",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void broadcastTermination(int sockfd,struct sockaddr_in client)
{
	struct Node* temp;
	temp = head;

	for(int i=0; i<clientIndex; i++)
	{
		client.sin_port = ntohs(temp->data);
		sendto(sockfd, ":exit:", BUFLEN,0, (struct sockaddr *)&client, sizeof(client));
		printf("Msg sent to: %s:%d\n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		temp = temp->next;
	}
}