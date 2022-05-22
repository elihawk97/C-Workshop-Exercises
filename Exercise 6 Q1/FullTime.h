/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* FullTime class header file, which is a child class
* of Employee. This file defines the methods and
* constructors for this class.
*/

#pragma once
#include "Employee.h"

class FullTime : public Employee
{
public:
	FullTime();
	FullTime(string , int, int, int);
	void salary();
	friend istream& operator>>(istream&, FullTime&);
	friend ostream& operator<<(ostream&, FullTime&);

private:
	int salaryPerYear;
};