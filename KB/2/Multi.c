#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

pthread_mutex_t lock; // Mutex variable
unsigned int iShared=1; // loop variable

/************************************************************************************
  * A method that will allow to print if global variable iShared is odd
  * 
  * Here, at the beginning only with the use of mutex we will have lock for thread-1
  *
  * if value of iShared is even then mutex will be unlocked.
  * 
  * @param void*
  * 
  * @return void*
*************************************************************************************/
void* odd(void*);

/************************************************************************************
  * A method that will allow to print if global variable iShared is even
  * 
  * Here, at the beginning only with the use of mutex we will have lock for thread-2
  *
  * if value of iShared is odd then mutex will be unlocked.
  * 
  * @param void*
  * 
  * @return void*
*************************************************************************************/
void* even(void*);

void main(){
	int iIn;
	
	while(1){
		printf("Enter Number:");
		int iInCheck = scanf("%d",&iIn);

		if(iIn < 1){
			printf("Please Enter the number greater than 1 (>1)!!\n");
			continue;
		}
		else if(isalpha(iIn)){

			printf("Please enter numerical value!!!\n");
			continue;
		}
		else break;
	}

	printf("\n");
	
	pthread_t t1,t2;
	int iCheck; //will check whether thread created successfully or not

	iCheck = pthread_create(&t1, NULL, odd, (void*) &iIn);
	if(iCheck){
		printf("Unable to create Thread-1!!!!!\n");
		exit(1);
	}

	iCheck = pthread_create(&t2, NULL, even, (void*) &iIn);
	if(iCheck){
		printf("Unable to create Thread-2!!!!\n");
		exit(1);
	}
	sleep(1);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

void* odd(void* iIn){
	int* iRange = (int*)iIn;
	pthread_mutex_lock(&lock);

	while(iShared <= *iRange){
		//pthread_mutex_lock(&lock);
		if(iShared % 2 != 0){
			printf("odd(thread-1):%d\n",iShared);
			iShared++;
		}
		else
			pthread_mutex_unlock(&lock);
	}
	/* This if condition is to tackle in the case when user i/p is 1 */
	if(*iRange == 1)
		pthread_mutex_unlock(&lock);
} 

void* even(void *iIn){
	int* iRange = (int*)iIn;
	pthread_mutex_lock(&lock);

	while(iShared <= *iRange){
		//pthread_mutex_lock(&lock);
		if(iShared%2 == 0){
			printf("even(thread-2):%d\n",iShared);
			iShared++;
		}
		else
			pthread_mutex_unlock(&lock);
		
	}
}

	

	

	
