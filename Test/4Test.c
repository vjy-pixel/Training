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
		cout << "----------------------------" << endl;
		cout << "1.Insert" << endl << "2.Delete" << endl << "3.Show" << endl << "4.Exit" << endl;
		cout << "----------------------------" << endl;
		cout << "Choose:";
		cin >> ch;
		
		switch(ch){
		//----------------------------------------------------- For Insertion-----------------------------------------------------------
			case 1:	
				cout << "Enter element you want to add:";
				cin >> x;
				char choice;
	
				cout << endl << "Where to add?" << endl << "1.Start" << endl << "2.Specific Location" << endl << "3.End" << endl;
	
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
			
				break;	
	

			//------------------------------------------------------- For Deletion----------------------------------------------------------
			case 2:	
				if(n==0)
					cout << "Nothing to Delete!!!! :(" << endl;
				else{
					cout << "From Where?" << endl << "1.Start" << endl << "2.Specific Location" << endl << "3.End" << endl;
	
					cin >> choice;
					switch(choice){
						case '1':
							for(int i=0;i<n-1;i++)
								arr[i]=arr[i+1];
							n--;
							break;

						case '2':
							int pos;
							cout << "Enter the position:";
							cin >> pos;
		
							for(int i=pos-1;i<n-1;i++)
								arr[i]=arr[i+1];
							n--;
							break;
	
						case '3':
							n--;
							break;
	
						default:
							cout << "Please make valid choice!!!";
					}
				}
	
			break;
	
	//----------------------------------------------------------------------------------
			case 3: 
				if(n==0)
					cout << "Nothing to Show!!! :(" << endl;
				else{
					cout << "Final Array:";
					for(int i=0;i<n;i++)
						cout << arr[i] << " ";
					cout << endl;
			
					cout << "Array-Length:" << n << endl;
				}	
				break;

			case 4:
				cout << "Thank You!!!! :)";
				exit(0);

			default:
				cout << "Please make valid Choice!!!";
		}
	}
}