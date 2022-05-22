/*
* Eli Hawk 563385586
* C++ Workshop
* Exercise 3 Question 2
* This is the main file (driver class) 
* for the Date class. This file takes in user
* input and creates Date objects and then performs
* 1 of 7 operations on them based on user input 
* and continues to do user-input operations until
* the user enters 0.
* The operations are: SET_DATE, PRE_INCREMENT, POST_INCREMENT, 
* ASSIGN, GREATER_THAN, LESS_THAN, EQUAL
*/


#include "Date.h"
#include <iostream>
using namespace std;

enum OPERATOR {
	EXIT, SET_DATE, PRE_INCREMENT, POST_INCREMENT, ASSIGN, GREATER_THAN,
	LESS_THAN, EQUAL
};

int main() {
	cout << "Enter a Date" << endl;
	int day = 0;
	int month = 0;
	int year = 0;
	char junk;

	Date d2;
	Date d3;
	Date d4;
	Date d5;


	cin >> day >> junk >> month >> junk >> year;
	Date d1(day, month, year);
	d1.print();
	cout << endl;

	bool done = false;
	int choice = 1;
	bool equal = false;
	bool lessThan = false;
	bool greaterThan = false;

	while (choice != EXIT) {
		cout << "Enter a code" << endl;
		cin >> choice;


		switch (choice) {
		case SET_DATE:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			d1.setDate(day, month, year);
			d1.print();
			cout << endl;
			break;
		case PRE_INCREMENT:
			d2 = ++d1;
			d2.print();
			cout << endl;
			d1.print();
			cout << endl;
			break;
		case POST_INCREMENT:
			d2 = d1++;
			d2.print();
			cout << endl;
			d1.print();
			cout << endl;
			break;
		case ASSIGN:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			d2.setDate(day, month, year);
			d1 = d2;
			d1.print();
			cout << endl;
			break;
		case GREATER_THAN:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			d3.setDate(day, month, year);
			greaterThan = d1 > d3;
			if (greaterThan) {
				d1.print();
				cout << ">";
				d3.print();
				cout << " : true" << endl;
			}
			else {
				d1.print();
				cout << ">";
				d3.print();
				cout << " : false" << endl;
			}
			break;
		case LESS_THAN:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			d4.setDate(day, month, year);
			lessThan = d1 < d4;
			if (lessThan) {
				d1.print();
				cout << "<";
				d4.print();
				cout << " : true" << endl;
			}
			else {
				d1.print();
				cout << ">";
				d4.print();
				cout << " : false" << endl;
			}
			break;
		case EQUAL:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			Date d5(day, month, year);
			equal = (d1 == d5);
			if (equal) {
				d1.print();
				cout << ">";
				d5.print();
				cout << " : true" << endl;
			}
			else {
				d1.print();
				cout << ">";
				d5.print();
				cout << " : false" << endl;
			}
			break;
		}
	}



}