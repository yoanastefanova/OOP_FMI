// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


const int SIZE = 100;



void transformMatrix (int size, int arr[][SIZE])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (i == size - j - 1)
			{
				arr[i][j] = 1;
			}

			else if (i + j < size)
			{
				arr[i][j] = 0;
			}

			else if (i + j >= size)
			{
				arr[i][j] = 2;
			}
		}
	}

}

void OutputMatrix(int size, int arr[][SIZE])
{
	transformMatrix(size, arr);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{
	int matrix[SIZE][SIZE];
	int size;
	cin >> size;

	OutputMatrix(size, matrix);


	return 0;
}


