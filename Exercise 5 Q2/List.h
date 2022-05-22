/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 5 Question 1
* Eli Hawk 563385586
* Workshop in C++
* Exercise 5 Question 1
* 
* This is the header file of the List class which
* also contains the global methods which perform
* operations of Lists sent to it as a parameter.
*/
#pragma once
#include <iostream>
using namespace std;

class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	}; //end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();
	friend istream& operator>>(istream&, List&);
	friend ostream& operator<<(ostream&, List&);

	// operations
	
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void remove();
	List& operator=(const List&);
	void insert(int);
	void remove(int);



protected:
	// data field
	Link* head;
};

//new methods for Question 2

List merge(const List&, const List&);
void makeSet(List& lst);
void reverse(List& lst);