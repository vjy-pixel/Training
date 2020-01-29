#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout << "Enter size of array:";
	cin >> n;
	int arr[n+50];
	cout << "Enter elements of array:\n";
	for(int i=0;i<n;i++)
		cin >> arr[i];

	int x;
	int ch;
	
	while(1)
	{
	cout << "1.Insert" << endl << "2.Delete" << endl << "3.Length" << endl << "4.Exit" << endl;
	cin >> ch;
	switch(ch){
	//----------------------------------------------------- For Insertion-----------------------------------------------------------
	case 1:	
	cout << "Enter element you want to add:";
	cin >> x;
	char choice;
	
	cout << "Where to add?" << endl << "1.Start" << endl << "2.Specific Location" << endl << "3.End" << endl;
	//getc(choice);
	cin >> choice;
	switch(choice){
	case '1':
		for(int i=n++;i>0;i--)
			arr[i]=arr[i-1];
		arr[0]=x;
		break;

	case '2':
		int pos;
		cout << "Enter the position:";
		cin >> pos;
		
		for(int i=n++;i>pos-1;i--)
			arr[i]=arr[i-1];
		arr[pos-1]=x;
		break;
	case '3':
		arr[n++]=x;
		break;
	default:
		cout << "Please make valid choice!!!";
	}
	cout << "Final Array:";
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	break;	
	

	//------------------------------------------------------- For Deletion----------------------------------------------------------
	case 2:	
	cout << "Enter element you want to delete:";
	cin >> x;
	//char choice;
	
	cout << "From Where?" << endl << "1.Start" << endl << "2.Specific Location" << endl << "3.End" << endl;
	//getc(choice);
	cin >> choice;
	switch(choice){
	case '1':
		for(int i=0;i<n-1;i++)
			arr[i]=arr[i+1];
		n--;
		//arr[n]=x;
		break;

	case '2':
		int pos;
		cout << "Enter the position:";
		cin >> pos;
		
		for(int i=pos-1;i<n-1;i++)
			arr[i]=arr[i+1];
		n--;
		//arr[pos-1]=x;
		break;
	case '3':
		n--;
		break;
	default:
		cout << "Please make valid choice!!!";
	}
	cout << "Final Array:";
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	
	break;
	//------------------------------------------------------------------------------------------------------------------------------
	case 3: 
		cout << "The length of an array is:" << n << endl;	
		break;

	case 4:
		exit(0);

	default:
		cout << "Please make valid Choice!!!";
}
}
}