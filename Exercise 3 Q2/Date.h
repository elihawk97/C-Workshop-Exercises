/*
* Eli Hawk 563385586
* C++ Workshop 
* Exercise 3 Question 2
* This is the header file for the Date class
* which declares the class and its fields
* and methods.
*/

#pragma once
#include <iostream>
using namespace std;


class Date
{
public:
	Date();
	Date(int aDay);
	Date(int aDay, int aMonth);
	Date(int aDay, int aMonth, int aYear);
	Date(const Date& source);
	void setDate(int aDay, int aMonth, int aYear);
	Date operator++();
	Date operator++(int dummy);
	Date& incrementDateChecker(Date& aDate);
	Date& operator=(const Date& source);
	Date& operator=(const Date&& source);
	bool operator>(const Date& other);
	bool operator<(const Date& other);
	bool operator==(const Date& other) const;
	void print();

private:
	int day;
	int month;
	int year;
};

bool checkYear(int);
bool checkMonth(int);
bool checkDay(int);