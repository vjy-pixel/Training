#include<stdio.h>
#include<stdlib.h>
#include"SQHeader.h"

int main(){
	
	printf("Enter Size of the Queue:");
	scanf("%d",&iSize);
	
	int *ptrArray = (int*) calloc(iSize, sizeof(int));
	
	/* To Choose the ooperation*/
	int iChoice; 

	/* An element that is to be inserted*/
	int iElement;
	
	while(1){
		
	printf("\n\n1.Enqueue\n2.Dequeue\n3.Forced Dequeue\n4.View\n5.Exit\n");
	printf("Enter your Choice:");
	scanf("%d",&iChoice);
	printf("\n");
	
	switch(iChoice){
		
		case 1:
			
			if((iFront ==0 && iRear==iSize-1) || (iRear==iFront-1)){
				printf("Queue is Full\n");
				break;
			}
			printf("Enter element to insert:");
			scanf("%d",&iElement);
			
			Enqueue(ptrArray, iElement);
			break;

		case 2:
			
			Dequeue(ptrArray);
			break;

		case 3:

			ForcedDequeue(ptrArray);
			break;
		
		case 4:
			
			View(ptrArray);
			break;

		case 5:
			exit(0);

		default:
			printf("Please make valid choice!!!\n");
	}
	printf("Front:%d\nRear:%d\n",iFront,iRear);
}
}


/* Refer "SQHeader.h" */
void Enqueue(int* ptrArray, int iElement){
	
	if(iFront==-1){
		iFront=0;
		*(ptrArray+ (++iRear))= iElement;
	}

	else if((iFront ==0 && iRear==iSize-1) || (iRear==iFront-1))
		printf("Queue is Full\n");

	else if(iRear < iSize-1){
		*(ptrArray+ (++iRear))= iElement;
	}

	else if(iRear == iSize-1 && iFront!=0){
		iRear=-1;
		*(ptrArray+ (++iRear))= iElement;	
	}
}				

/* Refer "SQHeader.h" */
void Dequeue(int* ptrArray){
	
	/* Will temporarily store the value of the foremost element */
	int iTemp;
	iTemp= *(ptrArray+iFront);
		
		for(int index = 0; index< iRear; index++){
			*(ptrArray+iFront+index) = *(ptrArray+iFront+index+1);
		}
		*(ptrArray+iRear) = iTemp;
}


/* Refer "SQHeader.h" */
void ForcedDequeue(int* ptrArray){
	
	if(iRear == -1)
		printf("Queue is Empty\n");
	
	else if(iFront == iRear){
		iRear=-1;
		iFront=-1;
	}
	
	else if(iFront == iSize-1)
		iFront=0;			
	
	else{
		iFront++; 
	}
		
}

/* Refer "SQHeader.h" */
void View(int* ptrArray){
	
	if(iFront == -1){
		printf("Nothing to show!!!\n");
	}	

	else if(iRear>=iFront){
		for(int index=iFront; index<=iRear; index++){
			printf("%d ",*(ptrArray+index));
		}	
	}
	else if(iRear<iFront){
		for(int index=0; index<=iRear; index++){
			printf("%d ",*(ptrArray+index));
		}

		for(int index=iFront; index<iSize; index++){
			printf("%d ",*(ptrArray+index));
		}
	}

	else{
		for(int index=iFront; index<iSize; index++){
			printf("%d ",*(ptrArray+index));
		}

		for(int index=0; index<=iRear; index++){
			printf("%d ",*(ptrArray+index));
		}
	}
}