#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void LinearSearch(int *,int ,int);
void BinarySearch(int *,int ,int);

void main()
{
	//int ptrArray[MAX_ELEMENTS];
	int iSize;
	printf("Enter Size:");
	scanf("%d",&iSize);
	int *ptrArray = (int *)calloc(iSize,sizeof(int));
	//int ptrArray[iSize];
	printf("Enter elements if array:\n");
	
	for(int index=0; index< iSize; index++)
		scanf("%d", &ptrArray[index]);
	
	int iDesired;
	
	printf("\nEnter Desired Element:");
	scanf("%d",&iDesired);
	
	LinearSearch(ptrArray, iSize, iDesired);
		
	//Binary Search
	BinarySearch(ptrArray, iSize, iDesired);
	//getch();
}
		

void LinearSearch(int* ptrArray, int iSize, int iDesired){
	int iFlag=0;
	//Linear Search
	clock_t linSTime = clock();
	
	for(int index=0; index<iSize; index++)
		if(iDesired == ptrArray[index]){
			iFlag=1;
			printf("\n%d found at %d",ptrArray[index],index+1);
			break;
		}
	
	if(iFlag==0)
		printf("Element not found\n");
	
	linSTime = clock()-linSTime;
	printf("\nLinear Search Time:%f\n\n", (float)linSTime/CLOCKS_PER_SEC);
}


void BinarySearch(int* ptrArray,int iSize, int iDesired){
	clock_t linSTime = clock();
	
	for(int index=0; index< iSize; index++)
		
		for(int cnt=index+1;cnt< iSize;cnt++){
			
			if(ptrArray[index]>ptrArray[cnt]){
				
				ptrArray[index]=ptrArray[index]+ptrArray[cnt];
				ptrArray[cnt]=ptrArray[index]-ptrArray[cnt];
				ptrArray[index]=ptrArray[index]-ptrArray[cnt];
			
			}
		}

	printf("Sorted Array:");
	
	for(int index=0; index<iSize; index++)
		printf("%d ",ptrArray[index]);
	
	printf("\n");	
	linSTime = clock()-linSTime;
	printf("Sorting Time:%f\n",(float)linSTime/CLOCKS_PER_SEC);	
	
	int iLower=0,iUpper=iSize-1;
	int iMid=0,iFlag=0;
	
	clock_t binSTime=clock();
	while(1)
	{
		int iTemp=iMid;
		iMid=((iLower+iUpper)/2);
		//printf("Med:%d,%d\n",iTemp,iMid);
		if(iDesired==ptrArray[iMid]){
			iFlag=1;
			printf("\n%d found at %d\n",iDesired,iMid+1);
			break;
		}

		else if(iTemp==iMid){
			iFlag=1;
			printf("Element Not found!!!!\n");
			break;
		}

		else if(iDesired > ptrArray[iMid]){
			iLower = iMid+1;
			continue;
		}

		else if(iDesired < ptrArray[iMid]){ 
			iUpper=iMid-1;
			continue;
		}

		  
		
	}
	if(iFlag ==0)
		printf("Element not found\n");
	
	binSTime = clock() - binSTime;
	printf("Binary Search Time:%f\n",(float)binSTime/CLOCKS_PER_SEC);
}