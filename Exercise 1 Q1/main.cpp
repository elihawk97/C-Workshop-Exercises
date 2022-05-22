//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This is the main file for the Rational class, which
//allows the user to enter in rational numbers and
//then it used the Rational obeject's methods to add
// numbers together and reduce fractions

#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num1, num2, num3;
	char junk;

	cout << "part 1.  set/get" << endl;
	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat1;
	rat1.setNumerator(num1);
	rat1.setDenominator(num2);
	cout << "numerator: " << rat1.getNumerator() << endl;
	cout << "denominator: " << rat1.getDenominator() << endl;

	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat2;
	rat2.setNumerator(num1);
	rat2.setDenominator(num2);
	rat2.print();
	cout << endl << endl;

	cout << "part 2.  equals" << endl;
	if (rat1.equal(rat2))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;
	cout << endl << endl;

	cout << "part 3. add" << endl;
	Rational ans = rat1.add(rat2);
	rat1.print();
	cout << " + ";
	rat2.print();
	cout << " = ";
	ans.print();
	cout << endl;

	return 0;
}

/*
Example of program working
part 1.3.  set/get
enter a rational number:
3
/
5
numerator: 3
denominator: 5
enter a rational number:
4
/
10
4/10

part 2.  equals
The two numbers are different


part 3. add
3/5 + 4/10 = 1/1
*/