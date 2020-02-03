#include<stdio.h>
#include<time.h>
#define MAX_ELEMENTS 10
void main()
{
	int iArray[MAX_ELEMENTS];
	
	printf("Enter elements if array(10 elements):\n");
	
	for(int index=0; index< MAX_ELEMENTS; index++)
		scanf("%d", &iArray[index]);
	
	int iDesired;
	
	printf("Enter Desired Element:");
	scanf("%d",&iDesired);
	
	int iFlag=0;
	//Linear Search
	clock_t linSTime = clock();
	
	for(int index=0; index<MAX_ELEMENTS; index++)
		if(iDesired == iArray[index]){
			iFlag=1;
			printf("%d found at %d\n",iArray[index],index+1);
			break;
		}
	
	if(iFlag==0)
		printf("Element not found\n");
	
	linSTime = clock()-linSTime;
	printf("\nLinear Search Time:%f\n", (float)linSTime/CLOCKS_PER_SEC);
		
	//Binary Search
	linSTime = clock();
	
	for(int index=0; index< MAX_ELEMENTS; index++)
		
		for(int cnt=index+1;cnt< MAX_ELEMENTS;cnt++){
			
			if(iArray[index]>iArray[cnt]){
				
				iArray[index]=iArray[index]+iArray[cnt];
				iArray[cnt]=iArray[index]-iArray[cnt];
				iArray[index]=iArray[index]-iArray[cnt];
			
			}
		}

	printf("Sorted Array:");
	
	for(int index=0; index<MAX_ELEMENTS; index++)
		printf("%d ",iArray[index]);
	
	printf("\n");	
	linSTime = clock()-linSTime;
	printf("Sorting Time:%f\n",(float)linSTime/CLOCKS_PER_SEC);	
	
	int iLower=0,iUpper=9;
	int iMedian;
	
	clock_t binSTime=clock();
	while(1)
	{
		iMedian=((iLower+iUpper)/2);
		
		if(iDesired==iArray[iMedian]){
			iFlag=1;
			printf("\n%d found at %d\n",iDesired,iMedian+1);
			break;
		}

		else if(iDesired > iArray[iMedian]){
			iLower = iMedian+1;
			continue;
		}

		else if(iDesired<iArray[iMedian]){ 
			iUpper=iMedian-1;
			continue;
		}
		
	}
	if(iFlag ==0)
		printf("Element not found\n");
	
	binSTime = clock() - binSTime;
	printf("\nBinary Search Time:%f\n",(float)binSTime/CLOCKS_PER_SEC);
	//getch();
}
		