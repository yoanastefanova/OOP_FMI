#include "Book.h"



void Book::destroy()
{
	delete[] authorName;
}

void Book::copy(const Book &other) 
{
	authorName = nullptr;
	setAuthorName(other.authorName);
	setHardcovers(other.hasHardcovers);
	setYear(other.year);
}

Book::Book()
{
	authorName = new char[1];
	strcpy_s(authorName, 1, "");
	hasHardcovers = false;
	year = 0;
}

Book::Book(double pricePerPage, int pages, int issue, const char * name, const char * authorName, bool hasHardcovers, int year) :
	PrintEdition(pricePerPage, pages, issue, name)
{
	setAuthorName(authorName);
	setHardcovers(hasHardcovers);
	setYear(year);
}

Book::Book(const Book &other) : PrintEdition(other)
{
	copy(other);
}

Book & Book::operator=(const Book & other)
{
	if (this != &other)
	{
		PrintEdition::operator=(other);
		destroy();
		copy(other);
	}

	return *this;
}



Book::~Book()
{
	destroy();
}

void Book::setAuthorName(const char * _authorName)
{
	if (!_authorName)
	{
		_authorName = "";
	}

	delete[] authorName;
	int length = strlen(_authorName) + 1;
	authorName = new char[length];
	strcpy_s(authorName, length, _authorName);
}

void Book::setHardcovers(const bool _has)
{
	hasHardcovers = _has;
}

void Book::setYear(const int _year)
{
	year = _year;
}

const double Book::getSellPrice() const
{
	return getPrintPrice() + (hasHardcovers==true ? 5 : 2.5);
}

void Book::showInfo()
{
	std::cout << "Price per page: " << getPricePerPage() << ", Pages: " << getPages() << std::endl <<
		"Issue: " << getIssue() << ", Name: " << getName() << std::endl <<
		"Author Name: " << authorName << "Hardcovers: " << hasHardcovers << std::endl <<
		"Year: " << year << ", Final price: " << getSellPrice();
}

const char * Book::getAuthorName() const
{
	return authorName;
}

const bool Book::getHardcovers() const
{
	return hasHardcovers;
}

const int Book::getYear() const
{
	return year;
}
