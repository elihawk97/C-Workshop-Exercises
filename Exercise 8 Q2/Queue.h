/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 2
*
* This is the header file for the queue class.
* This file contains the basic methods declaratons
* for a queue.
* This is an abstract class.
*/

#pragma once

class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;
};
