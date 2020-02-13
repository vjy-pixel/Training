#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*******************************************************************************
	* This method is to take input in given 2D character array.
	*
	* This method will accept one double-pointer and int variable as argument
	* 
	* Double-Pointer will be pointing to the 2D character array
	*
	* @param char**, int
	*
	* @return void
********************************************************************************/
void InsertDataIn2DArray(char**, int);


/**************************************************************************
	* This method will sort given 2D character array in alphanumeric order.
	*
	* This method will accept one double-pointer and int variable.
	* 
	* Double-Pointer will be pointing to the 2D character array
	*
	* @param char**, int
	*
	* @return void
***************************************************************************/
void Sort2DArray(char**, int);

int main(){

	int iSize;
	cout << "Enter size of Array:";
	cin >> iSize;

	char **ptrArray = new char*[iSize];

	for(int i=0;i<iSize;i++){
		ptrArray[i] = new char[iSize];
	}

	InsertDataIn2DArray(ptrArray, iSize);
	Sort2DArray(ptrArray, iSize);

	for(int row =0; row<iSize; row++){
		cout << endl;
		//for(int col=0; col<iSize; col++)
			cout << ptrArray[row];
	}
	cout << endl;
}


void InsertDataIn2DArray(char** ptrArray, int iSize){
	for(int index=0; index<iSize; index++){
		cin >> ptrArray[index];
	}
}


void Sort2DArray(char** ptrArray, int iSize){
	
	for(int row=0; row<iSize-1; row++){
		
		for(int col=row+1; col< iSize; col++){
			
			int iCount=0;
		
			if(ptrArray[row][iCount]>ptrArray[col][iCount]){
				char* cTemp;
				cTemp = ptrArray[row];
				ptrArray[row] = ptrArray[col];
				ptrArray[col] = cTemp;
				break;
			}
			
			else if(ptrArray[row][iCount++]==ptrArray[col][iCount++]){
				char* cTemp;
				cTemp = ptrArray[row];
				ptrArray[row] = ptrArray[col];
				ptrArray[col] = cTemp;
				break;
			}
			
		}
	}
}