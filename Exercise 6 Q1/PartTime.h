/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* PartTime class header file, which is a child class
* of Employee. This file defines the methods and
* constructors for this class.
*/
#pragma once
#include "Employee.h"

class PartTime : public Employee
{
public:
	PartTime();
	PartTime(string, int, int, int, float);
	PartTime(PartTime&);
	void salary();
	friend istream& operator>>(istream&, PartTime&);
	friend ostream& operator<<(ostream&, PartTime&);


private:
	int hoursOfWork;
	float payPerHour;
};

