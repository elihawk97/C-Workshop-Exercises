/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the driver class to test the QueueStack
* functions.
* 
* The program asks the user to input 5 numbers which
* are enqueued into the Queue. Then it enqueues some
* other numbers and dequeues and displays numbers from
* the queue.
* 
* This is the driver class given in the assignment.
*/

#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {
	Queue* Q;
	int num;
	Q = new QueueStack();
	cout << "enter 5 numbers: " << endl;
	try {
		for (int i = 0; i < 5; i++) {
			cin >> num;
			Q->enqueue(num);
		}
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first in queue is: " << Q->front() << endl;
	cout << "removing first 2 elements:" << endl;
	cout << Q->dequeue() << ' ';
	cout << Q->dequeue() << endl;
	cout << "first in queue is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	cout << "emptying out the queue: " << endl;
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	cout << endl;
	return 0;
}
