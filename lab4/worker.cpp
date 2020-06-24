#include "worker.h"

#include <iostream>

Worker::Worker() : salary(0)
{
	//reuse mutators
	SetName("");
	SetPosition("");
}

Worker::Worker(const char* nam, const char* pos, double sal)
{
	//reuse mutators
	SetName(nam);

	SetPosition(pos);

	SetSalary(sal);
}

Worker::Worker(const Worker& other)
{
	copy(other);
}

Worker& Worker::operator=(const Worker& rhs)
{
	if (this != &rhs)
	{
		del();
		copy(rhs);
	}
	return *this;
}

Worker::~Worker()
{
	del();
}


void Worker::SetName(const char* nam)
{
	if (nam)
	{
		name = new char[strlen(nam) + 1];
		strcpy_s(name, strlen(nam) + 1, nam);
	}
	else
	{
		name = new char[1];
		name[0] = '\0';
	}
}

void Worker::SetPosition(const char* pos)
{
	if (pos)
	{
		position = new char[strlen(pos) + 1];
		strcpy_s(position, strlen(pos) + 1, pos);
	}
	else
	{
		position = new char[1];
		position[0] = '\0';
	}
}

void Worker::SetSalary(double sal)
{
	if (sal > 0)
	{
		salary = sal;
	}
	else
	{
		salary = -sal;
	}
}


const char* Worker::GetName() const
{
	return name;
}

const char* Worker::GetPosition() const
{
	return position;
}

double Worker::GetSalary() const
{
	return salary;
}


void Worker::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Position: " << position << std::endl;
	std::cout << "Salary: " << salary << std::endl;
}


void Worker::copy(const Worker& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	position = new char[strlen(other.position) + 1];
	strcpy_s(position, strlen(other.position) + 1, other.position);

	salary = other.salary;
}

//void Worker::del()
//{
//	delete[] name;
//	delete[] position;
//}