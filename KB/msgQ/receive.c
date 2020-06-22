#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<errno.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t mutex;
#define BUFSIZE 1024
#define TOTAL_CLIENTS 3

struct my_msg_st
{
	long int msgType;
	char msg[BUFSIZE];
}text;

void* rec(void*);
void* send(void*);

void main()
{
	int running = 1;//loop handling variable
	int msgID;//message ID
	int error;//checking of any error during creation of threads

	pthread_t sendThread, recThread;
	/* 
		the variable to handle the fetching of messages from queue
		Here, msgRecieve is 0 which means first message from queue will be fetched every time
	*/
	//long int msgReceive = 0;
	
	
	//struct my_msg_st text;

	msgID = msgget((key_t)1234,0666| IPC_CREAT);//creation of msg queue
	if(msgID == -1)
	{
		fprintf(stderr, "msg failed with error!!");
	}
	
	error = pthread_create(&sendThread, NULL, &send, &msgID);
	if(error == -1)
	{
		fprintf(stderr, "error in creating sendThread!!");		
		exit(EXIT_FAILURE);
	}

	error = pthread_create(&recThread, NULL, &rec, &msgID);
	if(error == -1)
	{
		fprintf(stderr, "error in creating receiveThread!!");		
		exit(EXIT_FAILURE);
	}


	if(pthread_mutex_init(&mutex, NULL) != 0)
	{
		fprintf(stderr, "error in initiazing mutex!!");		
		exit(EXIT_FAILURE);

	}

	/*while(running)
	{
		//receiving msg
		if(msgrcv(msgID, (void*)&text, BUFSIZE,1,0)==-1)
		{
			fprintf(stderr, "error in receiving msg!!");		
			exit(EXIT_FAILURE);
		}


		//comparison whether received msg is "end" or not
		if(!strncmp(text.msg, "end", 3))
		{	
			running=0;
		}
		else
		{
			printf("Received:%s\n",text.msg);
		}
	}

	//deletion of msg queue
	if(msgctl(msgID, IPC_RMID, 0)==-1)
	{
			fprintf(stderr, "error in msgctl msg!!");		
		exit(EXIT_FAILURE);
	}*/
	exit(EXIT_SUCCESS);	
}

void* send(void* arg)
{
	pthread_mutex_lock(&mutex);
	int msgID = *((int*) arg);
	int running=1;
	char buffer[BUFSIZE];

	while(running)
	{
		printf("Enter Client Index(starting from 1):");
		scanf("%ld",&text.msgType);
		if(text.msgType > TOTAL_CLIENTS)
		{
			printf("Please enter valid Client ID (<3):");
			continue;
		}

		//cleaning std input buffer
		while((getchar())!='\n');

		printf("Enter Message:");
		fgets(buffer, BUFSIZE, stdin);

		strcpy(text.msg, buffer);

		//msg sending
		if(msgsnd(msgID, (void*)&text, BUFSIZE,0)==-1)
		{
			fprintf(stderr, "error in sending msg!!");		
			exit(EXIT_FAILURE);
		}
		
		//comparison of msg whether it is "end" or not
		if(!strncmp(buffer,"end",3))
		{	
			running=0;
		}
	}
	pthread_mutex_unlock(&mutex);
}

void* rec(void* arg)
{
	int msgID = *((int*) arg);

	int running=1;

	if(msgrcv(msgID, (void*)&text, BUFSIZE,0,0)==-1)
		{
			fprintf(stderr, "error in receiving msg!!");		
			exit(EXIT_FAILURE);
		}


		//comparison whether received msg is "end" or not
		if(!strncmp(text.msg, "end", 3))
		{	
			running=0;
		}
		else
		{
			printf("Client:%s\n",text.msg);
		}
	

	//deletion of msg queue
	if(msgctl(msgID, IPC_RMID, 0)==-1)
	{
		fprintf(stderr, "error in msgctl msg!!");		
		exit(EXIT_FAILURE);
	}
}