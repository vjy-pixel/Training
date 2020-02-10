#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned long long Factorial(int);
int main(){
	
	int iNumber;
	cout << "------------------------------\n";
	cout << "           Factorial          \n";
	cout << "------------------------------\n";
	cout << "Enter Number:";
	cout << iNumber;

	if(iNumber < 0){
		cout << "Factorial of Negative Number not Possible!!";
		exit(0);
	}

	unsigned long long iResult = Factorial(&iNumber);
	cout << iResult;
}

unsigned long long Factorial(int* ptrNumber){
	if(*ptrNumber < 2)
		return 1;
	else{
		(*ptrNumber--) * Factorial(ptrNumber);
	}
}