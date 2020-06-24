#include "PrintEdition.h"
//#include <iostream>
//#include <cstring>



void PrintEdition::destroy()
{
	delete[] name;
}

void PrintEdition::copy(const PrintEdition &other)
{
	name = nullptr;
	setName(other.name);
	setPricePerPage(other.pricePerPage);
	setPages(other.pages);
	setIssue(other.issue);
}

PrintEdition::PrintEdition()
{
	pricePerPage = 0;
	pages = 0;
	issue = 0;
	name = new char[1];
	strcpy_s(name, 1, "");
}

PrintEdition::PrintEdition(double _pricePerPage, int _pages, int _issue, const char *_name) :
	name(nullptr)
{
	setPricePerPage(_pricePerPage);
	setPages(_pages);
	setIssue(_issue);
	setName(_name);
}


PrintEdition::~PrintEdition()
{
	destroy();
}

PrintEdition & PrintEdition::operator=(const PrintEdition & other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;

}

void PrintEdition::setPricePerPage(const double _pricePerPage)
{
	pricePerPage = _pricePerPage;
}

void PrintEdition::setPages(const int _pages)
{
	pages = _pages;
}

void PrintEdition::setIssue(const int _issue)
{
	issue = _issue;
}

void PrintEdition::setName(const char * _name)
{
	if (!_name)
	{
		_name = "";
	}

	delete[] name;
	int length = strlen(_name) + 1;
	name = new char[length];
	strcpy_s(name, length, _name);
}

const double PrintEdition::getPrintPrice() const
{
	return pages*pricePerPage;
}

const double PrintEdition::getPricePerPage() const
{
	return pricePerPage;
}

const int PrintEdition::getPages() const
{
	return pages;
}

const int PrintEdition::getIssue() const
{
	return issue;
}

const char* PrintEdition::getName() const
{
	return name;
}
