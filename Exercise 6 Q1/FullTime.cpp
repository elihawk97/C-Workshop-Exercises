/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* This is the implementation file for the methods
* and constructors of the FullTime child class
* of the Employee base class.
*/

#include "FullTime.h"


/// <summary>
/// Constructor with parameters with which to initialize 
/// a FullTime object.
///  </summary>
/// <param name="_name">the FullTime Employee's name</param>
/// <param name="_id">the FullTime Employee's ID</param>
/// <param name="_seniority">the FullTime Employee's seniority level</param>
/// <param name="_salaryPerYear">the FullTime Employee's yearly salary</param>
FullTime::FullTime(string _name, int _id, int _seniority, int _salaryPerYear){
	name = _name;
	id = _id;
	seniority = _seniority;
	salaryPerYear = _salaryPerYear;
	salary(); //initializes pay
}

/// <summary>
/// Empty constructor for the FullTime class, which
/// initializes all fields to 0 or an empty string.
/// It calls the Employee class constructor to initialize 
/// the fields inherited from that class.
/// </summary>
FullTime::FullTime() : Employee("", 0, 0){
	salaryPerYear = 0;
}


/// <summary>
/// Method to compute the monthly salary of the 
/// PartTimeemployee.
/// </summary>
void FullTime::salary() {
	pay = int(salaryPerYear/12.0);
}

/// <summary>
/// Input Operator overload to allow a user to input
/// the details of a PartTime object.
/// </summary>
/// <param name="is">reference to the istream operator to fill with 
/// the FullTime initialized FullTime object</param>
/// <param name="newFT">reference to the FullTime object
/// to be initialized</param>
/// <returns>the istream object with the FullTime Employee
/// details filled in it</returns>
istream& operator>>(istream& is, FullTime& newFT) {
	string _name = "";
	int _id = 0;
	int _seniority = 0;
	int _salaryPerYear = 0;
	
	is >> _name >> _id >> _seniority >> _salaryPerYear;

	if (is.fail() or _id < 0 or _seniority < 0 or _salaryPerYear < 0) {
		is.clear();
		throw "ERROR";
	}
	newFT = FullTime(_name, _id, _seniority, _salaryPerYear);

	return is;
}

/// <summary>
/// Output operator overload to print out a
/// FullTime object. 
/// </summary>
/// <param name="os">reference to an ostream object</param>
/// <param name="source">reference to a FullTime object to be printed</param>
/// <returns>reference to the ostream object to be printed</returns>
ostream& operator<<(ostream& os, FullTime& source) {
	string employeeData = "";

	employeeData += "Employee: " + source.name + "\n";
	employeeData += "Employee ID: " + to_string(source.id) + "\n";
	employeeData += "Years Seniority: " + to_string(source.seniority) + "\n";
	employeeData += "Salary per Month: " + to_string(int(source.pay)) + "\n";

	os << employeeData;
	return os;
}