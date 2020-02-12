#include<iostream>
using namespace std;

#include<bits/stdc++.h>
#define N 5


void InsertDataIn2DArray(char (&ptrArray)[N][N]);
void Sort2DArray(char (&ptrArray)[N][N]);

int main(){
	

	char ptrArray[N][N];
	

	InsertDataIn2DArray(ptrArray);
	//char *cTemp = ptrArray[0];
	//strcpy(ptrArray[1], ptrArray[4]);
	//strcpy(ptrArray[2], cTemp);
	
	//cTemp = (ptrArray)[0];
	//ptrArray[1] = cTemp;
	//cout << "cTemp:" << ptrArray[1]<< endl;
	
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
	int cnt=0;
	for(int row=0; row<N-1; row++){
		cout << ++cnt << endl;
		for(int col=row+1; col< N; col++){
			cout << ptrArray[row][0] << " --" << ptrArray[col][0] << "\n";
			if(ptrArray[row][0]>ptrArray[col][0]){
				char *cTemp = *(ptrArray+row);
				cout << "cTemp:" << cTemp<< endl;
				//strcpy(cTemp, ptrArray[row]);
				strcpy(ptrArray[row], ptrArray[col]);
				cout << "1:" << ptrArray[row]<< endl;
				cout << "cTemp:" << cTemp<< endl;
				strcpy(ptrArray[col], cTemp);
				cout << "2:" << ptrArray[col]<< endl;
				//break;
				//cTemp = ptrArray[row];
				//ptrArray[row] = ptrArray[col];
				//ptrArray[col] = cTemp;
				
			}
		}
	}
}