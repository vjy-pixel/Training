#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<semaphore.h>
#include<unistd.h>

//pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 
sem_t sem;

void* even(void*);

void secondSem(int iX){
	
	sem_init(&sem, 1, 1);
	//printf("%d\n",sem);

	pthread_t t2;

	pthread_create(&t2, NULL, even, &iX);
	//sleep(2);
	sem_wait(&sem);
	
	//main1();

	//pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&sem);
	//pthread_exit(NULL);
}

void* even(void* iX){
	int iRange = *(int*)iX;

	sem_post(&sem);
	//printf("%d",sem);
	for(int i=1;i<= iRange; i++){
		if(i%2==0){
			printf("even(thread-2):%d\n",i);
			sleep(1);
		}

		else{
			sem_post(&sem);
			//printf("%d",sem);
		}
	}
}

