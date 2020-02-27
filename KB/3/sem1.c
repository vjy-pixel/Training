#include<stdio.h>
#include<pthread.h>
#include<signal.h>
#include<semaphore.h>
#include<unistd.h>

sem_t sem;

void* odd(void*);

//void main1();
//void* even(void*);

void firstSem(int iX){
	
	sem_init(&sem, 1, 1);
	//printf("%d\n",sem);

	pthread_t t1;

	pthread_create(&t1, NULL, odd, &iX);
	
	pthread_join(t1,NULL);
	//pthread_join(t2,NULL);
	sem_destroy(&sem);
	//pthread_exit(NULL);
}

void* odd(void* iX){
	int iRange = *(int*)iX;

	sem_wait(&sem);
	
	for(int i=1;i<= iRange; i++){
		if(i%2!=0){
			printf("odd(thread-1):%d\n",i);
			sleep(1);
			
		}

		else{
			sem_post(&sem);
		}
	}
}


