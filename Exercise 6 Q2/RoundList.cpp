/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 2
*
* This is the implementation file for the methods
* and constructors of the RoundList child class
* of the List base class.
*/

#include "RoundList.h"

RoundList::RoundList::RoundList()
{

}


/// <summary>
/// Method to add a new link to the front of a
/// RoundList.
/// </summary>
/// <param name="val"></param>
void RoundList::add(int val)
{
	//Add a new value to the front of a Linked List
	if (head != nullptr) {
		head->next = new Link(val, head->next);
	}
	else { //if the RoundList is empty
		head = new Link(val, nullptr);
		head->next = head;
	}
	if (head == nullptr)
		throw "failed in memory allocation";
}



/// <summary>
/// Returns the first element in the list,
/// and throws an exception if the list is empty.
/// </summary>
/// <returns></returns>
int RoundList::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->next->value;
}


/// <summary>
/// Removes the first element in the list, it throws
/// an exception if the RoundList is Empty.
/// </summary>
void RoundList::removeFirst()
{
	// make sure the RoundList is not empty
	if (isEmpty()) {
		throw "the List is empty, no Elements to remove";
	}
	// Execute if there is only 1 element in the RoundList
	if (head->next == head) {
		delete head;
		head = nullptr;
		return;
	}

	// save pointer to the removed node
	Link* p = head->next;
	// reassign the first node
	head->next = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

/// <summary>
/// Clears out all elements in the list and
/// deallocates the memory.
/// </summary>
void RoundList::clear()
{
	// empty all elements from the List
	Link* next;
	Link* headNext = head->next;
	head->next = nullptr;

	for (Link* p = headNext; p != nullptr; p = next)
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
/// Insert function to insert a new Link
/// in the correct position in the RpundList
/// </summary>
/// <param name="key">the Value to add to the List</param>
void RoundList::insert(int key) {

	if (key >= head->next->value) {
		add(key);
	}
	else {
		//special test case for inserting the lowest element in the List 
		if (key <= head->value) {
			head->next = new Link(key, head->next);
			head = head->next;
		}
		for (Link* p = head->next; p != head; p = p->next) {
		    // case of inserting the second to lowest element in the RoundList
			if (p->next == head) {
				p->next = new Link(key, head);
				return;
			}
			// Regular insertion case for inserting an element in the 
			// middle of the List.
			else if (key >= p->next->value) {
				p->next = new Link(key, p->next);
				return;
			}

		}

	}
}

/// <summary>
/// Remove a specific value in the List,
/// it will remove only the first occurence 
/// of the value
/// </summary>
/// <param name="key">the value to be reomved</param>
void RoundList::remove(int key) {
    // If the RoundList is empty throw an error
	if (isEmpty()) {
		throw "value not found";
	}
	// Execute if there is only one element in the RoundList
	if (head == head->next) {
		if (head->value == key) {
			delete head;
			head = nullptr;
			return;
		}
		throw "value not found";
	}


	Link* p = head->next;
	bool found = false;
	//special test case for first element in the List
	if (head->next->value == key) {
	    // Execute if there is only one element in the RoundList
		if (head->next == head) {
			Link* temp = head->next;
			head->next = head->next->next;
			delete temp;
			head = nullptr;
			return;
		}
		// Regular case if the first element is being removed
		Link* temp = head->next;
		head->next = head->next->next;
		delete temp;
		return;
	}
	// If the value sent is greater than the first element in the sorted 
	// RoundList then throw an error
	else if (key > p->value) {
		found = false;
	}
	// If the value is that of the first element
	else if (key == p->value) {
		head->next = p->next;
		delete p;
		return;
	}
	else {
	    // Regular case of searching thourghout the middle of the RoundList
		while (p->next->value >= key and p->next != head->next) {
			if (p->next->value == key) {
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


/// <summary>
/// overload method for the input operator to
/// allow a user to create a new RoundList
/// </summary>
/// <param name="is">istream object</param>
/// <param name="list">the list to fill/create</param>
/// <returns>the istream object</returns>
istream& operator>>(istream& is, RoundList& list) {
	list.clear();

	int input = 0;
	is >> input;
	list.add(input);
	List::Link* p = list.head;
	List::Link* _head = list.head;


	while (p->value >= input) {
		is >> input;
		if (p->value > input) {
			p->next = new List::Link(input, _head);
			p = p->next;
		}
	}
	return is;
}


/// <summary>
/// copy assignment operator for the List,
/// performing a deep copy from the argument
/// List to the Left operand List
/// </summary>
/// <param name="source">the source List, a reference to the 
/// List to be copied</param>
/// <returns>the newly copied List</returns>
RoundList& RoundList::operator=(const RoundList& source) {
	if (this == &source) {
		return *this;
	}
	// Copy the last element in the RoundList
	head = new Link(source.head->value, nullptr);
	Link* q = head;
    
    // Copy the rest of the RoundList with the head pointing to the 
    // last element in the RoundList
	for (Link* p = source.head->next; p != head; p = p->next) {
		if (p->next = source.head) {
			q->next = head;
		}
		else {
			q->next = new Link(p->value, p->next);
			q = q->next;
		}
	}
	return *this;
}



/// <summary>
/// Copy Constructor for RoundList Class
/// </summary>
/// <param name="l">List object to be copied</param>
RoundList::RoundList(const RoundList& source)
{
	Link* q;
	if (source.head == nullptr)
		head = nullptr;
	else
	{
	    // Copy the last element in the RoundList
		head = new Link((source.head)->value, nullptr);
		q = source.head;
		// Copy the rest of the RoundList with the head pointing to the 
        // last element in the RoundList
		for (Link* p = source.head->next; p != head; p = p->next) {
			if (p->next = source.head) {
				q->next = head;
			}
			else {
				q->next = new Link(p->value, p->next);
				q = q->next;
			}
		}
	}
}
// Additional Methods for RoundList

/// <summary>
/// Method to add a value to the end of the RoundList.
/// </summary>
/// <param name="val"></param>
void RoundList::addToEnd(int val) {
	if (isEmpty()) {
		add(val);
	}
	else {
		head->next = new Link(val, head->next);
		head = head->next;
	}
}



/// <summary>
/// overload for the output operator to 
/// print out a List object
/// </summary>
/// <param name="os">ostream object</param>
/// <param name="list">the List to be printed</param>
/// <returns>the ostream object</returns>
ostream& operator<<(ostream& os, RoundList& list) {
	//speacial insert for the first element in the List
	if(list.isEmpty()) {
		os << "";
		return os;
	}
	if (list.head->next == list.head) {
		os << list.head->value;
	}
	else {
		os << list.head->next->value << " ";

		for (List::Link* p = list.head->next->next; p != list.head->next; p = p->next) {
			os << p->value << " ";
		}
	}
	return os;
}

/// <summary>
/// searchs for a value in the list 
/// needed to overload, since the search function
/// in List terminates when the List hits the last
/// elemetn marked with a nullptr, but in RoundList
/// there is no nullptr in the List
/// </summary>
/// <param name="val">the value to find</param>
/// <returns>true if the value is in the list</returns>
int RoundList::search(int n) const
{
	if (isEmpty()) {
		return -1;
	}
	// loop to test each element
	Link* p = head;

	for (int i = 0; i <= n; i++) {
		p = p->next;
	}
	return p->value;
}
