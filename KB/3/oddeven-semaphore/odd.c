#include<pthread.h>
#include<semaphore.h>
#include<stdatomic.h>
#include<stdio.h>
#include<unistd.h>
#include "odd.h"

extern atomic_uint iShared;
sem_t sem1;

void thread1(){
	pthread_t t1;
	pthread_create(&t1, NULL, odd, NULL);
	pthread_join(t1,NULL);
}

void* odd(void* arg){

	sem_init(&sem1,1,1);

	sem_wait(&sem1);
	
	if(iShared%2!=0){
		printf("(Thread-1)odd:%u\n",iShared++);
		sleep(1);
	}

	sem_post(&sem1);
	pthread_exit(NULL);
}