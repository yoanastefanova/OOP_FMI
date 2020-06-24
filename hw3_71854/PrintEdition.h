#pragma once
#include <iostream>
#include <cstring>

class PrintEdition
{
private:
	double pricePerPage;
	int pages;
	int issue;
	char* name;

	void destroy();
	void copy(const PrintEdition &other);

public:
	PrintEdition();
	PrintEdition(double _pricePerPage, int _pages, int _issue, const char *_name);
	virtual  ~PrintEdition();

	PrintEdition &operator=(const PrintEdition &other);

	void setPricePerPage(const double _pricePerPage);
	void setPages(const int _pages);
	void setIssue(const int _issue);
	void setName(const char *_name);

	const double getPrintPrice() const;

	virtual const double getSellPrice() const = 0;
	virtual void showInfo() = 0;

	

	const double getPricePerPage() const;
	const int getPages() const;
	const int getIssue() const;
	const char *getName() const;
	
};

