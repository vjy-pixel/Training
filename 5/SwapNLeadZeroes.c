#include<stdio.h>
#include<stdlib.h>

#define BIT_RANGE 64

void SwapNumbers(int, int);
void LeadingZeroes(int);
int RangeCheck(int);

void main(){
	
	//printf("%d\n",sizeof(int) );
	//printf("%ld,%d\n",LOWER_LIMIT,UPPER_LIMIT);
	int iNum1,iNum2,iChoice;
	int iNum3,iFlag=0;

	while(1){
		printf("\n1.Swap\n2.Leading Zeroes\n3.Exit\n");
		printf("Enter Choice:");
		scanf("%d",&iChoice);

		switch(iChoice){
			case 1:
				SwapNumbers(iNum1, iNum2);
				break;
			
			case 2:
				LeadingZeroes(iNum3);
				break;

			case 3:
				printf("Thank You!!!\n");
				exit(0);

			default:
				printf("Please make valid Choice!!!\n");
		}
	
	}
	
}


void SwapNumbers(int iNum1, int iNum2){

	printf("\n============================ Swap Numbers =============================\n");
	printf("Enter First Number:");
 	scanf("%d",&iNum1);
	int iTemp,iFlag=0;

	iTemp=iNum1;
	
	iFlag=RangeCheck(iNum1);
	
	iNum1 = iTemp;

	if(iFlag==0){
		printf("Enter Second Number:");
		scanf("%d",&iNum2);
					
		iTemp=iNum2;

		iFlag=RangeCheck(iNum2);

		iNum2 = iTemp;
	}
	
	if(iFlag==0){
		
		iNum1= iNum1^iNum2;
		iNum2= iNum1^iNum2;
		iNum1= iNum1^iNum2;

		printf("\n-----------\n");
		printf("First:%d\nSecond:%d",iNum1,iNum2);
		printf("\n-----------\n");
	}
	printf("======================================================================\n");
}

void LeadingZeroes(int iNum3){

	printf("\n=============== Leading Zeroes ==================\n\n");
	printf("Enter Number:");
	scanf("%d",&iNum3);
		
	int iZeroBit=0;		
				
	for(int bitCount=0; bitCount<BIT_RANGE; bitCount++,iNum3/=2){
		printf("%d ",(iNum3%2) );
		if((iNum3%2) == 0)
			iZeroBit++;
		
		else if((iNum3%2) == 1)
			iZeroBit=0;
		
		else{
			printf("Number is Out of Range of range of Integer!!!!\n");
			break;
		}

	}
		
	printf("\nLeading Zeroes:%d",iZeroBit);
	printf("\n=================================================\n");
	
}

int RangeCheck(int iNum){

	int iFlag;
	for(int bitCount=0; bitCount<BIT_RANGE; bitCount++,iNum/=2){
						//printf("%d ",(iNum3%2) );
		if((iNum%2)==-1){
			iFlag=1;
			printf("Number is Out of Range of range of Integer!!!!\n");
			break;
		}

		else{
			iFlag=0;
		}
	}
	return iFlag;
}