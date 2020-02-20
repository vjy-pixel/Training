#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

void* even(void*);
static void sigHandler(int);

unsigned int iShared2=1;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int flag2=0;

sem_t sem1;

void main1(){
	int iX;
	printf("Enter Number:");
	scanf("%d",&iX);

	int res = sem_init(&sem1, 0, 1);
	if(res!=0){
		perror("Semaphore initialization failed!!!\n");
		exit(EXIT_FAILURE);
	}

	signal(SIGINT, sigHandler);
	pthread_t t2;
	
	pthread_create(&t2, NULL, even, &iX);
	
	pthread_join(t2,NULL);
	sem_destroy(&sem1);
}


void* even(void* iX){
	int iRange = *(int*)iX;

	sem_wait(&sem1);
	//pthread_mutex_lock(&mutex);

	while(iShared2 <= iRange && flag2 ==0 ){
			if(iShared2%2==0){
				printf("even(thread-2):%d\n",iShared2);
				iShared2++;
				sleep(1);

			}
			else{
				//pthread_mutex_unlock(&mutex);
				sem_post(&sem1);
			}

	}
	
}

static void sigHandler(int iSigNum){
	flag2=1;
	printf("\nCaught Signal %d, Terminating Thread!!!!\n",iSigNum);
	//pthread_exit((void*)1);
}