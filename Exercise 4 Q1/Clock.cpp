/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 4 (only 1 question)
*
* Implementation file for the Clock class methods.
* This file has constructors, setters and getters,
* as well as operator overloading methods, ect..
*/
#include "Clock.h"
#include <iostream>

using namespace std;

/// <summary>
/// Default constructor of the Clock class.
/// Defaults all values to 0.
/// </summary>
Clock::Clock() {
	hour = 0;
	minute = 0;
	second = 0;
}

/// <summary>
/// Constructor for clock that takes the all input values
/// to set the time.
/// Checks to that all times (hours/minutes/seconds) are 
/// nonnegative and hours are at most 23 and that seconds
/// and minutes are at most 59.
/// If any values are illegal the program will not set the 
/// instance and it will throw an error to be printed.
/// </summary>
/// <param name="_hour">hour to set clock to</param>
/// <param name="_minute">minute to set clock to</param>
/// <param name="_second">second to set clock to</param>
Clock::Clock(int _hour, int _minute, int _second) {
	
	//validation check for the second/hour/minute
	if (_second < 0) {
		throw("Invalid time - negative number of seconds.");
	}
	else if (_second > 59) {
		throw("Invalid time - more than 60 seconds.");
	}
	else if (_minute < 0) {
		throw("Invalid time - negative number of minutes.");
	}
	else if (_minute > 59) {
		throw("Invalid time - more than 60 minutes.");
	}
	else if (_hour < 0) {
		throw("Invalid time - negative number of hours.");
	}
	else if (_hour > 23) {
		throw("Invalid time - more than 24 hours.");
	}

	hour = _hour;
	minute = _minute;
	second = _second;
}

/// <summary>
/// Setter for the hour field, updates the hour.
/// Throws an error if the hour argument is illegal.
/// </summary>
/// <param name="_hour">int of number to update the hour field</param>
void Clock::setHour(int _hour) {
	// Validation check of the input for hour
	if (_hour < 0) {
		throw("Invalid time - negative number of hours.");
	}
	else if (_hour > 23) {
		throw("Invalid time - more than 24 hours.");
	}
	hour = _hour;
}

/// <summary>
/// Getter for the hour field.
/// </summary>
/// <returns>int of hour</returns>
int Clock::getHour() {
	return hour;
}

/// <summary>
/// Setter for the hour field, updates the minute.
/// Throws an error if the hour argument is illegal.
/// </summary>
/// <param name="_minute">int of number to update the minute field</param>
void Clock::setMinute(int _minute) {
	// Validation check of the input for minute
	if (_minute < 0) {
		throw("Invalid time - negative number of minutes.");
	}
	else if (_minute > 59) {
		throw("Invalid time - more than 60 minutes.");
	}
	minute = _minute;
}

/// <summary>
/// Getter for the minute field.
/// </summary>
/// <returns>int for minute</returns>
int Clock::getMinute() {
	return minute;
}

/// <summary>
/// Setter for the second field, updates the second.
/// Throws an error if the hour argument is illegal./// </summary>
/// <param name="_second">int of number to update the second field</param>
void Clock::setSecond(int _second) {
	// Validation check of the input for second.
	if (_second < 0) {
		throw("Invalid time - negative number of seconds.");
	}
	else if (_second > 59) {
		throw("Invalid time - more than 60 seconds.");
	}
	second = _second;
}

/// <summary>
/// Getter for the second field.
/// </summary>
/// <returns>int of second</returns>
int Clock::getSecond() {
	return second;
}


/// <summary>
/// += operator overload to adjust the time based on
/// how many seconds the time was increased by.
/// </summary>
/// <param name="_second">number seconds to increment 
/// the clock by</param>
/// <returns>the updated seconds</returns>
int Clock::operator+=(int _second) {
	if ((second + _second) < 59) {
		second = second + _second;
	}
	else if (minute < 59) {
		minute += 1;
		second = (second + _second) - 60;
	}
	else {
		if (hour < 23) {
			hour += 1;
		}
		else {
			hour = 0;
		}
		minute = 0;
		second = (second + _second) - 60;
	}
	return second; 
}

/// <summary>
/// Overloads the << cout operator to print out a Clock object
/// </summary>
/// <param name="os">output stream object</param>
/// <param name="time">Clock instance</param>
/// <returns>output stream</returns>
ostream& operator<<(ostream& os, const Clock& time) {
	string curTime = "";
	//set hour
	if (time.hour > 9) {
		curTime += to_string(time.hour) + ":";
	}
	else {
		curTime += "0";
		curTime += to_string(time.hour) + ":";
	}

	//set minute
	if (time.minute > 9) {
		curTime += to_string(time.minute) + ":";
	}
	else {
		curTime += "0";
		curTime += to_string(time.minute) + ":";
	}
	//set second
	if (time.second > 9) {
		curTime += to_string(time.second);
	}
	else {
		curTime += "0";
		curTime += to_string(time.second);
	}
	os << curTime;
	return os;

}

/// <summary>
/// Input stream >> operator overload
/// takes in user input to create Clock
/// instance
/// </summary>
/// <param name="is">input stream object</param>
/// <param name="time">instance of Clock to be constructed/filled</param>
/// <returns>input stream</returns>
istream& operator>>(istream& is, Clock& time) {
	int _hour = 0;
	int _minute = 0;
	int _second = 0;


	is >> _hour;
	if (cin.fail()) {
		throw("Wrong time format");
	}
	is >> _minute;
	if (cin.fail()) {
		throw("Wrong time format");
	}
	is >> _second;
	if (cin.fail()) {
		throw("Wrong time format");
	}
	time = Clock(_hour, _minute, _second);
	return is;
}
