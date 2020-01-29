#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINES 10

int ifault_check(char strop[]);
int imaxlen(int ilen[]);
int iblank=0;
void main(){
	FILE *fp;
	fp =fopen("file_input.txt","r");
	char strop[256];
	int ichcount=0,ilinecount=0,icount=0;
	int ilen[MAX_LINES]={0};	
	if(fp==NULL)
		printf("An Error Occured!!!");
	
	else{
		//fflush(stdin);
		while(!feof(fp) && ilinecount<10){
			fgets(strop,256,fp);
			int ifault = ifault_check(strop);

			if(ifault==0){
				ilinecount++;
				ilen[icount++]=strlen(strop);
			}
		
		}
		int imaxidx = imaxlen(ilen);
		
		int isum=0;
		for(int index=0; index<= imaxidx; index++){
			isum+= ilen[index];
			
		}
		
		fseek(fp,(long)(isum-ilen[imaxidx]+iblank),0);
		
		if(ilen[imaxidx]==0)
			printf("File is Empty!!!\n");
		else{
			fgets(strop,ilen[imaxidx],fp);
			printf("Longest String:%s at %d position\n",strop,imaxidx+1);		

		}
		
	}
}

int ifault_check(char strop[]){
	int iflag=0;
	for(int index=0; index<strlen(strop); index++){
		if(strop[index]==' ' || strop[0]=='\n'){
			iflag++;
			iblank++;
		}
		else
			iflag=0;
	}
	return iflag;
}

int imaxlen(int ilen[]){
	int imax=0,imaxidx;
	for(int index=0; index<MAX_LINES; index++){
		if(ilen[index] > imax){
			imax = ilen[index];
			imaxidx = index;
		}
	}
	return imaxidx;
}