#include<iostream>
#include<bits/stdc++.h>

#define MAX_STR_LENGTH 1000
using namespace std;

/*************************************************************************************************
	* This method is to copy from one string(first arg) to another string(second arg)
	*
	* First and Second arguments are Character Pointers that points to src string tp dest string
	* 
	* While third argument is to access at most n bits.
	* 
	* @param char*, char*, int
	*
	* @return char*
**************************************************************************************************/
char* cpystrn(char*, char*, int);

/*************************************************************************************************
	* This method is to concate from one string(first arg) to another string(second arg)
	*
	* First and Second arguments are Character Pointers that points to src string tp dest string
	* 
	* While third argument is to access at most n bits.
	* 
	* @param char*, char*, int
	*
	* @return char*
**************************************************************************************************/
char* catstrn(char*, char*, int);

/*************************************************************************************************
	* This method is to compare from one string(first arg) to another string(second arg)
	*
	* First and Second arguments are Character Pointers that points to src string tp dest string
	* 
	* While third argument is to access at most n bits.
	* 
	* @param char*, char*, int
	*
	* @return char*
**************************************************************************************************/
int cmpstrn(char*, char*, int);

int main()
{
	char *str1 = (char*) malloc(sizeof(char)*MAX_STR_LENGTH);
	char *str2 = (char*) malloc(sizeof(char)*MAX_STR_LENGTH);
	
	/* Resultant string where result will be stored after copying. */
	char *cRes;
	
	/* To select what operation to be performed */
	int iChoice;
	
	/* To store at most how many characeters to be accessed */
	int iN;

	/* Result of Comparison operation of two strings */
	int iRes;

	/* To store lengths of two strings that will be passed in comparison operation */
	int iLen1, iLen2;
	while(1){
		
		cout << "1. Copy\n2. Compare\n3. Concate\n4.Exit\n";
		cout << "Enter Your Choice:";
		cin >> iChoice;
	
	switch(iChoice){
		
		case 1:
			cout << "================== Copy ===================\n";
			
			cout << "Enter String to Copy:";
			cin >> str1;
	
			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered string or not.
			***********************************************************************************/
			while(1){
				
				cout << "Enter Range till u wanna Copy:";
				cin >> iN;
				if(iN < strlen(str1))
					break;
				else{
					cout << "Please Try Again!!!\n";
					cout << "As entered value is greater than length of entered string\n";
					continue;
				}
			}

			/************ cpystrn() call *************/
			cRes = cpystrn(cRes,str1,iN);
			
			cout << "String Copied!!!\n";
			cout << cRes << endl;
			
			cout << "===========================================\n";

			free(cRes);
			free(str1);
			free(str2);
			
			break;
		case 2:
			cout << "------------------- Compare -----------------\n";

			cout << "Enter String from which to Compare:";
			cin >> str1;

			cout << "Enter Range till u wanna Compare:";
			cin >> iN;

			cout << "Enter String to which to Compare?:";
			cin >> str2;

			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered strings or not.
			***********************************************************************************/		
			while(1){
				
				cout << "Enter Range till u wanna Copy:";
				cin >> iN;
				if(iN < strlen(str1) && iN < strlen(str2))
					break;
				else{
					cout << "Please Try Again!!!\n";
					cout << "As entered value is greater than length of entered strings\n";
					continue;
				}
			}

			/************ cmpstrn() call *************/
			iRes = cmpstrn(str1, str2, iN);		

			if(iRes == 0)
				cout << "str1 is same as str2 till location" << iN << endl;

			else if(iRes > 0)
				cout << "str1 is greater than str2 till location" << iN << endl;				

			else
				cout << "str1 is less than str2 till location" << iN << endl;

			cout << "-----------------------------------------------\n";
			free(str1);
			free(str2);
			break;

		case 3:
			
			cout << "++++++++++++++++++ Concate +++++++++++++++++\n";
			cout << "Enter String from which to Concate:";
			cin >> str1;

			cout << "Enter Range till u wanna Concate:";
			cin >> iN;
			
			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered string or not.
			***********************************************************************************/
			while(1){
				
				cout << "Enter Range till u wanna Copy:";
				cin >> iN;
				if(iN < strlen(str1))
					break;
				else{
					cout << "Please Try Again!!!\n";
					cout << "As entered value is greater than length of entered string\n";
					continue;
				}
			}

			cout << "Enter String to which to Concate?:";
			cin >> str2;

			cRes = (char*) malloc(sizeof(char)*(iN));
			
			/************ catstrn() call *************/
			cRes = catstrn(str2,str1,iN);
			
			cout << "String Concated!!!\n";
			cout << cRes << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
			
			free(cRes);
			free(str1);
			free(str2);
			
			break;
		
		case 4:
			exit(0);
				
		default:
			cout << "Please make valid Choice!!!\n";
	}
	}	
	return 0;	
}

char* cpystrn(char* cRes, char* str, int iN){
	
	cRes = (char*) malloc(sizeof(char)*iN);
	if(NULL == cRes)
		cout << "Unable to get memory for Dest. String!!!\n";
	else{
		for(int index=0; index<iN; index++){
			//cout << "String Char:" << str[index] << endl;
			cRes[index] = str[index];
			//cout << "String Char:" << cRes[index] << endl;
		}
		cRes[iN] = '\0';
		cout << strlen(cRes) << endl;
	}
	//cout << cRes << endl;
	return cRes;
}


int cmpstrn(char* sStr, char* dStr, int iN){
	int iLen1 = strlen(sStr);
	int iLen2 = strlen(dStr);

	cout << "Length of String 1:" << iLen1 << endl;
	cout << "Length of String 2:" << iLen2 << endl;

	
	if(sStr > dStr)
		iN = iLen2;
	else
		iN = iLen1;

	int iSum = 0; 
	for(int index = 0; index<=iN; index++){
		//if(str1[index] > str2[index])
			iSum+=(sStr[index] - dStr[index]);
	}
	return iSum;
}
char* catstrn(char* dStr, char* sStr, int iN){
		

		int idLen = strlen(dStr);
		for(int index=0; index<iN; index++){
			
			dStr[idLen++] = sStr[index];
			
		}
		dStr[idLen] = '\0';
		
	return dStr;
}