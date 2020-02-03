#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	
	char *ptrChar = (char*)malloc(sizeof(char)*100);
	
	printf("Enter Name:");
	scanf("%s",ptrChar);

	strcat(ptrChar,".txt");
	
	FILE *fp = fopen(ptrChar,"w");

	if(fp== NULL)
		printf("Failed to open file");

	else
		printf("File opened Successfully");
}

