#include<stdio.h>


void main(){
	int iRow1;
	printf("Enter no of rows of first matrix:");
	scanf("%d",&iRow1);
	
	int iCol1;
	printf("Enter no of cols of first matrix:");
	scanf("%d",&iCol1);
	
	int iRow2;
	printf("Enter no of rows of second matrix:");
	scanf("%d",&iRow2);
	
	int iCol2;
	printf("Enter no of cols of second matrix:");
	scanf("%d",&iCol2);
	
	int a[iRow1][iCol1],b[iRow2][iCol2];
	
	//	int i,j;
	printf("For A:\n");
	for(int iRow =0; iRow <iRow1; iRow++)
		for(int iCol=0; iCol <iCol1; iCol++)
			scanf("%d", &a[iRow][iCol]);
		
	printf("For B:\n");
	for(int iRow =0; iRow <iRow2; iRow++)
		for(int iCol =0; iCol <iCol2; iCol++)
			scanf("%d", &b[iRow][iCol]);


	int c[iRow1][iCol2];
	if(iCol1 !=iRow2)
		printf("Multiplication not possible!!!");
	
	else{
		//int i,j,k;
		for(int i=0; i <iRow1; i++)
			for(int j=0; j <iCol2; j++){
			    int isum=0;
				for(int k=0; k<iCol1; k++){
					isum +=a[i][k]*b[k][j];
				}
				c[i][j] =isum;
			}
	}
	printf("\n");
//	int i,j;
	for(int iRow=0; iRow <iRow1; iRow++){
	    printf("\n");
		for(int iCol=0; iCol <iCol2; iCol++)
			printf("%d\t",c[iRow][iCol]);
	}
}