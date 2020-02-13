#include<iostream>
using namespace std;

#include<bits/stdc++.h>
#define N 5

/*********************************************************************************
	* This method is to take input in given 2D character array.
	*
	* This method will accept one reference varialbe as argument
	* 
	* Reference variable will be refering to the 2D character array
	*
	* @param char&
	*
	* @return void
*********************************************************************************/
void InsertDataIn2DArray(char (&ptrArray)[N][N]);


/**************************************************************************
	* This method will sort given 2D character array in alphanumeric order.
	*
	* This method will accept one reference varialbe as argument
	* 
	* Reference variable will be refering to the 2D character array
	*
	* @param char&
	*
	* @return void
***************************************************************************/
void Sort2DArray(char (&ptrArray)[N][N]);

int main(){
	

	char ptrArray[N][N];
	

	InsertDataIn2DArray(ptrArray);
	
	Sort2DArray(ptrArray);

	for(int row =0; row<N; row++){
		cout << endl;
		cout << ptrArray[row];
	}
	cout << endl;
}


void InsertDataIn2DArray(char (&ptrArray)[N][N]){
	for(int index=0; index<N; index++){
		
		cin >> ptrArray[index];
		
		if(strlen(ptrArray[index])>= N){
			cout << "String limit exceeded!!!" << endl;
			exit(0);
		}
		
		ptrArray[index][4] = '\0';
	}
}


void Sort2DArray(char (&ptrArray)[N][N]){
	
	for(int row=0; row<N-1; row++){
		
		for(int col=row+1; col< N; col++){
			
			int iCount = 0;

			if(ptrArray[row][iCount]>ptrArray[col][iCount]){
				char cTemp[N];
				strcpy(cTemp, ptrArray[row]);
				strcpy(ptrArray[row], ptrArray[col]);
				strcpy(ptrArray[col], cTemp);
				break;
			}
			
			else if(ptrArray[row][iCount++]==ptrArray[col][iCount++]){
				char cTemp[N];
				strcpy(cTemp, ptrArray[row]);
				strcpy(ptrArray[row], ptrArray[col]);
				strcpy(ptrArray[col], cTemp);
				break;
			}
			
		}
	}
}