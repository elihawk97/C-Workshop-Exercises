/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 2
*
* This is the method implementation file
* which implements the methods of the class
* List. 
* 
* It includes overloaded operators and
* other methods which perform operations on
* List objects.
*/

#include "List.h"
#include <string>

/// <summary>
/// Constructor for a new Link, with the
/// parameters for the value and next
/// sent to it.
/// </summary>
/// <param name="val">the number to put in the link</param>
/// <param name="nxt">the link to have next point to</param>
List::Link::Link(int val, Link* nxt) :
	value(val), next(nxt) {}

/// <summary>
/// Copy constructor for the Link class.
/// Takes in a reference to another link
/// and copies the content.
/// </summary>
/// <param name="source">reference to the link to be copied</param>
List::Link::Link(const Link& source) :
	value(source.value), next(source.next) {}


List::List() : head(nullptr)
{
	// no further initialization
}

/// <summary>
/// Copy Constructor for List Class
/// </summary>
/// <param name="l">List object to be copied</param>
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

/// <summary>
/// Destructor for the List class
/// </summary>
List::~List()
{
	clear();
}

/// <summary>
/// clears out all elements in the list and
/// deallocates the memory
/// </summary>
void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link* p = head; p != nullptr; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}




/// <summary>
/// Checks to see if the list is empty by checking if 
/// "head" points to "nullptr"
/// </summary>
/// <returns>bool true if the list is empty</returns>
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null

	return head == nullptr;
}


/// <summary>
/// adds a new value at the front of the list
/// </summary>
/// <param name="val">the value to be added to the list</param>
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

/// <summary>
/// returns the first element in the list,
/// and throws an exception if the list is empty
/// </summary>
/// <returns></returns>
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

/// <summary>
/// searchs for a value in the list 
/// </summary>
/// <param name="val">the value to find</param>
/// <returns>true if the value is in the list</returns>
bool List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


/// <summary>
/// removes the first element in the list
/// </summary>
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

/// <summary>
/// copy assignment operator for the List,
/// performing a deep copy from the argument
/// List to the Left operand List
/// </summary>
/// <param name="source">the source List, a reference to the 
/// List to be copied</param>
/// <returns>the newly copied List</returns>
List& List::operator=(const List& source) {
	if (this == &source) {
		return *this;
	}
	head = new Link(source.head->value, nullptr);
	Link* q = head;

	for (Link* p = source.head->next; p != nullptr; p = p->next) {
		q->next = new Link(p->value, p->next);
		q = q->next;
	}
	return *this;
}

/// <summary>
/// overload method for the input operator to
/// allow a user to create a new List
/// </summary>
/// <param name="is">istream object</param>
/// <param name="list">the list to fill/create</param>
/// <returns>the istream object</returns>
istream& operator>>(istream& is, List& list) {
	list.clear();

	int input = 0;
	is >> input;
	list.add(input);
	List::Link* p = list.head;

	while (p->value >= input) {
		is >> input;
		if (p->value > input) {
			p->next = new List::Link(input, nullptr);
			p = p->next;
		}
	}
	return is;
}

/// <summary>
/// overload for the output operator to 
/// print out a List object
/// </summary>
/// <param name="os">ostream object</param>
/// <param name="list">the List to be printed</param>
/// <returns>the ostream object</returns>
ostream& operator<<(ostream& os, List& list) {

	for (List::Link* p = list.head; p != nullptr; p = p->next) {
		os << p->value << " ";
	}

	return os;
}


/// <summary>
/// insert function to insert a new Link
/// in the correct position in the list
/// </summary>
/// <param name="key">the Value to add to the List</param>
void List::insert(int key) {

	if (key >= head->value) {
		add(key);
	}
	else {
		for (Link* p = head; p != nullptr; p = p->next) {
			if (p->next == nullptr) {
				p->next = new Link(key, nullptr);
				return;
			}
			else if (key >= p->next->value) {
				p->next = new Link(key, p->next);
				return;
			}

		}

	}
}

/// <summary>
/// remove a specific value in the List,
/// it will remove only the first occurence 
/// of the value
/// </summary>
/// <param name="key">the value to be reomved</param>
void List::remove(int key) {

	Link* p = head;
	bool found = false;

	if (key > p->value) {
		found = false;
	}
	else if (key == p->value) {
		head = p->next;
		delete p;
		return;
	}
	else {
		while (p->next->value >= key and p->next != nullptr) {
			if (key == p->next->value) {
				Link* temp = p->next;
				p->next = p->next->next;
				delete temp;
				return;
			}
			p = p->next;
		}
	}
	if (found == false) {
		throw "value not found";
	}
}

