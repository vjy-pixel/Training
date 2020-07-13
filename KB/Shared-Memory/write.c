#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>

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
	struct student *stu;

	int iTotal; // Total no of students
	int  iTemp; // For storing roll no of students temperarily while entering marks

	printf("Enter total number of Students:");
	scanf("%d",&iTotal);
	
	int iSize = iTotal*sizeof(struct student); // Total size required to get shared memory
	
	//printf("iSize:%d\n", iSize);
	
	int shmid = shmget(SHM_KEY, iSize, 0666|IPC_CREAT); // Shared memory ID
	//printf("shmid:%d\n",shmid);
	if(shmid == -1)
	{
		perror("Shared Memory\n");
	}


	stu = (struct student*)shmat(shmid, NULL,0); // shared memory attachment
	//printf("attach:%ls\n", (int*)stu);

	for(int i=0; i<iTotal; i++)
	{
		
		printf("Enter Roll no of student(Press Ctrl-C to exit):\n");
		scanf("%d",&iTemp);

		if(iTemp > iTotal)
		{
			printf("Invalid Input, Please enter number less that total students.\n");
			exit(0);
		}

		stu[iTemp-1].iRollNo = iTemp;

		printf("-----------------------------------------\n");
		printf("Maths:");
		scanf("%d",&stu[iTemp-1].iMath);

		//printf("---\n");
		printf("Physics:");
		scanf("%d",&stu[iTemp-1].iPhy);

		printf("Chemistry:");
		scanf("%d",&stu[iTemp-1].iChem);	

		stu[iTemp-1].fResult = ((stu[iTemp-1].iMath + stu[iTemp-1].iPhy + stu[iTemp-1].iChem)/3);
		printf("Result:%.2f percent\n", stu[iTemp-1].fResult);

		printf("-----------------------------------------\n");
	}

	// shared memory detachment
	if(shmdt(stu)==-1)
			perror("Detach Failed!!\n");
	//shmctl(shmid, IPC_RMID, NULL);
	
}