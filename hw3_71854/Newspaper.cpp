#include <iostream>
#include <cstring>
#include "Newspaper.h"



Newspaper::Newspaper()
{
	for (int i = 0; i < 2; i++)
	{
		printDate[i] = 0;
	}

	adverts = 0;
}

Newspaper::Newspaper(double pricePerPage, int pages, int issue,const char *name,
	const char printDate[], int adverts) : PrintEdition (pricePerPage, pages, issue, name)
{
	setPrintDate(printDate);
	setAdverts(adverts);
}


Newspaper::~Newspaper()
{}


const double Newspaper::getSellPrice() const
{
	return getPrintPrice() + adverts*0.05;
}

void Newspaper::showInfo() 
{
	std::cout << "Price per page: " <<getPricePerPage() << ", Pages: " << getPages() << std::endl <<
		"Issue: " << getIssue() << ", Name: " << getName() << std::endl <<
		"Print Date: ";
	for (int i = 0; i < strlen(printDate); i++)

	{
		std::cout << printDate[i];
	}
	std::cout << ", Number of Adverts: " << adverts << ", Final price: " << getSellPrice();
}

void Newspaper::setPrintDate(const char _printDate[])
{
	int length = strlen(_printDate);
	for (int i = 0; i < length; i++)
	{
		printDate[i] = _printDate[i];
	}
}

void Newspaper::setAdverts(const int _adverts)
{
	adverts = _adverts;
}

//const char Newspaper::getPrintDate() const
//{
	//return printDate;
//}

const int Newspaper::getAdverts() const
{
	return adverts;
}
