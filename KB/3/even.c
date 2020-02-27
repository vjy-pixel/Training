#include<pthread.h>
#include<semaphore.h>
#include<stdatomic.h>
#include<stdio.h>
#include<unistd.h>
#include "even.h"

//void* even();
extern atomic_uint iShared;
sem_t sem2;

void thread2(){
	pthread_t t2;
	pthread_create(&t2, NULL, even, NULL);
	pthread_join(t2,NULL);
}

void* even(void* arg){

	sem_init(&sem2,1,1);

	sem_wait(&sem2);
	
	if(iShared%2 == 0){
		printf("(Thread-2)even:%u\n",iShared++);
		sleep(1);
	}
	
	sem_post(&sem2);
	pthread_exit(NULL);
}