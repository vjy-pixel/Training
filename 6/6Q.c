#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int iSize;
	int iFront=0,iRear=-1;
	
	printf("Enter Number of Elements:");
	scanf("%d",&iSize);
	
	int *ptrArray = (int*) calloc(iSize, sizeof(int));
	int iChoice,iElement;
	
	while(1){
	printf("\n\n1.Enqueue\n2.Dequeue\n3.View\n4.Exit\n");
	
	scanf("%d",&iChoice);
	printf("\n");
	
	switch(iChoice){
		
		case 1:
			//int iElement;
			if(iRear<iSize-1){
				printf("Enter element to insert:");
				scanf("%d",&iElement);
				*(ptrArray+ (++iRear))= iElement;
			}
			else
				printf("Queue is Full\n");
			break;

		case 2:
			if(iRear==-1)
				printf("Queue is Empty\n");
			else if(iFront==iRear){
				iRear=-1;
				iFront=0;
			}			
			else 
				iFront++;
			
			break;

		case 3:
			
			for(int index=0;index<iSize;index++){
				
				if(index>=iFront && index<=iRear)
					printf("%d ",*(ptrArray+index));
				
				else
					printf("_ ");
			}
			
			break;
		
		case 4:
			exit(0);

		default:
			printf("Please make valid choice!!!\n");
	}
}
}


					
