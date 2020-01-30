#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINES 10

/* To check whether line is blank(faulty) or not. */
int faultCheck(char strop[]);

/* To find maximum length amongst all lines.  */
int maxLength(int ilen[]); 		 

/*To keep the count of blank lines after entring first character.*/
int iblank=0;
void main(){
	FILE *fp;
	fp =fopen("file_input.txt","r");
	
	/*Output String*/
	char strop[256]; 
	
	/*
		* ilinecount - Number of Lines
		* ilen[MAXS_LINE] - Array that stores Lengths of lines
		* icount - index of  Array of lengths of lines(ilen[MAX_LINES])
	*/
	int ichcount=0,ilinecount=0,icount=0;
	int ilen[MAX_LINES]={0};	
	if(fp==NULL)
		printf("An Error Occured!!!");
	
	else{
		//fflush(stdin);
		while(!feof(fp) && ilinecount<10){
			fgets(strop,256,fp);
			
			/*
			  if it encounters blank lines in between then
			  ifault's value will be non-zero
			*/
			int ifault = faultCheck(strop);

			if(ifault==0){
				ilinecount++;
				ilen[icount++]=strlen(strop);
			}
		
		}
		
		/*call to maxLength function*/
		int imaxidx = maxLength(ilen); 
		
		int isum=0;
		for(int index=0; index <=imaxidx; index++){
			isum+= ilen[index];
			
		}
		
		/*
			Below Statement sets the File Pointer(fp) to the starting position of 
			line with maximum length, so that it can get printed.
		*/
		fseek(fp,(long)(isum -ilen[imaxidx] +iblank),0);
		
		if(ilen[imaxidx] ==0)
			printf("File is Empty!!!\n");
		else{
			fgets(strop, ilen[imaxidx], fp);
			printf("Longest String:%s at %d position\n", strop, imaxidx+1);		

		}
		
	}
}


/*
	* As line is fetched, it will be passed to 'faultCheck' function.
	* It checks whether that lines are blank(faulty) or not after entering first character to the file
	* If it encounters only BLANK SPACES or LINE BREAKS then it will evaluate that line as faulty and
	* will return non-zero value.	
*/
int faultCheck(char strop[]){
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

/*
	* The array consisting lengths of lines(ilen[]) passed to 'maxLength' function.
	* It returns the index of the line with maximum length.

*/
int maxLength(int ilen[]){
	int imax=0,imaxidx;
	for(int index=0; index<MAX_LINES; index++){
		if(ilen[index] > imax){
			imax = ilen[index];
			imaxidx = index;
		}
	}
	return imaxidx;
}