#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int in1,in2;
	cout << "============ Swapping Number ==============" << endl << endl;
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
	
	int in3,index=0;
	cout << "============== Find Leading Zeroes ==============" << endl << endl;
	cout << "Enter Number:";
	cin >> in3;
	//cout << sizeof(in3) << endl;
	//cout << pow(2,index++);
	while(1) 
		if(pow(2,index++)-in3>=0) break;
		else continue;
		cout << "Leading zeroes will be:"<< 64-index << endl;
	cout << endl << endl <<"==============================================" << endl;	
}