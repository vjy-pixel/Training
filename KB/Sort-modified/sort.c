#include<stdio.h>
#include<stdlib.h>

#define NO_OF_CAMS 8

typedef struct Cameras
{
	//int iPre,iPost;
	long lPreTime[NO_OF_CAMS],lPostTime[NO_OF_CAMS]; 
	int iCamIndex[NO_OF_CAMS];
} Camera;


/***********************************************************************
	* A method that will be called for sorting of Pre-Time
	*
	* Here, Merge sort is used. Sorting will be done on Pre-Time only.
	*
	* And along with Pre-Time Post-Time and Camera-Index will also be moved
	*
	* according the value of Pre-Times of diff cameras
	*
	* @param : Pointer of user-defined data-type Camera
	*
	* @return : void
************************************************************************/
void sorting(Camera*);

/***********************************************************************
	* A method that is part of merge sort, to divide array
	*
	* @param : Pointer of user-defined data-type Camera, int, int
	*
	* @return : void
************************************************************************/
void divide(Camera*, int , int);

/**************************************************************************************
	* A method that is part of merge sort, to merge the divided array in sorted order 
	*
	* @param : Pointer of user-defined data-type Camera, int, int, int
	*
	* @return : void
***************************************************************************************/
void merge(Camera*, int, int ,int);

void main()
{
	/*Event Time will be stored in this variable*/
	long lEvent;

	/*To store difference to be made to get Pre and Post time of the cameras*/
	int iDiff=0;
	printf("Enter time of Event Generation:");
	scanf("%ld",&lEvent);

	Camera cams;

	/*Pointer that refers to above array*/
	/*This is used so that modification of array over functions can be easier*/
	Camera *camsPoint = &cams;

	
	/*Pre-Sorting Array*/	
	for(int i=0; i<NO_OF_CAMS; i++)		
	{
		cams.iCamIndex[i] = i;
		printf("Cam-%d:\n",i);
		
		cams.lPreTime[i] = lEvent - ++iDiff;
		cams.lPostTime[i] = lEvent + ++iDiff;
		
		printf("\n");
	}

	/*Sorted Array*/	
	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",cams.iCamIndex[i], cams.lPreTime[i], cams.lPostTime[i]);
	}
	printf("\n");
	
	sorting(camsPoint);

	printf("sorted:");
	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",cams.iCamIndex[i], cams.lPreTime[i], cams.lPostTime[i]);
	}
	printf("\n");

}

void sorting(Camera *camsPoint)
{
	for(int i=0;i <NO_OF_CAMS; i++)
	{
		printf("\ncam-%d:%ld-%ld",(camsPoint)->iCamIndex[i], (camsPoint)->lPreTime[i], (camsPoint)->lPostTime[i]);
	}
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
	/*Temparary arrays to store Pre-Time,Post-Time and Camera-Index temprarily during merging*/
	long extraPre[iUp-iLow+1];
	long extraPost[iUp-iLow+1];
	long extraCam[iUp-iLow+1];

	int extraIndex = 0;
	
	int p = iLow, q = iMed+1;

	for(int i=iLow; i<=iUp; i++)
	{		
		if(p > iMed)
		{
			extraPre[extraIndex] = (camsPoint)->lPreTime[q];
			extraPost[extraIndex] = (camsPoint)->lPostTime[q];
			extraCam[extraIndex++] = (camsPoint)->iCamIndex[q++];

		}
		
		else if(q > iUp)
		{
			extraPre[extraIndex] = (camsPoint)->lPreTime[p];
			extraPost[extraIndex] = (camsPoint)->lPostTime[p];
			extraCam[extraIndex++] = (camsPoint)->iCamIndex[p++];


		}
		
		else if((camsPoint)->lPreTime[p] < (camsPoint)->lPreTime[q])
		{
			extraPre[extraIndex] = (camsPoint)->lPreTime[p];
			extraPost[extraIndex] = (camsPoint)->lPostTime[p];
			extraCam[extraIndex++] = (camsPoint)->iCamIndex[p++];


		}
		
		else
		{
			extraPre[extraIndex] = (camsPoint)->lPreTime[q];
			extraPost[extraIndex] = (camsPoint)->lPostTime[q];
			extraCam[extraIndex++] = (camsPoint)->iCamIndex[q++];
		}

	}

	for(int i=0; i< extraIndex; i++)
	{
		(camsPoint)->lPreTime[iLow] = extraPre[i]; 	
		(camsPoint)->lPostTime[iLow] = extraPost[i]; 
		(camsPoint)->iCamIndex[iLow++] = extraCam[i]; 

	}
}
