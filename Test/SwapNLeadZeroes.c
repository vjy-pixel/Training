#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout << "============ Swapping Number ==============" << endl << endl;
	long int in1,in2;
	cout << "Enter first number:";
	cin >> in1;
	cout << "Enter Second number:";
	cin >> in2;
	
	in1=in1^in2;
	in2=in1^in2;
	in1=in1^in2;
	
	cout << endl;	
	cout << "First:" << in1 << endl;
	cout << "Second:" << in2 << endl;
	cout << endl <<"===========================================" << endl << endl << endl;
	
	
	cout << "============== Find Leading Zeroes ==============" << endl << endl;
	long int in3,index=0;
	cout << "Enter Number:";
	cin >> in3;
	cout << sizeof(in3)*8;
	while(1) 
		if(pow(2,index++)-in3>=0) 
			break;
		else 
			continue;
		cout << "Leading zeroes will be:"<< (sizeof(in3)*8)-index << endl;
	cout << endl << "==============================================" << endl;	
}