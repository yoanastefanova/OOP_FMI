// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;


void NumOfDigits(char str[])
{
	int counter = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] <= 57) counter++;
	}
	
	cout << counter;
}


int main()
{
	char str[100];
	cin.getline(str, 100);

	NumOfDigits(str);


   return 0; 
}


