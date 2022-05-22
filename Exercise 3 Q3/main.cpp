//Eli Hawk 563385586
//C++ Workshop
//Exercise 3 Question 3
//This is the main file (driver class) 
//for the MyString class to test the 
//methods and implementations.

#include "MyString.h"

int main() {

	//create and intialize 2 strings
	char input1[64];
	char input2[64];
	int index;

	cin >> input1;
	cin >> input2;
	cin >> index;

	MyString a(input1);
	MyString b(input2);

	//logical function overload test
	if (a < b) {
		cout << "a<b" << endl;
	}
	if (a > b) {
		cout << "a>b" << endl;
	}
	if (!(a != b)) {
		cout << "a=b" << endl;
	}

	//insert function test

	MyString concated;
	concated = (b.insert(index, input1));
	concated.print();


	//operator[] test
	char c = '0';
	int i = -1;

	cin >> c;

	//Only call the update subscript[] operator if a valid
	//index within the string is entered
	if (!(cin >> i) or i < 0 or i >= concated.getLength()) {
		concated[-1];
	}
	else {
		concated[i] = c;
		concated.print();
	}


}

/*
Code Example:

theehe
telihawk
4
a>b
move ctor
move assign
telitheehehawk
r
5
telitreehehawk

*/