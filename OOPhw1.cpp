// OOPhw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;


struct Point//горната лява точка на правоъгълника
{
	double x;
	double y;
};

struct Rectangle
{
	Point point;
	double height;
	double width;
};

void inputRectangle(Rectangle &other)
{
	cout << "x= ";
	cin >> other.point.x;
	cout<< endl;
	cout << "y= ";
	cin >> other.point.y;
	cout << endl;
	cout << "height= ";
	cin >> other.height;
	cout << endl;
	cout << "width= ";
	cin >> other.width;
	cout << endl;
}

void topAndBottomPoints(const Rectangle &rect, Point &bottom)
{
	bottom.x = rect.point.x + rect.width;
	bottom.y = rect.point.y - rect.height;
}

bool intersectionArea(const Point &top1, const Point &bot1, const Point &top2, const Point &bot2)
{
	if (top1.x > bot2.x || top2.x > bot1.x)
	{
		return false;
	}

	if (top1.y < bot2.y || top2.y < bot2.y)
	{
		return false;
	}

	return true;
}

double intersectionArea(const Rectangle &rect1, const Rectangle &rect2)
{
	Point bot1;
	Point bot2;

	topAndBottomPoints(rect1, bot1);
	topAndBottomPoints(rect2, bot2);

	if (intersectionArea(rect1.point, bot1, rect2.point, bot2))
	{
		return (fmin(bot1.x, bot2.x) - fmax(rect1.point.x, rect2.point.x)*
			(fmin(rect1.point.y, rect2.point.y) - fmax(bot1.y, bot2.y)));

	}

}

int main()
{
	Rectangle rectangle;
	inputRectangle(rectangle);

    return 0; 
}

