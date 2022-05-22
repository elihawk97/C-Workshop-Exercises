/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* This is the implementation file for the methods
* and constructors of the PartTime child class
* of the Employee base class.
*/

#include "PartTime.h"

/// <summary>
/// Default constructor for PartTime class
/// </summary>
PartTime::PartTime() : Employee(), hoursOfWork(0), payPerHour(0)
{
	// No further initialization
}

/// <summary>
/// Constructor with parameters with which to initialize 
/// a PartTime object.
///  </summary>
/// <param name="_name">the PartTime Employee's name</param>
/// <param name="_id">the PartTime Employee's ID</param>
/// <param name="_seniority">the PartTime Employee's seniority level</param>
/// <param name="_hoursOfWork">the PartTime Employee's hours worked</param>
/// <param name="_payPerHour">the PartTime Employee's hourly salary</param>
PartTime::PartTime(string _name, int _id, int _seniority, int _hoursOfWork, float _payPerHour) : 
	Employee(_name, _id, _seniority), hoursOfWork(_hoursOfWork), payPerHour(_payPerHour) {
	salary(); //initializes pay
}


/// <summary>
/// Copy constructor for a deep copy of a PartTime
/// instance.
/// </summary>
/// <param source="">the PartTime object to be copied</param>
PartTime::PartTime(PartTime& source) {
	name = source.name;
	id = source.id;
	seniority = source.seniority;
	pay = 0;
	hoursOfWork = source.hoursOfWork;
	payPerHour = source.payPerHour;
}

/// <summary>
/// Method to compute the monthly salary of the 
/// PartTimeemployee.
/// </summary>
void PartTime::salary() {
	pay = int((hoursOfWork * payPerHour));
}

/// <summary>
/// Input Operator overload to allow a user to input
/// the details of a PartTime object.
/// </summary>
/// <param name="is">reference to the istream operator to fill with 
/// the PartTime initialized PartTime object</param>
/// <param name="newPT">reference to the PartTime object
/// to be initialized</param>
/// <returns>the istream object with the PartTime Employee
/// details filled in it</returns>
istream& operator>>(istream& is, PartTime& newPT) {
	string _name = "";
	int _id = 0; 
	int _seniority = 0;
	int _hoursOfWork = 0;
	int _payPerHour = 0;

	is >> _name >> _id >> _seniority >> _hoursOfWork >> _payPerHour;

	if (is.fail() or _id < 0 or _seniority < 0 or _hoursOfWork < 0 or _payPerHour < 0) {
		is.clear();
		throw "ERROR";
	}

	newPT = PartTime(_name, _id, _seniority, _hoursOfWork, _payPerHour);
	return is;
 }

/// <summary>
/// Output operator overload to print out a
/// PartTime object. 
/// </summary>
/// <param name="os">reference to an ostream object</param>
/// <param name="source">reference to a PartTime object to be printed</param>
/// <returns>reference to the ostream object to be printed</returns>
ostream& operator<<(ostream& os, PartTime& source) {
	string employeeData = "";

	employeeData += "Employee: " + source.name + "\n";
	employeeData += "Employee ID: " + to_string(source.id) + "\n";
	employeeData += "Years Seniority: " + to_string(source.seniority) + "\n";
	employeeData += "Hours: " + to_string(source.hoursOfWork) + "\n";
	employeeData += "Salary per Month: " + to_string(int(source.pay)) + "\n";

	os << employeeData;
	return os;
}
