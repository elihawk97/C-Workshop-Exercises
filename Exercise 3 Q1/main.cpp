//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 1
//This is the main file for the Rational object
//this file takes in user input of rational
//numbers and performs the user chosen operations
//which utilize the methods and tests them
#include"Rational.h"
#include <iostream>
using namespace std;

enum OPERATOR {
	EXIT, ADD_PRE, ADD_POST, SUB_PRE, SUB_POST, ADD, SUB, MULT, DIV,
	GREATER, LESS_THAN, GREATER_OR_EQUAL, LESS_OR_EQUAL, EQUAL, NOT_EQUAL
};

void print(Rational rat1, Rational rat2, Rational  rat3, char op) {
	rat1.print();
	cout << " " << op << " ";
	rat2.print();
	cout << " = ";
	rat3.print();
	cout << endl;
}

void print(Rational rat1, Rational rat2, const char* op) {
	rat1.print();
	cout << " " << op << " ";
	rat2.print();
	cout << " ? ";
	cout << endl;
}

void printBefore(const char* op, Rational rat) {
	cout << "x = " << op << "y;" << endl;
	cout << "before operation y is: ";
	rat.print();
	cout << endl;
}

void printBefore(Rational rat, const char* op) {
	cout << "x = " << " y" << op << ";" << endl;
	cout << "before operation y is: ";
	rat.print();
	cout << endl;
}

void printAfter(Rational rat1, Rational rat2) {
	cout << "after operation x is: ";

	rat2.print();

	cout << endl << "y is: ";
	rat1.print();
	cout << endl;
}

int main()
{
	int numerator, denominator;
	char junk;
	int op;
	cout << "enter your choice:" << endl;
	cin >> op;
	Rational r2, r3;
	while (op != EXIT) {
		cout << "enter a rational number:" << endl;
		cin >> numerator >> junk >> denominator;
		Rational r1(numerator, denominator);
		if (op >= 5) {
			cout << "enter a rational number:" << endl;
			cin >> numerator >> junk >> denominator;
			r2.setNumerator(numerator);
			r2.setDenominator(denominator);
		}
		switch (op) {
		case ADD_PRE:
			printBefore("++", r1);
			r3 = ++r1;
			printAfter(r1, r3);
			break;
		case ADD_POST:
			printBefore(r1, "++");
			r3 = r1++;
			printAfter(r1, r3);
			break;
		case SUB_PRE:
			printBefore("--", r1);
			r3 = --r1;
			printAfter(r1, r3);
			break;
		case SUB_POST:
			printBefore(r1, "--");
			r3 = r1--;
			printAfter(r1, r3);
			break;
		case ADD:
			r3 = r1 + r2;
			print(r1, r2, r3, '+');
			break;
		case SUB:
			r3 = r1 - r2;
			print(r1, r2, r3, '-');
			break;
		case MULT:
			r3 = r1 * r2;
			print(r1, r2, r3, '*');
			break;
		case DIV:
			r3 = r1 / r2;
			print(r1, r2, r3, '/');
			break;
		case GREATER:
			print(r1, r2, ">");
			if (r1 > r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case LESS_THAN:
			print(r1, r2, "<");
			if (r1 < r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case GREATER_OR_EQUAL:
			print(r1, r2, ">=");
			if (r1 >= r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case LESS_OR_EQUAL:
			print(r1, r2, "<=");
			if (r1 <= r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case EQUAL:
			print(r1, r2, "==");
			if (r1 == r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		case NOT_EQUAL:
			print(r1, r2, "!=");
			if (r1 != r2)
				cout << "yes\n";
			else cout << "no\n";
			break;
		}
		cout << "enter your choice : " << endl;
		cin >> op;
	}

	return 0;
}

/*
Code Example:
enter your choice:
2
enter a rational number:
4/5
x =  y++;
before operation y is: 4/5

after operation x is: 4/5

y is: 9/5

enter your choice :
3
enter a rational number:
6/9
x = --y;
before operation y is: 6/9

after operation x is: -3/9

y is: -3/9

enter your choice :
5
enter a rational number:
3/8
enter a rational number:
4/9
3/8
 + 4/9
 = 59/72

enter your choice :
5
enter a rational number:
345/324444445
enter a rational number:
345/899
345/324444445
 + 345/899
 = 264493984/382220073

enter your choice :


4
enter a rational number:
23/54
x =  y--;
before operation y is: 23/54

after operation x is: 23/54

y is: -31/54

enter your choice :
0
*/
