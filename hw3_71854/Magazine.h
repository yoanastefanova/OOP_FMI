#pragma once
#include <iostream>
#include <cstring>
#include "PrintEdition.h"

class Magazine : public PrintEdition
{
private:
	bool hasPosters=0;
	int numberOfInterviews;
public:
	Magazine();
	Magazine(double pricePerPage, int pages, int issue, const char *name, bool hasPosters, int numberOfInterviews);
	~Magazine();

	const double getSellPrice() const;
	void showInfo();

	void setPosters(const bool _hasPosters);
	void setNumOfInterviews(const int _numOfInterviews);

	const int getNumberOfInterviews() const;
	const bool getPosters() const;
};

