#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>
#include<stdatomic.h>
#include "even.c"
#include "odd.c"


atomic_uint iShared =1;

void thread1();
void thread2();
void sigIntHandler(int);

void main(){
	
	struct sigaction signalAction;
	signalAction.sa_handler = sigIntHandler;
    sigemptyset(&signalAction.sa_mask);
    signalAction.sa_flags = 0;      
    sigaction(SIGINT, &signalAction, NULL);

	int iX;
	printf("Enter Number:");
	scanf("%d",&iX);

	while(iShared <= iX){
		thread1();
		thread2();
	}
}

void sigIntHandler(int signum)
{
    fprintf(stderr, "Ctrl-C (%d)\n", signum);
    pthread_exit(NULL);
}