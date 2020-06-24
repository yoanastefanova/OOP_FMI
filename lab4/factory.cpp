#include "factory.h"

#include <iostream>

Factory::Factory() : size(0), capacity(10), workers(new Worker[capacity])
{}

Factory::Factory(const Factory& other)
{
	copy(other);
}

Factory& Factory::operator=(const Factory& rhs)
{
	if (this != &rhs)
	{
		del();
		copy(rhs);
	}
	return *this;
}

Factory::~Factory()
{
	del();
}


void Factory::AddWorker(const Worker& worker)
{
	//we've ran out of memory, allocate more
	if (size == capacity)
	{
		resize();
	}

	workers[size++] = worker;
}

void Factory::RemoveWorker(const char* name)
{
	size_t ind = -1;

	//find the worker
	for (size_t i = 0; i < size && ind == -1; i++)
	{
		if (strcmp(workers[i].GetName(), name) == 0)
		{
			ind = i;
		}
	}

	//remove the worker by overwriting them
	for (size_t i = ind; i < size - 1; i++)
	{
		workers[i] = workers[i + 1];
	}

	//if we removed
	if (ind != -1)
	{
		size--;
	}
}

void Factory::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		workers[i].print();
	}
}

void Factory::copy(const Factory& other)
{
	size = other.size;
	capacity = other.capacity;

	workers = new Worker[capacity];

	for (size_t i = 0; i < size; i++)
	{
		workers[i] = other.workers[i];
	}
}

void Factory::del()
{
	delete[] workers;
}

void Factory::resize()
{
	//remember what we talked about memory fragmentation [    |****|    |***| ]

	//used by facebook
	capacity *= 1.5;
	Worker* temp = new Worker[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = workers[i];
	}

	delete[] workers;
	workers = temp;
}
