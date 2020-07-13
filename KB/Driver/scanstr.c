#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFSIZE 256
int main()
{
	int iRet,iFd;
	char string[BUFSIZE];

	iFd = open("/dev/Character Device", O_RDWR);

	if(iFd<0)
	{
		perror("Unable to open device\n");
		return errno;
	}

	printf("Enter a string:");
	scanf("%s",string);

	printf("Message to be written on a device:%s",string);

	iRet = write(iFd, string, strlen(string));

	if(iRet<0)
	{
		perror("Unable to write on a device\n");
		return errno;
	}
	return 0;
}
