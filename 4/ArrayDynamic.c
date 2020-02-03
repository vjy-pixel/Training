#include<stdio.h>
#include<stdlib.h>

void InsertElement(int*);
void DeleteElement(int*);
void ShowArray(int*);

int iSize;

int main(){
	
	printf("Enter size of array:");
	scanf("%d",&iSize);

	int *ptrArray =(int *)calloc(iSize,sizeof(int));
	
	printf("Enter elements of array:\n");
	for(int index=0; index<iSize; index++)
		scanf("%d", ptrArray+index);

	 
	
	while(1)
	{
		printf("\n");
		printf("1.Insert\n2.Delete\n3.Show\n4.Exit\n");
		printf("\n");
		printf("Choose:");
		int iChoose,iPos;
		scanf("%d",&iChoose);
		printf("\n");
		
		switch(iChoose){

			/*Insertion*/
			case 1:	
				InsertElement(ptrArray);
				break;	
	
			/*Deletion*/
			case 2:	
				DeleteElement(ptrArray);
				break;
	
			/*Show the Array*/
			case 3: 
				ShowArray(ptrArray);
				break;

			/*Exit*/
			case 4:
				printf("Thank You!!!! :)\n");
				free(ptrArray);
				exit(0);

			default:
				printf("Please make valid Choice!!!\n");
		}
	}
}


void InsertElement(int* ptrArray){
	
	ptrArray = realloc(ptrArray,(iSize+1)*sizeof(int));
	int iPos;

	printf("Enter element you want to insert:");
	int iNew;
	scanf("%d",&iNew);
				
	printf("\nWhere to add?\n1.Start\n2.Specific Location\n3.End\n");
	int iChoice;
	scanf("%d",&iChoice);
				
	/*Where to insert?*/
	switch(iChoice){
		/*At Start */
		case 1:
			
			for(int index =iSize++; index>0; index--)
				*(ptrArray+index) = *(ptrArray+index-1);
				*(ptrArray+0)=iNew;
				break;

		/*Specific Position */
		case 2:
						
			printf("Enter the position:");
						//int iPos;
			scanf("%d",&iPos);

			if(iPos<0 || iPos>iSize){
				printf("Entered Position is out of Range!!!!\n");
				break;
			}
		
			for(int index =iSize++; index>iPos-1; index--)
				*(ptrArray+index) = *(ptrArray+index-1);
				*(ptrArray+iPos-1) = iNew;
				break;
					
		/*At Last*/
		case 3:
			*(ptrArray+(iSize++))=iNew;
			break;
	
		default:
			printf("Please make valid choice!!!\n");
	}
}

void DeleteElement(int *ptrArray){
	
	int iPos,iChoice;

	if(iSize==0)
		printf("Nothing to Delete!!!! :(\n");
				
	else{
		printf("From Where?\n1.Start\n2.Specific Location\n3.End\n");
		scanf("%d",&iChoice);

		/*Delete from Where?*/
		switch(iChoice){
						
			/*From Start */
			case 1:
							
				for(int index =0; index < iSize-1; index++)
					*(ptrArray+index) = *(ptrArray+index+1);
					iSize--;
					break;

			/*From Specific Position*/
			case 2:
				printf("Enter the position:");
				scanf("%d",&iPos);
				
				if(iPos<0 || iPos>iSize){
					printf("Entered Position is out of Range!!!!\n");
					break;
				}		
				
				for(int index = iPos-1; index<iSize-1; index++)
					*(ptrArray+index) = *(ptrArray+index+1);
					
				iSize--;
				
				break;
	
			/*From End*/
			case 3:
				iSize--;
				break;
	
			default:
				printf("Please make valid choice!!!\n");
		}
	}
}



void ShowArray(int *ptrArray){
	if(iSize==0)
		printf("Nothing to Show!!! :(\n");
				
	else{
		
		printf("Final Array:");
					
		for(int index=0; index < iSize; index++)
			printf("%d ",*(ptrArray+index));
			printf("\n");
			printf("Array-Length:%d\n",iSize);
	}	
}