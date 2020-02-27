#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<curses.h>

/******************************************************************************
   * A method which prints sequence from 1 to the number passed in argument.
   * 
   * The argument will be type-casted to the (int*) as it needed to be 
   * 
   * compared with loop-variable  of integer type.
   * 
   * @param void*
   *
   * @return void*
*******************************************************************************/
void*  print_seq(void*);

/***********************************************************************************
   * A method that will be executed whenever interrupt will occur using Ctrl-C
   * 
   * to terminate the thread
   *
   * @param int
   * 
   * @return void
************************************************************************************/
void sigHandler(int);

void main(){
	
	int iThreadCheck; // will check thread successfully created or not
	
        int iX; // User Input
	while(1){

		printf("Enter the value till u wanna print(only >1):");
		scanf("%d",&iX);
		
		if(iX < 1){
			printf("\n---------Please enter a number greater than 1 (>1)!!!-------\n\n");
			continue;
		}
		else break;
	}
	
	pthread_t tId;// Thread ID

	iThreadCheck = pthread_create(&tId, NULL, print_seq,(void*) &iX);

	if(iThreadCheck)
		printf("\nError occured in creation of thread!!!\n");

	pthread_exit((void*)tId);
}


void*  print_seq(void* iX){
	
	/* iX is type casted to int* so that it can be compared with integer loop variable i. */
	struct sigaction sa;
	sa.sa_handler = sigHandler;
	int i=0,ch;
	int* iRange = (int*)iX;
	sigaction(SIGTERM, &sa, NULL);
	printf("Your Sequence:\n");
	for(i=1; i<=*iRange; i++){
		printf("%d ",i);
	
		sleep(1);
	}
		
	printf("\n");
}

void sigHandler(int iSigNum){
	printf("\nCaught Signal %d, Terminating Thread!!!!\n",iSigNum);
	
}
