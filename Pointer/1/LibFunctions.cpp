#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
char* mycpy(char*, char*, int);
//void strncmp(string, string, int);
//void strncat()
int main(){
	
	char str1[10],str2[10];
	
	cout << "Enter First String:";
	cin >> str1;

	cout << "Enter Second String:";
	cin >> str2;

	int iLen1,iLen2;
	iLen1 = strlen(str1);
	iLen2 = strlen(str2);

	int iN;
	cout << "Enter Range:";
	cin >> iN;

	string ch;
	ch = mycpy(ch, str1, iN);
}


char* mycpy(char* dest, char* src, int n)
           {
               int i;

               for (i = 0; i < n && src[i] != '\0'; i++)
                   dest[i] = src[i];
               for ( ; i < n; i++)
                   dest[i] = '\0';

               return dest;
           }
