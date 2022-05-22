/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the header file for the QueueStack class.
* This class implements a queue using a stack...and 
* a helper stack ;)
* 
* I know this sounds weird, since stacks and queues 
* are opposite, but this was the assingment, and hey,
* it's pretty cool that it works, and it's not even that
* complicated :)
*/

#pragma once
#include "StackList.h"
#include "Queue.h"

class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};
