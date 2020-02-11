#include<stdio.h>					
#include<stdlib.h>
#include<string.h>

/*****************************************************************************
	* Content entered by the user will be inserted in the file named by user.
	*
	* @param FILE* (File Pointer)
	*
	* @return void
******************************************************************************/
void InsertContent(FILE*);


/*******************************************************************
	* The list of files in the folder will be shown to user
	*
	* User will enter the name of the desired file with extension
	*
	* @param FILE* (File Pointer)
	*
	* return void
********************************************************************/
void ShowContent(FILE*);

/*************************************************************
	* This method will accept two file pointers as arguments
	*
	* First argument will be Source File Pointer
	*
	* Second argument will be Destination File Pointer
	*
	* @param FILE*, FILE*
	*
	* @return void
**************************************************************/
void CopyContent(FILE*, FILE*);

void main(){
	
	char *strFile1Name = (char *)malloc(sizeof(char)*100);
	char *strFile2Name = (char *)malloc(sizeof(char)*100);
	char *strFileName = (char *)malloc(sizeof(char)*100);
	

	int ichoice;
	
	while(1){
		printf("------------------------------------------------\n");
		printf("\t|1.Insert\t\t|\n\t|2.Show Content\t\t|\n\t|3.Copy to another file |\n\t|4.Exit\t\t\t|\n");
		printf("------------------------------------------------\n");
		printf("Enter your Choice:");
		scanf("%d",&ichoice);
		
		switch(ichoice){
	
			case 1:

				printf("Enter File1 Name:");
				scanf("%s",strFile1Name);
	
				strcat(strFile1Name,".txt");
	
				FILE *fp1 = fopen(strFile1Name,"w");
	
				if(NULL==fp1){
					printf("File Not Found!!!!\n");
					break;
				}

				InsertContent(fp1);

				fclose(fp1);

			break;
	
//	}
			case 2:
				
				
				system("ls");
				printf("Enter Name of the File you want to open:");
				scanf("%s",strFileName);

				//strcat(strFileName,".txt");
				
				FILE* fp = fopen(strFileName,"r");
				
				if(NULL == fp){
					printf("File Not Found!!!!\n");
					break;
				}

				ShowContent(fp);
				fclose(fp);
						
				
			break;

			case 3:
				fp1 = fopen(strFile1Name,"r");

				if(NULL == fp1){
					printf("File Not Found!!!!\n");
					break;
				}

				printf("Enter File2 Name:");
				scanf("%s",strFile2Name);
				
				strcat(strFile2Name,".txt");
				FILE *fp2 = fopen(strFile2Name,"w");

				if(NULL == fp2){
					printf("File Not Found!!!!\n");
					exit(0);
				}
				
				/*Copying Content in Second File*/
				CopyContent(fp1,fp2);
				fclose(fp1);
				fclose(fp2);
				
				break;

			case 4:
				printf("++++++++++++++++ Thank You!!! +++++++++++++++++++\n\n");
				exit(0);

			default: 
				printf("Plaese make valid Choice!!!!\n");
		
			break;
		}
	}
}
	
void InsertContent(FILE *fp){
	printf("------------------Enter Content--------------------\n");
	while(1){
					
		int ich=getc(stdin);
		
		if(ich != EOF)
			fputc(ich,fp);
			
		else
			break;
	}
			
			
}

void ShowContent(FILE* fp){
				
	int icount=0;  // Line Counter
	int ich,itemp;
				
	do{
		ich = fgetc(fp);	
		printf("%c",ich);		
					
		if((ich == '\n' && ich!=EOF) && itemp!='\0')
			icount++;
			
		itemp=ich;

	}while(ich!=EOF);

				
	printf("\n---------------------\n");
	printf("|  Total Lines:%d  |",icount);
	printf("\n---------------------\n\n");
	
}

void CopyContent(FILE* fp1, FILE* fp2){
	while(1){
		
		char ich= fgetc(fp1);
		
		if(ich!=EOF)
			fputc(ich,fp2);
		else
			break;
	}
	printf("///////////////// Copied!!!! ////////////////////\n\n");
}