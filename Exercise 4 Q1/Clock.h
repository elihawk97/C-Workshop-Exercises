/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 4 (only 1 question)
*
* Header file for the Clock class, which is a
* class that represents the time.
*/
#pragma once
#include <ostream>
#include <string>

using namespace std;

class Clock
{
public:
	Clock();
	Clock(int, int, int);

	void setHour(int);
	int getHour();

	void setMinute(int);
	int getMinute();

	void setSecond(int);
	int getSecond();


	int operator+=(int);
	friend ostream& operator<<(ostream& os, const Clock& time);
	friend istream& operator>>(istream& is, Clock& time);

private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};

