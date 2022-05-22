//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This program allows the user to enter information about
//employees working at the "Give From the Heart" organization
//and it will output the employee that raised the least amount
//of money and the employee that had the highest salary
//this file implements the methods for the "Employee" object
#include <iostream>
#include "Employee.h"
#include <string.h>

#pragma warning(disable : 4996)

/// <summary>
/// Default constructor for the program
/// </summary>
Employee::Employee() {
	setHourlyWage(0);
	setHoursWorked(0);
	setMoneyRaised(0);
	strcpy(name, "noname");
	setSocialSecurityNumber(123456789);
}



/// <summary>
/// Constructor with values user-defined values passed into it
/// </summary>
/// <param name="socialSecurity">social security number of employee</param>
/// <param name="employeeName">the employee's name</param>
/// <param name="wage">the hourly wage of the employee</param>
/// <param name="numberOfHours">Number of hours worked by the employee</param>
/// <param name="collected">Amount of money fundraised for the organization</param>
Employee::Employee(int socialSecurity, const char *employeeName, float wage, int numberOfHours, int collected) {
	setHourlyWage(wage);
	setHoursWorked(numberOfHours);
	setMoneyRaised(collected);
	setName(employeeName);
	setSocialSecurityNumber(socialSecurity);
	calculateTotalSalary();
}


/// <summary>
/// setter method for the employee's social security number
/// </summary>
/// <param name="socialSecurity">the employee's social security number</param>
void Employee::setSocialSecurityNumber(int socialSecurity){
	SocialSecurityNumber = socialSecurity;
}

/// <summary>
/// Getter method for the employee's social security number
/// </summary>
/// <returns>int of the employee's social security number</returns>
int Employee::getSocialSecurityNumber() const{
	return SocialSecurityNumber;
}

/// <summary>
/// setter for the employee "name" field
/// </summary>
/// <param name="name">name of the employee</param>
void Employee::setName(const char *employeeName) {
	if (strlen(employeeName) <= 21) {
		strcpy(name, employeeName);
	}
	return;
}

/// <summary>
/// This method returns the employee's name as a char array
/// </summary>
/// <returns>The employees name as a char array</returns>
char *Employee::getName() const{
    char *temp = new char[strlen(name) + 1];
    strcpy(temp, name);
	return temp;
}

/// <summary>
/// set the number of hours that the employee worked
/// </summary>
/// <param name="hours">number of hours the employee worked</param>
void Employee::setHoursWorked(int hours){
	hoursWorked = hours;
}

/// <summary>
/// get the number of hours that the employee worked
/// </summary>
/// <returns>hoursWorked - the number of hours the employee worked</returns>
int Employee::getHoursWorked() const{
	return hoursWorked;
}

/// <summary>
/// set the per hour wage of the employee
/// </summary>
/// <param name="wage">the hourly wage of the employee</param>
void Employee::setHourlyWage(float wage) {
	hourlyWage = wage;
}

/// <summary>
/// get the hourly wage of the employee
/// </summary>
/// <returns>hourlyWage - the hourly wage of the employee</returns>
float Employee::getHourlyWage() const{
	return hourlyWage;
}

/// <summary>
/// sets the field of the amount of money fundraised for
/// the organization by the employee
/// </summary>
/// <param name="collectedAmount">amount of money collected</param>
void Employee::setMoneyRaised(float collectedAmount) {
	moneyRaised = collectedAmount;
}

/// <summary>
/// get the field of the amount of money fundraised for
/// the organization by the employee
/// </summary>
/// <returns>moneyRaised - amount of money collected</returns>
float Employee::getMoneyRaised() const{
	return moneyRaised;
}
/// <summary>
/// This method calculates the employee's salary
///based on his hours worked mulitplied by his
///hourly wage and then added to that is the percentage
///of the money he collected
/// </summary>
void Employee::calculateTotalSalary(){
	totalSalary = (hourlyWage * hoursWorked);

	float collectedMoney = moneyRaised;
//adding the money collected for an employee that collected less than 1k
	if (collectedMoney <= 1000) {
		totalSalary = totalSalary + (collectedMoney * .1);
	}
//adding the money collected for an employee that collected between 1k-2k
	if (collectedMoney > 1000 and collectedMoney <= 2000) {
		totalSalary = totalSalary + ((collectedMoney - 1000) * .15) + (1000 * .1);
	}
//adding the money collected for an employee that collected between 2k-4k
	if (collectedMoney > 2000 and collectedMoney <= 4000) {
		totalSalary = totalSalary + ((collectedMoney - 2000) * .2) + 1000 * .15 + 1000 * .1;
	}
//adding the money collected for an employee that collected between 4k-5k
	if (collectedMoney > 4000 and collectedMoney <= 5000) {
		totalSalary = totalSalary + ((collectedMoney - 4000) * .3) + 2000 * .2 + 1000 * .15 + 1000 * .1;
	}
//adding the money collected for an employee that collected more than $5000
	if (collectedMoney > 5000) {
		totalSalary = totalSalary + ((collectedMoney - 5000) * .4) + 1000 * .3 + 2000 * .2 + 1000 * .15 + 1000 * .1;
	}
	

}

float Employee::getTotalSalary() {
	//float temp = totalSalary;
	return totalSalary;
}

