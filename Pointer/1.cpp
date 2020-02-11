//int N;
#include<iostream>
using namespace std;

#include<bits/stdc++.h>
#define N 5


void InsertDataIn2DArray(char (&ptrArray)[N][N]);
void Sort2DArray(char (&ptrArray)[N][N]);

int main(){
	
	//cout << "Enter N of Array:";
	//cin >> N;

	char ptrArray[N][N];
	/*char **ptrArray = new char*[N];

	for(int i=0;i<N;i++){
		ptrArray[i] = new char[N];
	}*/

	InsertDataIn2DArray(ptrArray);

	char *cTemp;
	cout << "fdfdf:" << ptrArray[1] << endl;
	//strcpy(cTemp, ptrArray[1]);
	//Sort2DArray(ptrArray);

	for(int row =0; row<N; row++){
		cout << endl;
		//for(int col=0; col<N; col++)
			cout << ptrArray[row];
	}
	cout << endl;
}


void InsertDataIn2DArray(char (&ptrArray)[N][N]){
	for(int index=0; index<N; index++){
		cin >> ptrArray[index];
	}
}


void Sort2DArray(char (&ptrArray)[N][N]){
	for(int row=0; row<N-1; row++){
		for(int col=row+1; col< N; col++){
			
			if(ptrArray[row][0]>ptrArray[col][0]){
				char cTemp[N];
				strcpy(cTemp, ptrArray[row]);
				strcpy(ptrArray[row], ptrArray[col]);
				strcpy(ptrArray[col], cTemp);
				/*cTemp = ptrArray[row];
				ptrArray[row] = ptrArray[col];
				ptrArray[col] = cTemp;*/
				
			}
		}
	}
}