#include<stdio.h>
#include<stdlib.h>

#define NO_OF_CAMS 8

typedef struct Cameras
{
	int iPre,iPost;
	long lPreTime,lPostTime; 
	int iCamIndex;
} Camera;


void sorting(Camera*);
void divide(Camera*, int , int);
void merge(Camera*, int, int ,int);

void main()
{
	long lEvent;
	printf("Enter time of Event Generation:");
	scanf("%ld",&lEvent);

	Camera cams[NO_OF_CAMS];
	Camera *camsPoint = cams;

	printf("\nEnter Pre & Post time for each camera:\n");
	for(int i=0; i<NO_OF_CAMS; i++)		
	{
		cams[i].iCamIndex = i;
		printf("Cam-%d:\n",i);
		
		printf("Pre:");
		scanf("%d",&cams[i].iPre);
		
		printf("Post:");
		scanf("%d",&cams[i].iPost);
		
		cams[i].lPreTime = lEvent - cams[i].iPre;
		cams[i].lPostTime = lEvent + cams[i].iPost;
		
		printf("\n");
	}

	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",cams[i].iCamIndex, cams[i].lPreTime, cams[i].lPostTime);
	}
	printf("\n");
	
	sorting(camsPoint);

	printf("sorted:");
	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",cams[i].iCamIndex, cams[i].lPreTime, cams[i].lPostTime);
	}
	printf("\n");

}

void sorting(Camera *camsPoint)
{
	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",(camsPoint+(i))->iCamIndex, (camsPoint+(i))->lPreTime, (camsPoint+(i))->lPostTime);	}
	printf("\n");



	
	divide(camsPoint, 0, NO_OF_CAMS-1);
}

void divide(Camera* camsPoint, int iLow, int iUp)
{

	if(iLow < iUp)
	{
		int iMed = (iLow + iUp)/2;

		divide(camsPoint, iLow, iMed);
		divide(camsPoint, iMed+1, iUp);
		
		merge(camsPoint, iLow, iMed, iUp);
	}
}

void merge(Camera* camsPoint, int iLow, int iMed, int iUp)
{
	long extraPre[iUp-iLow+1];
	long extraPost[iUp-iLow+1];
	long extraCam[iUp-iLow+1];

	int extraIndex = 0;
	
	int p = iLow, q = iMed+1;

	for(int i=iLow; i<=iUp; i++)
	{		
		if(p > iMed)
		{
			extraPre[extraIndex++] = (camsPoint+(q++))->lPreTime;
			extraPost[extraIndex++] = (camsPoint+(q++))->lPostTime;
			extraCam[extraIndex++] = (camsPoint+(q++))->iCamIndex;

		}
		
		else if(q > iUp)
		{
			extraPre[extraIndex++] = (camsPoint+(p++))->lPreTime;
			extraPost[extraIndex++] = (camsPoint+(p++))->lPostTime;
			extraCam[extraIndex++] = (camsPoint+(p++))->iCamIndex;


		}
		
		else if((camsPoint+(p))->lPreTime < (camsPoint+(q))->lPreTime)
		{
			extraPre[extraIndex++] = (camsPoint+(p++))->lPreTime;
			extraPost[extraIndex++] = (camsPoint+(p++))->lPostTime;
			extraCam[extraIndex++] = (camsPoint+(p++))->iCamIndex;


		}
		
		else
		{
			extraPre[extraIndex++] = (camsPoint+(q++))->lPreTime;
			extraPost[extraIndex++] = (camsPoint+(q++))->lPostTime;
			extraCam[extraIndex++] = (camsPoint+(q++))->iCamIndex;
		}

	}

	for(int i=0; i< extraIndex; i++)
	{
		(camsPoint+(iLow++))->lPreTime = extraPre[i]; 	
		(camsPoint+(iLow++))->lPostTime = extraPost[i]; 
		(camsPoint+(iLow++))->iCamIndex = extraCam[i]; 

	}
}
