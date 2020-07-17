/*
	* Program for scanning the string from user space and return the same string in user application.
	*
	* To do so here, we have made one file descriptor(iFd), which will open a device driver located in /dev lib
	*
	* Here, the name of the character driver is kept "drv", which will be located to the /dev lib
	*
	* Then by executing "write_str" we can scan the string from user and send it to kernel module
	* 
	* Which will be available in kernel log
	*
	* In the same way we will be executing the "read_str" function to fetch string from kernel module and will display it here
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFSIZE 256

/*To scan the string from user and send it to kernel module*/
int write_str(int);

/*To read the string from kernel module and print it on console*/
int read_str(int);

int main()
{
	int iFd;//file descriptor
	char string[BUFSIZE];//string to be transmitted

	/*User must be having /dev lib access permission*/
	iFd = open("/dev/drv", O_RDWR); 
	if(iFd<0)
	{
		perror("Unable to open device\n");
		return errno;
	}
	
	write_str(iFd);
	read_str(iFd);
	
	return 0;
}

int write_str(int iFd)
{
	char wrstr[BUFSIZE];
	int iRet;

	printf("Enter a string:");
	scanf("%s",wrstr);

	printf("Message to be written on a device:%s\n",wrstr);

	iRet = write(iFd, wrstr, strlen(wrstr));

	if(iRet<0)
	{
		perror("Unable to write on a device\n");
		return errno;
	}
}

int read_str(int iFd)
{
	char rdstr[BUFSIZE];
	int iRet = read(iFd, rdstr, strlen(rdstr));

	if(iRet<0)
	{
		perror("Unable to read on a device\n");
		return errno;
	}
	else
		printf("Msg from Kernel:%s\n",rdstr);

}