
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void InsertDataIn2DArray(int*, int);
void Sort2DArray(int*, int);
int main(){
	int iSize;
	cout << "Enter size of Array:";
	cin >> iSize;

	int *ptrArray = (int*) malloc(iSize*iSize*sizeof(int));

	InsertDataIn2DArray(ptrArray,iSize);

	//for(int index=0; index<iSize; index+)
	Sort2DArray(ptrArray,iSize);
	

	//cout << "fsdfsdf";
	for(int row =0; row<iSize; row++){
		cout << endl;
		for(int col=0; col<iSize; col++)
			cout << *(ptrArray+ row*iSize +col) << " ";
	}
	cout << endl;
}

void InsertDataIn2DArray(int* ptrArray, int iSize){
	for(int row =0; row<iSize; row++)
		for(int col=0; col<iSize; col++)
			cin >> *(ptrArray+ row*iSize +col);

}

void Sort2DArray(int* ptrArray, int iSize){
		for(int index=0; index< iSize*iSize; index++){
		
			for(int cnt=index+1;cnt< iSize*iSize;cnt++){
			
				if(ptrArray[index]>ptrArray[cnt]){
				
					ptrArray[index]=ptrArray[index]+ptrArray[cnt];
					ptrArray[cnt]=ptrArray[index]-ptrArray[cnt];
					ptrArray[index]=ptrArray[index]-ptrArray[cnt];
				}
			}
		}
	


	
}