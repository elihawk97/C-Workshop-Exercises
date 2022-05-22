//Eli Hawk 563385586
//C++ Workshop
//Exercise 3 Question 3
//This is the Function implementation file for the
//MyString class this file implements the method
//declarations in the header file.

#include "MyString.h"
#include <cstring>

/// <summary>
/// constructor with char* parameter for 
/// MyString
/// </summary>
/// <param name="p">char* to append to the new 
/// MyString object</param>
MyString::MyString(const char* p) {
	len = strlen(p);
	data = new char[len + 1];
	strcpy(data, p);
}


/// <summary>
/// copy constructor to perform a deep copy
/// into the new MyString object
/// </summary>
/// <param name="s">reference to a MyString object</param>
MyString::MyString(const MyString& s) :
	MyString(s.data)
{
	cout << "cctor\n";
}

/// <summary>
/// Move constructor, directing the pointer of the
/// new MyString object to the endpoint of the 
/// argument's pointer, and then pointing the argument
/// to nullptr
/// </summary>
/// <param name="source">Rvalue pointer to a 
/// MyString object</param>
MyString::MyString(MyString&& source) noexcept {
	len = source.len;
	data = source.data;
	source.data = nullptr;
	cout << "move ctor" << endl;
}

/// <summary>
/// Example method in the GitHub code
/// displaying the copy constructor 
/// on returning a MyString object
/// </summary>
/// <returns></returns>
MyString f() {
	MyString temp("good day");
	return temp; // cctor
}

/// <summary>
/// Move assign, directing the pointer of the
/// new MyString object to the endpoint of the 
/// argument's pointer, and then pointing the argument
/// to nullptr/// </summary>
/// <param name="source"></param>
/// <returns></returns>
MyString& MyString::operator=(MyString&& source) {
	if (this == &source) {
		return *this;
	}
	if (this != NULL) {
		delete[] data;
	}
	len = source.len;
	data = source.data;
	source.data = nullptr;
	cout << "move assign" << endl;
	return *this;
}

/// <summary>
/// lessthan operator overload
/// </summary>
/// <param name="source">MyString object pointer</param>
/// <returns>boolean, true if the lValue < rValue 
/// in lexagraphic order</returns>
bool MyString::operator<(const MyString& source) {

	int min = len;
	if (source.len < len) {
		min = source.len;
	}

	int i = 0;
	//loop to lexagraphically compare the 2 MyString 
	//objects' char arrays
	while (i < min) {

		if (data[i] < source.data[i]) {
			return true;
		}
		else if (data[i] > source.data[i]) {
			return false;
		}
		i++;
	}

	if (len < source.len) {
		return true;
	}
	return false;
}

/// <summary>
/// lessthan or equal to operator overload
/// </summary>
/// <param name="source"></param>
/// <returns>boolean, true if the lValue <= rValue 
/// in lexagraphic order</returns>
bool MyString::operator<=(const MyString& source) {

	int min = len;
	if (source.len < len) {
		min = source.len;
	}

	int i = 0;
	//loop to lexagraphically compare the 2 MyString 
	//objects' char arrays
	while (i < min) {

		if (data[i] < source.data[i]) {
			return true;
		}
		else if (data[i] > source.data[i]) {
			return false;
		}
		i++;
	}

	if (len <= source.len) {
		return true;
	}
	return false;
}

/// <summary>
/// greaterthan operator overload
/// </summary>
/// <param name="source"></param>
/// <returns>boolean, true if the lValue > rValue 
/// in lexagraphic order</returns>
bool MyString::operator>(const MyString& source) {

	int min = len;
	if (source.len < len) {
		min = source.len;
	}

	int i = 0;
	//loop to lexagraphically compare the 2 MyString 
	//objects' char arrays
	while (i < min) {

		if (data[i] < source.data[i]) {
			return false;
		}
		else if (data[i] > source.data[i]) {
			return true;
		}
		i++;
	}

	if (len > source.len) {
		return true;
	}
	return false;
}

/// <summary>
/// greaterthan or equal to operator overload
/// </summary>
/// <param name="source"></param>
/// <returns>boolean, true if the lValue >= rValue 
/// in lexagraphic order</returns>
bool MyString::operator>=(const MyString& source) {

	int min = len;
	if (source.len < len) {
		min = source.len;
	}

	int i = 0;
	//loop to lexagraphically compare the 2 MyString 
	//objects' char arrays
	while (i < min) {

		if (data[i] < source.data[i]) {
			return false;
		}
		else if (data[i] > source.data[i]) {
			return true;
		}
		i++;
	}

	if (len >= source.len) {
		return true;
	}
	return false;
}

/// <summary>
/// != operator overload
/// </summary>
/// <param name="other"></param>
/// <returns>boolean, true if the lValue != rValue (lexagraphicly)</returns>
bool MyString::operator!=(const MyString& other) {
	//simple chekc to compare the 2 object's equivalence
	//if their lengths are different then they aren't equal
	if (len != other.len) {
		return true;
	}

	int i = 0;
	//loop to lexagraphically compare the 2 MyString 
	//objects' char arrays
	while (i < len) {

		if (data[i] != other.data[i]) {
			return true;
		}
		i++;
	}
	return false;
}

/// <summary>
/// [] operator overload for update operator
/// </summary>
/// <param name="index">index of spot in 
/// char array to update</param>
/// <returns></returns>
char& MyString::operator[](int i) {

	//checks to make sure index is within the range 
	//of the char array
	if (i < 0 or i >= len) {
		cout << "ERROR" << endl;
		return data[0];
	}
	return data[i];

}

/// <summary>
/// [] operator overload for retrieve operator
/// </summary>
/// <param name="index">index of spot in char array
///  to retrieve</param>
/// <returns>char reference</returns>
const char& MyString::operator[](int i) const {
	
	//checks to make sure index is within the range 
	//of the char array
	if (i < 0 or i >= len) {
		cout << "ERROR" << endl;
		return data[0];
	}
	return data[i];
}

/// <summary>
/// insert operator for MyString class to insert
/// a char array into a MyString array char array
/// at a specific index
/// </summary>
/// <param name="index">index of spot in array to add 
/// the char array to</param>
/// <param name="str">char ptr of the char array to 
/// add to the MyString</param>
/// <returns>the new MyString object</returns>
MyString MyString::insert(int index, const char* str) {

	MyString newString;
	if (index > len) {
		cout << "ERROR" << endl;
		return newString;
	}

	//create and allocate memory to a new char*
	char* concat = new char[len + strlen(str) + 1];

	//combine the MyString object with char* char array
	//adding the char* to the object at the index specified
	for (int i = 0; i < len + strlen(str) + 1; i++) {
		if (i < index) {
			concat[i] = data[i];
		}
		else if (i >= index and i < (index + strlen(str))) {
			concat[i] = str[i - index];
		}
		else if (i < len + strlen(str)) {
			concat[i] = data[i - strlen(str)];
		}
		else {
			concat[i] = '\0';
		}
	}
	MyString newString2(concat);
	return newString2;

}


/// <summary>
/// print function for this String
/// </summary>
void MyString::print() {

	for (int i = 0; i < len; i++) {
		cout << data[i];
	}
	cout << endl;
}

/// <summary>
/// method to return the MyString 
/// object's length
/// </summary>
/// <returns></returns>
int MyString::getLength() {
	return len;
}

