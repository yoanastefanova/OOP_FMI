#include "Magazine.h"



Magazine::Magazine()
{
	hasPosters = false;
	numberOfInterviews = 0;
}

Magazine::Magazine(double pricePerPage, int pages, int issue, const char *name, bool hasPosters, int numberOfInterviews) :
	PrintEdition(pricePerPage, pages, issue, name)
{
	setPosters(hasPosters);
	setNumOfInterviews(numberOfInterviews);
}


Magazine::~Magazine()
{}

const double Magazine::getSellPrice() const
{
	return getPrintPrice() + getNumberOfInterviews() + (hasPosters==true? 1.5 : 0);
}

void Magazine::showInfo()
{
	std::cout << "Price per page: " << getPricePerPage() << ", Pages: " << getPages() << std::endl <<
		"Issue: " << getIssue() << ", Name: " << getName() << std::endl <<
		"Posters: " << hasPosters << "Number of Interviews: " << numberOfInterviews << std::endl <<
		"Final price: " << getSellPrice();
}

void Magazine::setPosters(const bool _hasPosters)
{
	hasPosters = _hasPosters;
}

void Magazine::setNumOfInterviews(const int _numOfInterviews)
{
	numberOfInterviews = _numOfInterviews;
}

const int Magazine::getNumberOfInterviews() const
{
	return numberOfInterviews;
}

const bool Magazine::getPosters() const
{
	return hasPosters;
}
