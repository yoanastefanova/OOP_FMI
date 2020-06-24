//alternative way to guard
//#pragma once

//guards
#ifndef WORKER_H
#define WORKER_H

class Worker
{
public:
	//canonical
	Worker();
	Worker(const char* nam, const char* pos, double sal);
	Worker(const Worker& other);
	Worker& operator=(const Worker& rhs);
	~Worker();

	//mutators
	//explicit inline
	inline void SetName(const char* nam);
	void SetPosition(const char* pos);
	void SetSalary(double sal);

	//selectors
	const char* GetName() const;
	const char* GetPosition() const;
	double GetSalary() const;

	void print() const;

private:
	//helpers
	void copy(const Worker& other);
	//implicit inline
	void del()
	{
		delete[] name;
		delete[] position;
	}

	//data
	char* name = nullptr;
	char* position = nullptr;
	double salary = 0;
};

#endif // !WORKER_H
