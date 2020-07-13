#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>

//#define NO_OF_STUDENTS 10
#define SHM_KEY 5315

struct student
{
	int iRollNo;
	int iMath;
	int iPhy;
	int iChem;
	float fResult;
};

void main()
{ 
	int iTotal; // total number of students
	int iTemp; // to store roll no tempararily while getting result

	printf("Enter total number of Students:");
	scanf("%d",&iTotal);
	
	int iSize = iTotal*sizeof(struct student); // total size required to get shared memory
	
	struct student *stu; 
	
	int shmid = shmget(SHM_KEY, iSize, 0666|IPC_CREAT); //shared memory ID
	//printf("shmid:%d\n",shmid);
	if(shmid == -1)
	{
		perror("Shared Memory\n");
		exit(0);
	}

	stu = (struct student*)shmat(shmid, NULL,0); // shared memory attachment

	while(1)
	{

		printf("Enter Roll no of student(Press Ctrl-C to exit):\n");
		scanf("%d",&iTemp);
		if(iTemp > iTotal)
		{
			printf("Invalid Input, Please enter number less that total students.\n");
			continue;
		}
		
		printf("Enter marks of subjects out of 100\n");
		printf("-----------------------------------------\n");
		printf("Maths:");
		printf("%d\n",stu[iTemp-1].iMath);

		printf("Physics:");
		printf("%d\n",stu[iTemp-1].iPhy);

		printf("Chemistry:");
		printf("%d\n",stu[iTemp-1].iChem);

		printf("Result:");
		printf("%.2f percent\n",stu[iTemp-1].fResult);

		printf("-----------------------------------------\n");
	}

	// shared memory detachmet
	if(shmdt(stu)==-1)
			perror("Error in Detachment!!!!\n"); 
	
	// To destroy segment through shared memory control
	shmctl(shmid, IPC_RMID, NULL);
}