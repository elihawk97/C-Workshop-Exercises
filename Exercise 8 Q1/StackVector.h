/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 8 Question 1
*
* This is the header file and implementation of the 
* StackVector template class. 
*/


#include <sstream> // use stringstream class  
#include <string>
#include "Vector.h" 
#include <ctype.h>

//-------------------------------------------------------
// class StackVector
// Stack implemented using Vector
// Vector will grow as necessary to avoid overflow
//-------------------------------------------------------


template<class T> class StackVector {
protected:
	Vector<T> data;

public:
	// constructor requires a starting size
	StackVector(T capacity);
	StackVector(const StackVector& s);

	// Stack operations
	void clear();
	bool isEmpty() const;
	T pop();
	void push(T value);
	T top();
};


//-------------------------------------------------------
// class StackVector implementation
// ***Note: The implementation must be in the .h 
// file with the class definition.
//-------------------------------------------------------

/// <summary>
/// Constructor for the StackVector class. It calls the 
/// constructor of the Vector class to create a vector
/// of capacity "capacity."
/// </summary>
/// <typeparam name="T">the type of variable the StackVector 
/// holds, which is determined at compile time.</typeparam>
/// <param name="capacity">the capacity of the stack</param>
template<class T>
StackVector<T>::StackVector(T capacity)
	: data(capacity)
{
	// create and initialize a Stack based on Vectors
}

/// <summary>
/// Copy constructor for the StackVector class, to perform
/// a deep copy on a StackVector. This constructor calls the 
/// copy constructor of the Vector template class to do the 
/// actual copying of the elements in the Vector field of the 
/// source StackVector to the new one. 
/// </summary>
/// <typeparam name="T">the type of variable the 
/// StackVector holds, which is determined at compile time.</typeparam>
/// <param name="s"></param>
template<class T>
StackVector<T>::StackVector(const StackVector<T>& s): data(s.data){
	// No further initialization.
}

/// <summary>
/// Method to clear all contents of the stack.
/// It call the clear function of the vector class
/// to delete all elements in the vector that is 
/// used to build the stack.
/// </summary>
/// <typeparam name="T">the type of variable the StackVector holds</typeparam>
template<class T>
void StackVector<T>::clear()
{
	// clear all elements from Stack, by setting
	// index to bottom of Stack
	data.clear();
}

/// <summary>
/// Checks if the stack is empty by calling the 
/// isEmpty function of the Vector class for the
/// data fiel, which is of type Vector, where the
/// elements are stored
/// </summary>
/// <typeparam name="T">the type of variable the StackVector holds</typeparam>
/// <returns>Boolean, true if the stack is empty.</returns>
template<class T>
bool StackVector<T>::isEmpty() const
{
	return data.getSize() == 0;
}

/// <summary>
/// Removes the top element of the stack and
/// returns it. It uses the delLast function
/// of the data field, of type Vector, to remove
/// the last element from the vector and return it.
/// </summary>
/// <typeparam name="T">the type of variable the StackVector holds</typeparam>
/// <returns>Top element of the stack</returns>
template<class T>
T StackVector<T>::pop()
{
	// return and remove the intopmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data.delLast();
}

/// <summary>
/// Adds an element to the top of the stack.
///  It uses the insert function of the data 
/// field, of type Vector, to add an element
/// to the end of the vector, which is the top 
/// of the stack.
/// </summary>
/// <typeparam name="T">the type of variable the StackVector holds</typeparam>
/// <param name="val">Element to be inserted.</param>
template<class T>
void StackVector<T>::push(T val)
{
	// push new value onto Stack
	data.insert(val);
}

/// <summary>
/// Returns the value of the top element in the stack.
/// It uses the operator[] overload of the Vector class
/// for the data field, to retrieve to the last element
/// in the vector, which is the top element in the stack.
/// </summary>
/// <typeparam name="T">the type of variable the StackVector holds</typeparam>
/// <returns>Top element in the stack.</returns>
template<class T>
T StackVector<T>::top()
{
	// return the intopmost element in the Stack
	if (isEmpty()) throw "Stack is empty";
	return data[data.getSize() - 1];
}


/*------Global Functions------*/ 

/// <summary>
/// Goal: Convert an infix math expression to postfix form.
/// 
/// In Short: It utilizes a stack to push operation sysmbols
/// and parenthesis onto while putting all operands directly 
/// into the postfix string. When it reaches a right parenthesis
/// it pops the operation symbols off and appends them to the 
/// postfix string. 
/// 
/// Step-By-Step: Note: after each operation shorten the infix string by 1
/// 
/// Step 1: When a left parenthesis is reached it is pushed onto the stack.
/// Step 2: When an operand is reached the number is appended to the postfix
///			string. (Note: here we shorten the infix string by the number of
///			numbers long the operand is. e.g. 435 -> shorten by 3 chars)
/// Step 3: a) If a "+" or "-" is reached then any "*" or "/" is popped off
///				the stack and appended to the postfix string. Then the "+" 
///				or "-" is pushed onto the stack. This ensures that the
///				mathematical order of operations is kept. For Example:
///				((5+4)*2+8) -> will result in 5 4 + 2 * 8 + = 26
///				and not 5 4 + 2  8 + * = 90
///			b) If a "*" or "/" just push it onto the stack
/// Step 4: When a right parenthesis is reached pop all operands off the stack
///			until a left parenthesis is reached. Append the operands in order
///			of being popped off onto the postfix string. Then pop the left
///			parenthesis off the stack without appending it to the string.
/// Step 5: When the infix string is empty, pop all operation symbols off the 
///			stack and append them in that order to the postfix string. Done :)
/// 
///	
/// </summary>
/// <param name="infix">Math expression string written in infix notation</param>
/// <returns>Math expression string written in prefix notation</returns>
string infixToPostfix(string infix) {
	string postFix = "";
	StackVector<char> pStack(infix.length());
	
	// Loop to check each charachter in the infix string
	while (infix != "") {
		
		// Check for left parenthesis.
		if (infix.substr(0, 1) == "(") {
			pStack.push(*"(");
			infix = infix.substr(1);
		}
		// Check for right parenthesis.
		else if (infix.substr(0, 1) == ")") {
			// Pop all operation symbols off the stack and 
			// append them to postfix.
			while (pStack.top() != *"(") {
				postFix = postFix + pStack.pop();
				postFix = postFix + " ";
			}
			pStack.pop();
			infix = infix.substr(1);

		}
		// Check if next char is multiplication sign.
		else if (infix.substr(0, 1) == "*") {
			pStack.push(*"*");
			infix = infix.substr(1);
		}
		// Check if next char is division sign.
		else if (infix.substr(0, 1) == "/") {
			pStack.push(*"/");
			infix = infix.substr(1);
		}
		// Check if next char is add or subtract sign.
		else if (infix.substr(0, 1) == "-" or infix.substr(0, 1) == "+") {
			// Pop off all operation with higher precedence than "+" or "-" 
			while (pStack.top() == *"*" or pStack.top() == *"/") {
				postFix = postFix + pStack.pop();
				postFix = postFix + " ";
			}
			if (infix.substr(0, 1) == "+") {
				pStack.push(*"+");

			}
			else {
				pStack.push(*"-");
			}
			infix = infix.substr(1);
		}
		// Check if next char is an operand
		else if (isdigit(infix[0])) {
			while (isdigit(infix[0]) != 0) {
				postFix += infix.substr(0, 1);
				infix = infix.substr(1);
			}
			postFix += " ";
		}
		else {
			infix = infix.substr(1);
		}
	}
	// Pop off additional operation symbols from the stack.
	while (pStack.isEmpty() == false) {
		postFix = postFix + pStack.pop();
	}

	return postFix;
}



/// <summary>
/// Goal: Solve postfix expression.
/// 
/// Step by Step:
/// Step 1:	start with empty integer stack.
/// Step 2: Iterate over the elements of the postfix expression from left to right :
///       a.	If the next element is an operand add it to the stack
///       b.	If the next element it is an operator execute the operator 
///				on the two top elements of the stackand push the result onto 
///				the stack.
/// </summary>
/// <param name="postFix">Math expression string written in postfix notation</param>
/// <returns>result of the postfix math expression</returns>
int calcPostfix(string postFix) {
	StackVector<int> calcStack(postFix.length());

	string holder = "";
	int lvalue = 0;
	int rvalue = 0;
	int intHolder = 0;

	// Iterate over the expression from left to right.
	while (postFix != "") {
		// If it is a space, just delete it from the expression.
		if (postFix[0] == *" ") {
			postFix = postFix.substr(1);
		}
		// Check if the next char is a number, if so, push in onto the stack.
		else if (isdigit(postFix[0]) != 0) {
			while (isdigit(postFix[0]) != 0) {
				holder += postFix.substr(0, 1);
				postFix = postFix.substr(1);
			}

			//convert string number into an int
			stringstream temp;
			temp << holder;
			temp >> intHolder;
			calcStack.push(intHolder);
			holder = "";
		}
		// Otherwise, check which operation the next element in the
		// postfix string is and perform that operation on the top
		// 2 elements in the Stack.
		else {
			rvalue = calcStack.pop();
			lvalue = calcStack.pop();
			if (postFix[0] == *"*") {
				calcStack.push(lvalue * rvalue);
			}
			else if (postFix[0] == *"/") {
				calcStack.push(lvalue / rvalue);
			}
			else if (postFix[0] == *"+") {
				calcStack.push(lvalue + rvalue);
			}
			else if (postFix[0] == *"-") {
				calcStack.push(lvalue - rvalue);
			}
			postFix = postFix.substr(1);
		}
	}
	return calcStack.pop();
}