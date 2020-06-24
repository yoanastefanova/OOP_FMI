#include <iostream>

#include "worker.h"
#include "factory.h"

using namespace std;

int main()
{
	Worker	p("Pesho", "Engineer", 2000);
	p.print();

	cout << endl;

	Factory	fact;
	fact.AddWorker(p);
	fact.AddWorker(Worker("Gosho", "Cleaner", 1000));
	fact.print();

	cout << endl;

	fact.RemoveWorker("Pesho");
	fact.print();

	cin.get();
	return 0;
}
