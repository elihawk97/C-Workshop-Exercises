/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* This is the implementation file for the methods
* and constructors of the Employee class.
*/

#include "Employee.h"


/// <summary>
/// Default Constructor, initizializes all attributes
/// to an empty string for strings an 0 for int's
/// </summary>
Employee::Employee() : name(""), id(0), seniority(0), pay(0) {}

/// <summary>
/// Constructor with parameters with which to initialize 
/// an Employee object.
/// </summary>
/// <param name="_name">the Employee's name</param>
/// <param name="_id">the Employee's ID</param>
/// <param name="_seniority">the Employee's seniority</param>
Employee::Employee(string _name, int _id, int _seniority) :
	name(_name), id(_id), seniority(_seniority), pay(0) {
	//no further initialization
}


/// <summary>
/// Copy constructor for a deep copy of an 
/// Employee object
/// </summary>
/// <param name="source">the Employee object to be copied</param>
Employee::Employee(Employee& source) {
	name = source.name;
	id = source.id;
	seniority = source.seniority;
	pay = source.pay;
}

/// <summary>
/// Method to calculate the employee's salary
/// after his monthly bonus. If his seniority
/// is less than or equal to 5 years than it 
/// is a flat rate 500NIS, otherwise it is 25%
/// of his base salary
/// </summary>
/// <returns>the salary after bonus</returns>
float Employee::salaryAfterBonus() {
	if (seniority <= 5) {
		pay = pay + 500;
	}
	else {
		pay = (pay * 1.25);
	}
	
	return pay;
}


/// <summary>
/// Input operator override to read in an Employee
/// object using "cin." If there is an error in the 
/// input an error will be thrown and caught in
/// main.cpp
/// </summary>
/// <param name="is">refernce to the istream object</param>
/// <param name="newEmp">reference to an Employee object</param>
/// <returns>reference to the "filled" istream object</returns>
istream& operator>>(istream& is, Employee& newEmp) {
	string _name = "";
	int _id = 0;
	int _seniority = 0;

	// Read in Employee object data
	is >> _name;
	is >> _id;
	is >> _seniority;
	
	if (is.fail()) {
		is.clear();
		throw "ERROR";
	}

	newEmp = Employee(_name, _id, _seniority);

	return is;
}

/// <summary>
/// Output operator overload to print an Employee object
/// using "cout."
/// </summary>
/// <param name="os">reference to an ostream object</param>
/// <param name="source">reference to an Employee object</param>
/// <returns>reference to the "filled" ostream object</returns>
ostream& operator<<(ostream& os, Employee& source) {
	string employeeData = "";
	
	employeeData += source.name + "\n";
	employeeData += source.id + "\n";
	employeeData += source.seniority + "\n";

	os << employeeData;
	return os;
}