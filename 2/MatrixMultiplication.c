#include<stdio.h>
#include<stdlib.h>

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

	/*Validity Check!!*/
	if(iCol1 !=iRow2){
		printf("Multiplication not possible!!\nAs Column Count of Matrix 1 and Row Count of Matrix 2 is not Equal!!\n");
		exit(0);
	}
	
	int a[iRow1][iCol1],b[iRow2][iCol2];
	
	/*Input to the Matrices*/
	printf("For A:\n");
	for(int iRow =0; iRow <iRow1; iRow++)
		for(int iCol=0; iCol <iCol1; iCol++)
			scanf("%d", &a[iRow][iCol]);
		
	printf("For B:\n");
	for(int iRow =0; iRow <iRow2; iRow++)
		for(int iCol =0; iCol <iCol2; iCol++)
			scanf("%d", &b[iRow][iCol]);


	/*Multiplication Process*/
	int c[iRow1][iCol2];
	
	for(int i=0; i <iRow1; i++)
		for(int j=0; j <iCol2; j++){
			
			int isum=0;
			for(int k=0; k<iCol1; k++){
				isum +=a[i][k]*b[k][j];
			}
			c[i][j] =isum;
		}
	
	printf("\n");


	/*Printing Final Matrix*/
	for(int iRow=0; iRow <iRow1; iRow++){
	    printf("\n");
		for(int iCol=0; iCol <iCol2; iCol++)
			printf("%d\t",c[iRow][iCol]);
	}
	printf("\n");
}