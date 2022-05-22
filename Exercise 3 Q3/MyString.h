//Eli Hawk 563385586
//C++ Workshop
//Exercise 3 Question 3
//This is the header file for the MyString class
//this class is for Strings which stores a 
//char* (char pointer) and "len" the lenght of the 
//char array pointed to.
//This file has all function declarations including
//operator overloads for the logical and assignment 
//operators as well as a move assign and move constructor

#define _CRT_SECURE_NO_DEPRECATE
#include <cstring>
#include "iostream"
using namespace std;

class MyString {
	int len = 0;
	char* data;
public:
	MyString() : data(nullptr) {}
	MyString(const char* p);
	~MyString() { delete[] data; }
	// copy constructor
	MyString(const MyString& s);
	MyString(MyString&& source) noexcept;
	MyString& operator=(MyString&&);
	bool operator<(const MyString& source);
	bool operator<=(const MyString& source);
	bool operator>(const MyString& source);
	bool operator>=(const MyString& source);
	bool operator!=(const MyString& source);
	char& operator[](int i); //update
	const char& operator[](int i) const; //retrieve
	MyString insert(int, const char* str);
	void print();
	int getLength();
};