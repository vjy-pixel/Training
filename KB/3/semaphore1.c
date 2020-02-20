#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

void* odd(void*);
static void sigHandler(int);

sem_t sem;

unsigned int iShared1=1;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int flag1=0;

void main(){
	int iX;
	printf("Enter Number:");
	scanf("%d",&iX);

	int res = sem_init(&sem, 0, 0);
	if(res!=0){
		perror("Semaphore initialization failed!!!\n");
		exit(EXIT_FAILURE);
	}

	signal(SIGINT, sigHandler);
	pthread_t t1;
	
	pthread_create(&t1, NULL, odd, &iX);
	
	pthread_join(t1,NULL);
	sem_destroy(&sem);
}


void* odd(void* iX){
	int iRange = *(int*)iX;

	sem_wait(&sem);

	while(iShared1 <= iRange && flag1 ==0 ){
			if(iShared1%2!=0){
				printf("odd(thread-1):%d\n",iShared1);
				iShared1++;
				sleep(1);

			}
			else{
				//pthread_mutex_unlock(&mutex);
				sem_post(&sem);
			}

	}
	
}

static void sigHandler(int iSigNum){
	flag1=1;
	printf("\nCaught Signal %d, Terminating Thread!!!!\n",iSigNum);
	//pthread_exit((void*)1);
}