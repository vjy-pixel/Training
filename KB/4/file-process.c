#include<stdio.h>					
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h> 
#include<unistd.h> 
#define MAX_CHARS 1000

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
	int iPid;
	char *destFileName = (char *)malloc(sizeof(char)*MAX_CHARS);

	if((iPid=fork())< 0){
		perror("fork");
		exit(1);  
	}

	if(iPid == 0){
		printf("New Process Created!!!\n");
		FILE *fp1 = fopen("source.txt","r");

				if(NULL == fp1){
					printf("File Not Found!!!!\n");
					exit(1);
				}

				/*To take file name from user */
				/*(file will be created in the same directory where the program is placed.*/
				printf("Enter Destination File Name:");
				scanf("%s",destFileName);
				
				/*To append .txt extension*/
				strcat(destFileName,".txt");
				FILE *fp2 = fopen(destFileName,"w");

				if(NULL == fp2){
					printf("File Not Found!!!!\n");
					exit(0);
				}

				else
					printf("\n----%s.txt has been created!!----\n",destFileName);
				
				/*Copying Content in Second File*/
				CopyContent(fp1,fp2);
				fclose(fp1);
				fclose(fp2);
	}

	else{
		int iStatus;
		wait(&iStatus);

		if(WIFEXITED(iStatus)){
			printf("Exit Status:%d\n",WEXITSTATUS(iStatus));
		}

		else if (WIFSIGNALED(iStatus)){ 
			psignal(WTERMSIG(iStatus), "Exit signal"); 
		}

		else if (WIFSTOPPED(iStatus)){ 
			psignal(WSTOPSIG(iStatus), "STOP sqignal"); 
		}


	}

	if(iPid ==0){
		system("md5sum source.txt");
		printf("\n");
	
		/*As destination file name is stored in saperate variable named"destFileName"*/
		char cBuf[32];
		sprintf(cBuf, "md5sum %s", destFileName);
	
		system(cBuf);
		printf("\n");
	}


}

void CopyContent(FILE* fp1, FILE* fp2){
	while(1){
		
		char ich= fgetc(fp1);
		if(ich!=EOF)
			fputc(ich,fp2);
		else
			break;
	}
	printf("\n---- Copied Successfully ----\n\n");
}
