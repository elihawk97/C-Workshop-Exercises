/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the implementation file for the QueueStack class.
* This file implements the queue's methods using a stack...and
* a helper stack. ;)
*/

#include "QueueStack.h"

/// <summary>
/// Default constructor for the QueueStack class.
/// Initializes data, a stack, which is the only member
/// field of the class, to allocate memory for a new
/// stack.
/// </summary>
QueueStack::QueueStack() {
	data = new StackList();
}

/// <summary>
/// Method to clear all data in the queue.
/// It calls the pop method of data to clear
/// the stack which holds the queue's data.
/// </summary>
void QueueStack::clear() {
	// Special insert if the QueueStack is empty
	if (data->isEmpty()) {
		return;
	}

	while (data->isEmpty() != true) {
		data->pop();
	}
}

/// <summary>
/// Method to remove the first element that was input
/// into the queue. Since the enqueue function always 
/// makes sure that the first element input is on top 
/// of the stack, here it just calls the pop method on
/// the "data" stack, which holds the queues data and 
/// returns it.
/// </summary>
/// <returns>The first element in the queue.</returns>
int QueueStack::dequeue() {
	if (data->isEmpty() == true) {
		return 0;
	}

	return data->pop();
}


/// <summary>
/// Method to insert a value to the end of the queue.
/// This method first dumps the contents of the stack
/// "data" into a helper stack, then pushes the new value 
/// onto the "data" stack. Then the elements in the helper
/// stack are dumped back onto the "data" stack, ensuring
/// the new element is at the bottom of the stack.
/// 
/// Special case: If queue is empty, then it just inserts the
///               element directly into the queue using the
///				  stack functionality of "data."
/// </summary>
/// <param name="value">The value to be inserted</param>
void QueueStack::enqueue(int value) {
	// Special insert if the QueueStack is empty
	if (data->isEmpty()) {
		data->push(value);
		return;
	}

	// All other cases
	StackList* holder = new StackList();
	while (data->isEmpty() != true) {
		holder->push(data->pop());
	}

	data->push(value);

	while (holder->isEmpty() != true) {
		data->push(holder->pop());
	}

	delete holder;
}


/// <summary>
/// Method to return the first element that was input
/// into the queue. Since the enqueue function always 
/// makes sure that the first element input is on top 
/// of the stack, here it just calls the top method on
/// the "data" stack, which holds the queues data and 
/// returns it.
/// </summary>
/// <returns>The first element in the queue.</returns>
int QueueStack::front() {
	// Special insert if the QueueStack is empty
	if (data->isEmpty()) {
		return 0;
	}

	return data->top();
}

/// <summary>
/// Check if the queue is empty by calling the
/// isEmpty method of the stack "data" which
/// return the boolean of whether the stack is
/// empty or not. 
/// </summary>
/// <returns>Boolean, true if the queue is empty.</returns>
bool QueueStack::isEmpty() const {
	return data->isEmpty();
}