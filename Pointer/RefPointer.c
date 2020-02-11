#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned long long Factorial(int&);

int main(){
	
	int iNumber;
	cout << "------------------------------\n";
	cout << "           Factorial          \n";
	cout << "------------------------------\n";
	cout << "Enter Number:";
	cin >>iNumber;

	if(iNumber < 0){
		cout << "Factorial of Negative Number is not Possible!!\n";
		exit(0);
	}

	unsigned long long iResult = Factorial(iNumber);
	cout << iResult << endl;
}

/* Pass By Pointer*/
unsigned long long Factorial(int& refNumber){
	if(refNumber < 2)
		return 1;
	else{
		//cout << *ptrNumber << endl;
		return ((refNumber)--) * Factorial(refNumber);
	}
}