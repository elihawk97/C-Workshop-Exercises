/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 1
*
* This is the driver class file to test the 
* function of the StackVector template class.
* 
* The program takes an input of a mathematical
* expression in infix form and calls the global
* methods infixToPostfix to change it postfix
* and calcPostfix to then calculate the expression.
*/

#include <string>
#include <iostream>
#include "StackVector.h"
using namespace std;

int main() {

	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}
