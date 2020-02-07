#include<stdio.h>
#include<stdlib.h>
#include"SQHeader.h"
//using namespace std;

void Push(int*, int);
void Pop(int*);
void View(int *);

int main(){
	//int iSize;
	//int iHead=-1;
	
	printf("Enter Size of the Stack:");
	scanf("%d",&iSize);
	int *ptrArray = (int*)calloc(iSize, sizeof(int));
	//int arr[in];
	
	int iChoice,iElement;
	
	while(1){
	printf("\n1.Push\n2.Pop\n3.View\n4.Exit\n");
	scanf("%d",&iChoice);
	printf("\n");

	switch(iChoice){
		case 1:
			
			if(iHead == iSize-1){
				printf("Stack Overflow!!!!\n");
				break;
			}

			printf("Enter element to insert:");
			scanf("%d",&iElement);
			
			Push(ptrArray,iElement);
			break;

		case 2:
			Pop(ptrArray);
			break;

		case 3:
			//int index;
			View(ptrArray);
			break;
		case 4:
			exit(0);

		default:
			printf("Please make valid choice!!!\n");
	}
}

}


void Push(int* ptrArray, int iElement){
	
	*(ptrArray+(++iHead))=iElement;

}
					
void Pop(int* ptrArray){
	
	if(iHead==-1)
		printf("Stack Underflow!!!!\n");
	
	else if(iHead==0){
		iHead=-1;
	}			
	
	else 
		iHead--;
}

void View(int* ptrArray){
	for(int index=iSize-1;index>=0;index--){
				
		if( index<=iHead)
			printf("%d\n",*(ptrArray+index));
		
		else
			printf("_\n");
	}
}