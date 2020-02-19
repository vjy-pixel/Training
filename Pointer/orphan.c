#include<stdio.h>
#include<stdlib.h>

void main(){
	int iId = fork();

	if(iId == 0){
		printf("Child Process\n");
		exit(0);
	}

	else{

		printf("Parent Process\n");
		sleep(30);
	}
}