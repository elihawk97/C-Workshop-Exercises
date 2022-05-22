/*
* Eli Hawk 563385586
* C++ Workshop
* Exercise 3 Question 2
* This is the method implementation file of the 
* Date class, which includes operator overloads
* and other operations to be performed on 
* Date objects.
*/

#include "Date.h"

/// <summary>
/// Default constructor of the Date class
/// </summary>
Date::Date() {
	day = 1;
	month = 1;
	year = 1920;
}

/// <summary>
/// Constuctor of the Date class that only accepts a day
/// and the month and year are default values
/// </summary>
/// <param name="aDay">day of date Object</param>
Date::Date(int aDay) {
	if (checkDay(aDay)) {
		day = aDay;
	}
	else {
		day = 1;
		cout << "ERROR day" << "\n";
	}
	month = 1;
	year = 1920;
}

/// <summary>
/// Constuctor of the Date class that only accepts a day and month
/// the year is a default value
/// </summary>
/// <param name="aDay">day of date Object</param>
/// <param name="aMonth">month of date Object</param>
Date::Date(int aDay, int aMonth) {
	if (checkDay(aDay)) {
		day = aDay;
	}
	else {
		day = 1;
		cout << "ERROR day" << "\n";
	}
	if (checkMonth(aMonth)) {
		month = aMonth;
	}
	else {
		month = 1;
		cout << "ERROR day" << "\n";
	}
	year = 1920;
}

/// <summary>
/// Constuctor that accepts all 3 values for a Date object
/// Day/Month/Year. If any of the values are "illegal" the 
/// Date will default to 1/1/1920.
/// </summary>
/// <param name="aDay">day of Date object</param>
/// <param name="aMonth">month of Date object</param>
/// <param name="aYear">year of date Object</param>
Date::Date(int aDay, int aMonth, int aYear) {
	if (checkDay(aDay)) {
		day = aDay;
	}
	else {
		day = 1;
		cout << "ERROR day" << "\n";
	}
	if (checkMonth(aMonth)) {
		month = aMonth;
	}
	else {
		month = 1;
		cout << "ERROR month" << "\n";
	}
	if (checkYear(aYear)) {
		year = aYear;
	}
	else {
		year = 1920;
		cout << "ERROR year" << "\n";
	}
}

//Valid Date checkers for Day, Month, Year

/// <summary>
/// Checks that the day is a number between 
/// 1 and 30
/// </summary>
/// <param name="aDay">day to be checked</param>
/// <returns>bool: true if day is valid</returns>
bool checkDay(int aDay) {
	return (0 < aDay and aDay < 31);
}

/// <summary>
/// Checks that the month is a number between 
/// 1 and 12
/// </summary>
/// <param name="aMonth">month to be checked</param>
/// <returns>bool: true if month is valid</returns>
bool checkMonth(int aMonth) {
	return (0 < aMonth and aMonth < 13);
}

/// <summary>
/// Checks that the year is or is after 1920
/// </summary>
/// <param name="aYear">year to be checked</param>
/// <returns>bool: true if year is valid</returns>
bool checkYear(int aYear) {
	return (aYear >= 1920);
}

/// <summary>
/// copy constructor
/// </summary>
/// <param name="source">Date object to be copied</param>
Date::Date(const Date& source) {
	day = source.day;
	month = source.month;
	year = source.year;
}

/// <summary>
/// setDate updates the date object with user inputed fields
/// </summary>
/// <param name="aDay">the new day</param>
/// <param name="aMonth">the new month</param>
/// <param name="aYear">the new year</param>
void Date::setDate(int aDay, int aMonth, int aYear) {
	if (checkDay(aDay) and checkMonth(aMonth) and checkYear(aYear)) {
		day = aDay;
		month = aMonth;
		year = aYear;

	}
	return;
}

//operator overload methods

/// <summary>
/// o++ operator overload, to postincrement the date
/// postfix operator has the dummy
/// </summary>
/// <param name="dummy"></param>
/// <returns></returns>
Date Date::operator++(int dummy) { //o++
	Date original(this->day, this->month, this->year);
	Date temp = (incrementDateChecker(*this));
	return original;
}

/// <summary>
/// ++o operator overload, to preincrement the date
/// </summary>
/// <returns></returns>
Date Date::operator++() {
	Date original = incrementDateChecker(*this);
	return original;
}

/// <summary>
/// Increments the date by 1 day and adjusts
/// the months and years accordingly when
/// nesiccary.
/// </summary>
/// <param name="aDate">Date object to be incremented</param>
/// <returns>pointer to the incremented Date instance</returns>
Date& Date::incrementDateChecker(Date& aDate) {
	if (aDate.day < 30) {
		aDate.day += 1;
	}
	else {
		aDate.day = 1;
		if (aDate.month < 12) {
			aDate.month += 1;
		}
		else {
			aDate.month = 1;
			aDate.year += 1;
		}
	}
	return aDate;
}

/// <summary>
/// Copy assignment operator
/// </summary>
/// <param name="source">Date instence to be copied</param>
/// <returns>pointer to the Date object changed</returns>
Date& Date::operator=(const Date& source) {
	if (this == &source) {
		return *this;
	}
	day = source.day;
	month = source.month;
	year = source.year;
	return *this;
}


/// <summary>
/// mover assignment operator
/// </summary>
/// <param name="source">Date instance to be "stolen" 
/// by the object that called the method</param>
/// <returns>pointer to the Date object changed</returns>
Date& Date::operator=(const Date&& source) {
	if (this == &source) {
		return *this;
	}
	day = source.day;
	month = source.month;
	year = source.year;
	return *this;
}


/// <summary>
/// ">" greater than operator overload for the Date class
/// </summary>
/// <param name="other">Date object to compare with the 
/// instance that called the method</param>
/// <returns>bool: true if right operand is greater than
/// the left operand</returns>
bool Date::operator>(const Date& other) {
	Date temp(this->day, this->month, this->year);
	if (temp.year > other.year) {
		return true;
	}
	if (temp.year == other.year and temp.month > other.month) {
		return true;
	}
	if (temp.year == other.year and temp.month == other.month and temp.day > other.day) {
		return true;
	}
	return false;
}

/// <summary>
/// "<" less than operator overload for the Date class
/// </summary>
/// <param name="other">Date object to compare with the 
/// instance that called the method</param>
/// <returns>bool: true if right operand is less than
/// the left operand</returns>
bool Date::operator<(const Date& other) {
	if (year < other.year) {
		return true;
	}
	if (year == other.year and month < other.month) {
		return true;
	}
	if (year == other.year and month == other.month and day < other.day) {
		return true;
	}
	return false;
}

/// <summary>
/// overloading the == opeator, to check if 2 dates are the same
/// </summary>
/// <param name="other">right opeand to compare with the instance
/// that called the method</param>
/// <returns>bool: true if they are equal dates</returns>
bool Date::operator==(const Date& other) const {
	return(year == other.year and month == other.month and day == other.day);
}


/// <summary>
/// Print function for the Date object.
/// </summary>
void Date::print() {
	cout << day << "/" << month << "/" << year;
}
