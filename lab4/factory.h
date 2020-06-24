#ifndef FACTORY_H
#define FACTORY_H

#include "worker.h"

class Factory
{
public:
	//canonical
	Factory();
	Factory(const Factory& other);
	Factory& operator=(const Factory& rhs);
	~Factory();

	//operations
	void AddWorker(const Worker& worker);
	void RemoveWorker(const char* name);

	void print() const;

private:
	void copy(const Factory& other);
	void del();

	//we may run out of space
	void resize();

	size_t size		= 0;
	size_t capacity	= 0;

	Worker* workers	= nullptr;
};


#endif // !FACTORY_H
