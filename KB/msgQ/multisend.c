#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<errno.h>
#include<string.h>	
#include<pthread.h>


#define BUFSIZE 1024

//structure of msg queue
struct my_msg_st
{
	long int msgType;
	char msg[BUFSIZE];
};

void main()
{
	int running = 1;//loop handling variable
	int msgID;//message ID
	
	char buffer[BUFSIZE];//Buffer for taking input of msg
	
	struct my_msg_st text;//instance of structure of msg queue

	msgID = msgget((key_t)1234,0666| IPC_CREAT);//creation of msg queue
	if(msgID == -1)
	{
		fprintf(stderr, "msg failed with error!!");
	}

	while(running)
	{
		printf("Enter Message:");
		fgets(buffer, BUFSIZE, stdin);

		text.msgType=1;

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
	exit(EXIT_SUCCESS);
}