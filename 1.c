#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX_FNAME 20
#define MAX_LINES 10
void main(){
	char strFName[MAX_FNAME];
	int len[MAX_LINES];
	
	printf("Enter input file name(with extension):");   /**/
	scanf("%s",strFName);

	if(!fork())                                           //It will open new file (named by user) in text editor
		execlp("gedit","gedit",strFName".txt",NULL);       // in which user will enter the lines.


/*	FILE *ptrInput;
	ptrInput=fopen(strName,"r");
	
*/	
	
	
}
