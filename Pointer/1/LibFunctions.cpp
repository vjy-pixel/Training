#include<iostream>
#include<bits/stdc++.h>

#define MAX_STR_LENGTH 1000


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
		
		std::cout << "1. Copy\n2. Compare\n3. Concate\n4.Exit\n";
		std::cout << "Enter Your Choice:";
		std::cin >> iChoice;
	
	switch(iChoice){
		
		case 1:
			std::cout << "================== Copy ===================\n";
			
			std::cout << "Enter String to Copy:";
			scanf(" %[^\n]s",str1);
	
			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered string or not.
			***********************************************************************************/
			while(1){
				
				std::cout << "Enter Range till u wanna Copy:";
				std::cin >> iN;
				if(iN < strlen(str1))
					break;
				else{
					std::cout << "Please Try Again!!!\n";
					std::cout << "As entered value is greater than length of entered string\n";
					continue;
				}
			}

			/************ cpystrn() call *************/
			cRes = cpystrn(cRes,str1,iN);
			
			std::cout << "\nString Copied!!!\n\n";
			std::cout << cRes << std::endl << std::endl;
			
			std::cout << "===========================================\n";

			free(cRes);
			free(str1);
			free(str2);
			
			break;
		
		case 2:
			std::cout << "------------------- Compare -----------------\n";

			std::cout << "Enter String from which to Compare:";
			scanf(" %[^\n]s",str1);

			std::cout << "Enter String to which to Compare?:";
			scanf(" %[^\n]s",str2);

			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered strings or not.
			***********************************************************************************/		
			while(1){
				
				std::cout << "\nEnter Range till u wanna Copy:";
				std::cin >> iN;
				if(iN < strlen(str1) && iN < strlen(str2))
					break;
				else{
					std::cout << "Please Try Again!!!\n";
					std::cout << "As entered value is greater than length of entered strings\n";
					continue;
				}
			}

			/************ cmpstrn() call *************/
			iRes = cmpstrn(str1, str2, iN);		

			if(iRes == 0)
				std::cout << "str1 is same as str2 till location " << iN << std::endl;

			else if(iRes > 0)
				std::cout << "str1 is greater than str2 till location " << iN << std::endl;				

			else
				std::cout << "str1 is less than str2 till location " << iN << std::endl;

			std::cout << "-----------------------------------------------\n";
			free(str1);
			free(str2);
			break;

		case 3:
			
			std::cout << "++++++++++++++++++ Concate +++++++++++++++++\n";
			std::cout << "Enter String from which to Concate:";
			scanf(" %[^\n]s",str1);

			std::cout << "Enter String to which to Concate?:";
			scanf(" %[^\n]s",str2);
			
			/********************************************************************************** 
				* A loop to check whether entered value of at most to be accessed characeters
				*
				* is in range of entered string or not.
			***********************************************************************************/
			while(1){
				
				std::cout << "\nEnter Range till u wanna Copy:";
				std::cin >> iN;
				if(iN < strlen(str1))
					break;
				else{
					std::cout << "Please Try Again!!!\n";
					std::cout << "As entered value is greater than length of any of entered string\n";
					continue;
				}
			}

			

			cRes = (char*) malloc(sizeof(char)*(iN));
			
			/************ catstrn() call *************/
			cRes = catstrn(str2,str1,iN);
			
			std::cout << "String Concated!!!\n";
			std::cout << cRes << std::endl;
			std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
			
			free(cRes);
			free(str1);
			free(str2);
			
			break;
		
		case 4:
			exit(0);
				
		default:
			std::cout << "Please make valid Choice!!!\n";
	}
	}	
	return 0;	
}

char* cpystrn(char* cRes, char* str, int iN){
	
	cRes = (char*) malloc(sizeof(char)*iN);
	if(NULL == cRes)
		std::cout << "Unable to get memory for Dest. String!!!\n";
	else{
		for(int index=0; index<iN; index++){
			//std::cout << "String Char:" << str[index] << std::endl;
			cRes[index] = str[index];
			//std::cout << "String Char:" << cRes[index] << std::endl;
		}
		cRes[iN] = '\0';
		std::cout << strlen(cRes) << std::endl;
	}
	//std::cout << cRes << std::endl;
	return cRes;
}


int cmpstrn(char* sStr, char* dStr, int iN){
	int iLen1 = strlen(sStr);
	int iLen2 = strlen(dStr);

	std::cout << "Length of String 1:" << iLen1 << std::endl;
	std::cout << "Length of String 2:" << iLen2 << std::endl;

	
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