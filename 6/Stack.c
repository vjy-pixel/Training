#include<stdio.h>
#include<stdlib.h>
//using namespace std;


int main(){
	int iSize;
	int iHead=-1;
	printf("Enter Number of Elements:");
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
		
			if(iHead<iSize-1){
				printf("Enter element to insert:");
				scanf("%d",&iElement);
				*(ptrArray+(++iHead))=iElement;
			}
			else
				printf("Stack Overflow!!!!\n");
			break;

		case 2:
			if(iHead==-1)
				printf("Stack Underflow!!!!\n");
			else if(iHead==0){
				iHead=-1;
				//front=0;
			}			
			else 
				iHead--;
			break;

		case 3:
			//int index;
			for(int index=iSize-1;index>=0;index--){
				//cout << front << "---" << rear << endl;
				if( index<=iHead)
					printf("%d\n",*(ptrArray+index));
				else
					printf("_\n");
			}
			break;
		case 4:
			exit(0);

		default:
			printf("Please make valid choice!!!\n");
	}
}

}


					
