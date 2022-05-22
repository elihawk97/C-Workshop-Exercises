/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 2
*
* This is the header file for the RoundList class
* which represents linked lists.
*/

#include "List.h"


class RoundList : public List
{
public:
	RoundList();
	int search(int) const;
	RoundList& operator=(const RoundList& source);
	RoundList(const RoundList& source);
	void addToEnd(int);
	friend ostream& operator<<(ostream&, RoundList&);
	friend istream& operator>>(istream&, RoundList&);

	void add(int val);

	int firstElement() const;

	void removeFirst();

	void clear();

	void insert(int key);

	void remove(int key);

};

