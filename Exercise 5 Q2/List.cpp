/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 5 Question 1
*
* This is the method implementation file
* which implements the methods of the class
* List. It includes overloaded operators and
* other methods which perform operations on
* List objects.
* 
* This file includes additonal global methods
* that perform the following operations on Lists 
* sent to it:
* 1) merge - merges 2 lists together
* 2) makeSet - removes all duplicates from the list
* 3) reverse - reverses the list from nonascending to
*              nondescending order.
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



/// <summary>
/// Takes in references to 2 lists in and then
/// copies lst1 to a new List and then add the 
/// elements of lst2 to the new List.
/// Then the method returns the new List.
/// </summary>
/// <param name="lst1">Reference to List object</param>
/// <param name="lst2">Reference to List object</param>
/// <returns>List which is a merge of the 2 sent lists</returns>
List merge(const List& lst1, const List& lst2) {

	List merged(lst1);
	List lst2Copy(lst2);
	
	//add the elements of lst2 to 'merged'
	while (!(lst2Copy.isEmpty())) {
		merged.insert(lst2Copy.firstElement());
		// remove the first Link in lst2 to allow access
		// to the next elements in the lst2 to add them
		// to merged, using the firstElement() method.
		try {
			lst2Copy.removeFirst();
		}
		catch(const char* msg) {
			//catch the error, but just ignore it
		}
		
	}
	return merged;
}


/// <summary>
/// Takes in an input of a List object and removes
/// all duplicates from it, making it a set,
/// i.e. the classic set in "set theory."
/// </summary>
/// <param name="lst">List object to maeke a set</param>
void makeSet(List& lst) {
	List lstCopy(lst);

	bool existsDuplicate = true;

	// This section removes the dupliactes by:
	// Taking the value of the first element in the list 
	// and comparing it to the rest of the list using
	// the firstelement() method to view the Link values
	// and removing the first value in the list if it is
	// a duplicate.
	while (lst.isEmpty() != true) {
		//tests the next value in the Lis
		int checker = lst.firstElement();
		//remove the first occurence of the value from lst
		lst.remove(lst.firstElement());
		existsDuplicate = true;

		while(existsDuplicate) {
			existsDuplicate = (lst.search(checker) == true);
			// if there is another occurence of the value in
			// lst then remove it from lst and lstcpy.
			if (existsDuplicate) {
				lst.remove(checker);
				lstCopy.remove(checker);
			}
		}
	}
	lst = lstCopy;
}

/// <summary>
/// Takes in a sorted List object which is in
/// nonascending order and reverses to be 
/// nondescending. It changes the actual object sent
/// to it and does Not return any object.
/// </summary>
/// <param name="lst">sorted List object</param>
void reverse(List& lst) {
	
	List lstCopy;
	
	//copies the Links in lst to lstCopy by adding the 
	//first elements to the new List first and then adding
	//all of the subsequent Links (which will be greater) to
	//the front of the new List, making the new List the 
	//reversed order of lst
	while (lst.isEmpty() != true) {
		lstCopy.add(lst.firstElement());
		lst.removeFirst();
	}

	lst = lstCopy;
}