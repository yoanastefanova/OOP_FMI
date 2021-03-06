// triangles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

class Triangle
{

protected: 
	double side1;
	double side2;
	double side3;

public:

	void exists(double a, double b, double c)
	{
		if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
		{
			side1 = a;
			side2 = b;
			side3 = c;
		}

		else
		{
			cout << a << ", " << b << ", " << c << "cannot be sides of a triangle.";
		}
	}

	void input()
	{
		cout << "a= ";
		cin >> side1;
		cout << endl;
		cout << "b= ";
		cin >> side2;
		cout << endl;
		cout << "c= ";
		cin >> side3;
	}

	double perimeter() const
	{
		return side1 + side2 + side3;
	}	

	double area() const
	{
		double p = (side1 + side2 + side3) / 2;
		return sqrt(p * (p-side1) * (p-side2) * (p-side3));
	}
	void output() const
	{
		cout << side1 << " ";
		cout << side2 << " ";
		cout << side3;
	}
};

class RightTriangle : public Triangle
{
public:
	void exists(double a, double b, double c)
	{
		Triangle::exists(a, b, c);
		if  ((a*a - b * b - c * c != 0 ) ||
			(b*b - a * a - c * c != 0) ||
			(c*c - a * a - b * b != 0))
		{
			cout << "That is not a right triangle.";
		}
	}

	double area() const
	{
		if (side1*side1 - side2 * side2 - side3 * side3 != 0) return side2 * side3 / 2;
		else if (side2*side2 - side1 * side1 - side3 * side3 != 0) return side1 * side3 / 2;
		else if (side3*side3 - side1 * side1 - side2 * side2 != 0) return side2 * side3 / 2;
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	void exists(double a, double b, double c)
	{
		Triangle::exists(a, b, c);
	}
};


int main()
{
    return 0; 
}


