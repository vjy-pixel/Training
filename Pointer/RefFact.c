#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/****************************************************
	* A method that takes address as an argument 
	* and recursively calls the same function by
	* decrementing value of the address to which 
	* pointer is pointing.
	*
	* @param int*
	*
	* @return unsigned long long 
*****************************************************/
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

/* Pass By Reference*/
unsigned long long Factorial(int& refNumber){
	if(refNumber < 2)
		return 1;
	else{
		return ((refNumber)--) * Factorial(refNumber);
	}
}