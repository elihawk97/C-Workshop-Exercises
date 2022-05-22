/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* The base class Employee header file. 
* This file defines the methods and 
* constructors for this class.
*/
#pragma once
#include <string>
using namespace std;
#include <iostream>

class Employee
{
public:
	Employee();
	Employee(string, int, int);
	Employee(Employee&);	
	float salaryAfterBonus();

	friend istream& operator>>(istream&, Employee&);
	friend ostream& operator<<(ostream&, Employee&);

protected:
	string name;
	int id;
	int seniority;
	float pay;
};


