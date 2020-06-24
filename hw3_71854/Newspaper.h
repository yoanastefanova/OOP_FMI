#pragma once
#include "PrintEdition.h"
#include <iostream>
#include <cstring>

const int DATE_SIZE = 25;

class Newspaper : public PrintEdition
{
private:
	char printDate[DATE_SIZE];
	int adverts;
public:
	Newspaper();
	Newspaper(double pricePerPage, int pages, int issue, const char *name, const char printDate[], int adverts);
	~Newspaper();

	const double getSellPrice() const;//override
	void showInfo();//override

	void setPrintDate(const char _printDate[]);
	void setAdverts(const int _adverts);

	//const char getPrintDate() const;
	const int getAdverts() const;

};

