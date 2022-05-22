/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the header file for the stack class.
* This file contains the basic method
* declaratons for a stack.
* This is an abstract class.
*/

#pragma once

class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual int pop() = 0;
	virtual void push(int value) = 0;
	virtual int top() = 0;
};
