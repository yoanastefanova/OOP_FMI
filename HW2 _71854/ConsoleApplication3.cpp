// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void shiftLetters(char word[], char decrypted[], int position)
{
	int counter = 0;

	for (int i = 0; word[i] != '\0'; i++)
	{

		if (word[i] >= 65 + position)// 65 - ascii code for A
		{
			decrypted[i] = word[i] - position;
		}

		else decrypted[i] = word[i] - position + 26;// z= b - 2 +26 => x = 66 + 24 => x=z;	

		counter++;//увеличават се позициите, за да преминава на следващата и да знаем къде да сложим детерминиращата нула
	}

	decrypted[counter] = '\0';
	cout << decrypted;
}


int main()
{
	char word[100];
	char ch;
	char decrypted[100];
	int position;
	cin >> word;
	cin >> position;
	
	shiftLetters(word, decrypted, position);

	return 0;
}

