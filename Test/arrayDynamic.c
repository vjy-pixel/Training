#include<stdio.h>
#include<stdlib.h>
//using namespace std;

int main(){
	int iSize;
	printf("Enter size of array:");
	scanf("%d",&iSize);

	int *ptrArray =(int *)calloc(iSize,sizeof(int));
	
	printf("Enter elements of array:\n");
	for(int index\=0; index<iSize; index++)
		scanf("%d", ptrArray+index);

	 
	int iChoose;
	
	while(1)
	{
		printf("----------------------------\n");
		printf("1.Insert\n2.Delete\n3.Show\n4.Exit\n");
		printf("----------------------------\n");
		printf("Choose:");
		scanf("%d",&iChoose);
		
		switch(iChoose){
		//----------------------------------------------------- For Insertion-----------------------------------------------------------
			case 1:	
				
				ptrArray = realloc(ptrArray,sizeof(int));

				printf("Enter element you want to add:");
				int iNew;
				scanf("%d",&iNew);
				char chChoice;
	
				printf("\nWhere to add?\n1.Start\n2.Specific Location\n3.End\n");
	
				scanf("%c",&chChoice);
				switch(chChoice){
					case '1':
						
						for(int index =iSize++; index>0; index--)
							*(ptrArray+index) = *(ptrArray+index-1);
						
						*(ptrArray+0)=iNew;
						
						break;

					case '2':
						int iPos;
						printf("Enter the position:");
						scanf("%d",&iPos);
		
						for(int index =iSize++; index>iPos-1; index--)
							*(ptrArray+index) = *(ptrArray+index-1);
						
						*(ptrArray+iPos-1) = iNew;
						
						break;
	
					case '3':
						
						*(ptrArray+(iSize++))=x=iNew;
						
						break;
	
					default:
						
						printf("Please make valid choice!!!\n");
				}
			
				break;	
	

			//------------------------------------------------------- For Deletion----------------------------------------------------------
			case 2:	
				if(iSize==0)
					printf("Nothing to Delete!!!! :(");
				else{
					printf("From Where?\n1.Start\n2.Specific Location\n3.End\n");
	
					scanf("%c",&chChoice);

					switch(chChoice){
						case '1':
							for(int index=
								0; index < iSize-1; index++)
								arr[i]=arr[i+1];
							n--;
							break;

						case '2':
							int pos;
							cout << "Enter the position:";
							cin >> pos;
		
							for(int i=pos-1;i<n-1;i++)
								arr[i]=arr[i+1];
							n--;
							break;
	
						case '3':
							n--;
							break;
	
						default:
							cout << "Please make valid choice!!!";
					}
				}
	
			break;
	
	//----------------------------------------------------------------------------------
			case 3: 
				if(n==0)
					cout << "Nothing to Show!!! :(" << endl;
				else{
					cout << "Final Array:";
					for(int i=0;i<n;i++)
						cout << arr[i] << " ";
					cout << endl;
			
					cout << "Array-Length:" << n << endl;
				}	
				break;

			case 4:
				cout << "Thank You!!!! :)";
				exit(0);

			default:
				cout << "Please make valid Choice!!!";
		}
	}
}