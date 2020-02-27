#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void* odd(void*);
void sigHandler(int);

unsigned int iShared=1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int flag=0;

void main(){
	int iX;
	printf("Enter Number:");
	scanf("%d",&iX);

	signal(SIGINT, sigHandler);
	pthread_t t1;
	
	pthread_create(&t1, NULL, odd, &iX);
	
	pthread_join(t1,NULL);
}


void* odd(void* iX){
	int iRange = *(int*)iX;

	pthread_mutex_lock(&mutex);

	while(iShared <= iRange && flag ==0 ){
			if(iShared%2!=0){
				printf("odd(thread-1):%d\n",iShared);
				iShared++;
				sleep(1);

			}
			else{
				pthread_mutex_unlock(&mutex);
			}

	}
}

void sigHandler(int iSigNum){
	flag=1;
	printf("\nCaught Signal %d, Terminating Thread!!!!\n",iSigNum);
	//pthread_exit((void*)1);
}