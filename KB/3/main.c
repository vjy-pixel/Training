//#include "sem1.c"
//#include "sem2.c"
#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<semaphore.h>
#include<unistd.h>

void sigIntHandler(int);
void firstSem(int);
void secondSem(int);

void main(){
	struct sigaction signalAction;
	signalAction.sa_handler = sigIntHandler;
    sigemptyset(&signalAction.sa_mask);
    signalAction.sa_flags = 0;      // SA_RESTART;
    sigaction(SIGINT, &signalAction, NULL);

	//signal(SIGINT,sigHandler);
	int iX;
	printf("Enter Number:");
	scanf("%d",&iX);

	firstSem(iX);
	secondSem(iX);
}

/*void sigHandler(int iSigNum){
	//flag1=1;
	printf("\nCaught Signal %d, Terminating Thread!!!!\n",iSigNum);
	pthread_exit(NULL);
}*/

void sigIntHandler(int signum)
{
    fprintf(stderr, "Ctrl-C (%d)\n", signum);
}
