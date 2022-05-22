/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the implementation file for the StackList class.
* 
* This is the file provided in the course workbook and was 
* instructed to use in this assignment.
*/

#include "StackList.h"

StackList::StackList() :data()
{
		// create and initialize a Stack based on Lists
}
StackList::StackList(const StackList& lst)
	: data(lst.data)
{ /* copy constructor*/
}
void StackList::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}
bool StackList::isEmpty() const
{ // return true if Stack is empty
	return data.isEmpty();
}
int StackList::pop()
{
	// return and remove the intopmost element in the Stack
	// get first element in List
	int result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}
void StackList::push(int val)
{
	// push new value onto Stack
	data.add(val);
}
int StackList::top()
{
	return data.firstElement();
}