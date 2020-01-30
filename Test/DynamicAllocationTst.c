#include<stdio.h>
#include<stdlib.h>
//using namespace std;

int main(){
	int iSize;
	printf("Enter Size of an Array:");
	scanf("%d",&iSize);
//	int iArray[iSize];
	int *ptrArray = (int*)calloc(iSize,sizeof(int));	

	printf("Enter Elements:\n");
	for(int index=0; index<iSize; index++){
			scanf("%d",(ptrArray+index));
	}

	printf("Array:");
	for(int index=0; index<iSize; index++){
			printf("%d ",*(ptrArray+index));
	}
	
	printf("\nInsert Element:");
	int x;
	int *ptrExtra = ptrArray;
	scanf("%d",&x);
	ptrExtra=(int*)realloc(ptrExtra,(iSize+1)*sizeof(int));
	//(ptrArray+iSize)=(int*)malloc(sizeof(int));
	iSize++;
	*(ptrArray+iSize-1)=x;

	printf("Array:");
	for(int index=0; index<iSize; index++){
			printf("%d ",*(ptrExtra+index));
	}
	printf("\n");
	for(int index=0; index<iSize; index++){
			printf("%d ",*(ptrArray+index));
	}
	printf("\nSize:%ld,%ld",sizeof(ptrExtra),sizeof(int));

		free(ptrExtra);
	printf("\n%ld\n",sizeof(*ptrExtra) );
		//fflush(stdin);
	iSize--;
	for(int index=0; index<iSize; index++){
			printf("%d ",*(ptrArray+index));
	}
	printf("\n");
	//free(ptrArray);
}