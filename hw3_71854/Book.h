#pragma once
#include "PrintEdition.h"
#include <iostream>
#include <cstring>

class Book : public PrintEdition
{
private:
	char *authorName;
	bool hasHardcovers=0;
	int year;

	void destroy();
	void copy(const Book &other);

public:
	Book();
	Book(double pricePerPage, int pages, int issue, const char *name, const char* authorName, bool hasHardcovers, int year);
	Book(const Book &other);
	Book &operator=(const Book &other);
	~Book();

	void setAuthorName(const char *_authorName);
	void setHardcovers(const bool _has);
	void setYear(const int _year);

	const double getSellPrice() const;
	void showInfo();

	const char *getAuthorName() const;
	const bool getHardcovers() const;
	const int getYear() const;
};

