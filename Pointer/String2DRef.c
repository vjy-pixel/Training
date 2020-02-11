#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void InsertDataIn2DArray(char**, int);
void Sort2DArray(char**, int);
int main(){
	int iSize;
	cout << "Enter size of Array:";
	cin >> iSize;

	char *strArray[iSize];
	/*char **ptrArray = new char*[iSize];

	for(int i=0;i<iSize;i++){
		ptrArray[i] = new char[iSize];
	}*/

	InsertDataIn2DArray(&strArray, iSize);
	Sort2DArray(&strArray, iSize);

	for(int row =0; row<iSize; row++){
		cout << endl;
		//for(int col=0; col<iSize; col++)
			cout << strArray[row];
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
			
			if(ptrArray[row][0]>ptrArray[col][0]){
				char* cTemp;
				cTemp = ptrArray[row];
				ptrArray[row] = ptrArray[col];
				ptrArray[col] = cTemp;
				
			}
		}
	}
}