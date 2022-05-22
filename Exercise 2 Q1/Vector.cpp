//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 1
//This is the header for file for the Vector class
//Vector is a class which represents an array and 
//with 3 fields the 1)the array itself 2) capacity
//of the array and 3) the size, which is the actual
//number of elements in the array
//This file implements the methods that were layed
//out in the Vector.h header file

#include "Vector.h"


/// <summary>
/// Default Constructor
/// </summary>
Vector::Vector() {
	capacity = 2;
	data = new int[2];
	size = 0;
}

/// <summary>
/// Regular Constructor
/// </summary>
/// <param name="MaxCapacity"></param>
Vector::Vector(int maxCapacity) {
	bool isPowerOf2 = false;

	for (int i = 0; i < maxCapacity; i++) {
		if (maxCapacity == pow(2, i)) {
			isPowerOf2 = true;
		}
	}
	if (isPowerOf2) {
		capacity = maxCapacity;
		data = new int[maxCapacity];
	}
	else {
		int newCapacity = pow(2, ceil(log(maxCapacity) / log(2)));
		data = new int[newCapacity];
		capacity = newCapacity;
	}
	size = 0;
	
}

/// <summary>
/// Copy Constructer
/// </summary>
/// <param name="source"></param>
Vector::Vector(const Vector& source) {
	capacity = source.capacity;
	size = source.size;
	//calls on the method to copy the array to a new array object
	data = copyArray(source.data);
}

/// <summary>
/// helper function to copy a vector's array to a new array object and 
/// then send back the pointer to that new object
/// </summary>
/// <param name="source">the array to be copied</param>
/// <returns>pointer to a new array instance</returns>
int* Vector::copyArray(int *source) {

	int* temp = new int[capacity];
	// assigns each value in the source array of Points
	// to the new Polygon object's array of points
	for (int i = 0; i < capacity; i++) {
		temp[i] = source[i];
	}
	return temp;

}

/// <summary>
/// Destructor
/// </summary>
Vector::~Vector() {
	if (capacity > 0)
		delete[] data;
}

/// <summary>
/// get the total capacity of the array
/// </summary>
/// <returns>the max capacity of the array</returns>
int Vector::getCapacity() {
	return capacity;
}

/// <summary>
/// get the actual number of elements in the array
/// </summary>
/// <returns>the size of the array</returns>
int Vector::getSize() {
	return size;
}

/// <summary>
/// print function for the Vector object
/// </summary>
void Vector::print() {
	cout <<endl<< "capacity: " << capacity;
	cout << " size: " << size;
	cout << " values: ";

	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// takes in one vector as a parameter and assigns its values to 
/// the vector that called it.
/// </summary>
/// <param name="source">the vector to copy values from</param>
void Vector::assign(Vector source) {
	capacity = source.capacity;
	size = source.size;
	data = copyArray(source.data);
}

/// <summary>
/// compares 2 Vectors and return true if they are the same.
/// 2 vectors are considered the same if they have the same 
/// size and have the same values at each index. 
/// </summary>
/// <param name="right">the vector to be compared on the
/// "right" side of the == operator</param>
/// <returns>true: if vectors are equal, false otherwise</returns>
bool Vector::isEqual(Vector right) {
	if (size != right.size) {
		return false;
	}

	bool isEqual = true;
	int i = 0;
	while(isEqual and i < size) {
		if (data[i] != right.data[i]) {
			isEqual = false;
		}
		i++;
	}

	if (isEqual) {
		return true;
	}
	return false;
}

/// <summary>
/// this method functions as a [] operator
/// and returns a reference to the value at the integer
/// sent to the method, if that integer is out of range
/// then it will return the value in the first element
/// in the array
/// </summary>
/// <param name="index">the index of the value in the
/// array to return</param>
/// <returns>a reference to the value in the array at 
/// index</returns>
int& Vector::at(int index) {
	if (index >= size or index < 0) {
		cout << "ERROR";
		return data[0];
	}
	return data[index];
}

/// <summary>
/// method to calculate the dot product of 2 vectors
/// and then return that value
/// </summary>
/// <param name="other">the second vector for the dot product</param>
/// <returns>dotproduct of 2 vectors, unless their size is not 
/// equal, if so it return -1</returns>
int Vector::scalmul(Vector other) {

	if (size != other.size) {
		cout << "ERROR";
		return -1;
	}

	int dotProduct = 0;
	for (int i = 0; i < size; i++) {
		dotProduct += (data[i] * other.data[i]);
	}
	return dotProduct;
}

/// <summary>
/// 
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Vector Vector::strnewcat(Vector other) {
	int newCapacity = capacity + other.capacity;
	Vector newVector(newCapacity);
	newVector.size = size + other.size;
	for (int i = 0; i < (size + other.size); i++) {
		if (i < size) {
			newVector.data[i] = data[i];
		}
		else {
			newVector.data[i] = other.data[i - size];
		}
	}

	return newVector;
}

/// <summary>
/// sets the size field of the Vector to 2 just like
/// described for making the default constructor.
/// this implicitly deletes the data in the array
/// by setting the size to 0
/// </summary>
void Vector::clear() {
	size = 0;
}

/// <summary>
/// Deletes the last item in the array by setting the
/// size to be "size - 1"
/// </summary>
void Vector::delLast(){
	if (size == 0) {
		cout << "ERROR";
	} 
	else {
		size = size - 1;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="val"></param>
void Vector::insert(int val) {
	
	if (size < capacity && size >= 0) {
		data[size] = val;
	}
	else {
		capacity *= 2;
		int* temp = new int[capacity];

		for (int i = 0; i < capacity; i++) {
			if (i < capacity / 2) {
				temp[i] = data[i];
			}
			else {
				temp[i] = val;
			}
		}
		data = temp;
	}
	size += 1;
}






