#include<stdio.h>

void main(){
	char *cptrSelf = "#include<stdio.h>%c%cvoid main(){%c  char*cptrSelf = %c%s%c;%c  printf(cptrSelf,10,10,34,cptrSelf,34,10,10,10);%c}%c";
	printf(cptrSelf,10,10,10,34,cptrSelf,34,10,10,10,10);
}