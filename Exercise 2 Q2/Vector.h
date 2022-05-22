//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 1
//This is the header for file for the Vector class
//Vector is a class which represents an array and 
//with 3 fields the 1)the array itself 2) capacity
//of the array and 3) the size, which is the actual
//number of elements in the array
#pragma once
#include "Vector.h"
#include <cmath>
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector();
	Vector(int);
	Vector(const Vector&);
	int* copyArray(int *source);
	~Vector();

	int getCapacity();

	int getSize();

	void print();

	void assign(Vector other);

	bool isEqual(Vector);

	int& at(int index);

	int scalmul(Vector other);

	Vector strnewcat(Vector other);

	void clear();

	void delLast();

	void insert(int val);

private:
	int* data;
	int capacity;
	int size;
};

