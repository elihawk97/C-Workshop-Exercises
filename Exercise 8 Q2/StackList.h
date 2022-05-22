/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the header file for the StackList class.
* This class extends the abstract class Stack and 
* implements the stack methods using a Linked List.
*/

#include "List.h" 
#include "Stack.h"
#pragma once

class StackList : public Stack
{
public:
	StackList();
	StackList(const StackList&);
	// Stack operations
	void clear()override;
	bool isEmpty() const override;
	int pop()override;
	void push(int value) override;
	int top()override;
protected:
	// data fields
	List data;
};