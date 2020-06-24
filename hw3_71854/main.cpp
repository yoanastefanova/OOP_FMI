#include <iostream>
#include "PrintEdition.h"
#include "Newspaper.h"
#include "Magazine.h"
#include "Book.h"

int main()
{
	PrintEdition* np1;
	/*
	PrintEdition* np2;
	PrintEdition* mag1;
	PrintEdition* mag2;
	PrintEdition* b1;
	PrintEdition* b2;
	*/

	np1 = new Newspaper (0.5, 20, 300, "blah", "20.05.2019", 3);
	np1->showInfo();
	delete np1;
	//np2 = new Newspaper(0.25, 35, 275, "blaah", "27.07.2019", 15);
	//delete np2;
	/*
	mag1 = new Magazine(1.2, 40, 300, "blaa", true, 5);
	mag2 = new Magazine(1.5, 55, 530, "blaaaa", false, 8);

	b1 = new Book(0.7, 270, 1500, "bbb", "aaa", true, 1999);


	np1->showInfo();
		
	delete np1;
	*/

	return 0;
}