//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This program allows the user to enter information about
//employees working at the "Give From the Heart" organization
//and it will output the employee that raised the least amount
//of money and the employee that had the highest salary
//this is the driver (main) function of the program
#include <iostream>
#include <string.h>
#include <list>
#include "Employee.h"

#pragma warning(disable : 4996)

using namespace std;

/// <summary>
/// This method takes in the user-entered numbers and 
/// checks to make sure they are valid number inputs
/// before using them to create an instance of Employee
/// </summary>
/// <param name="numToCheck"></param>
/// <returns></returns>
bool numberChecker(float numToCheck) {
	if (numToCheck >= 0) {
		return true;
	}
	return false;
}

int main() {

	//This is the list of variables the main function will use to
	//take store the user's data and create a new instance of Employee with
	int socialSecurityNumber = 0;
	char employeeName[21];
	int hourlyWage = 0;
	int hoursWorked = 0;
	int moneyCollected = 0;


	//boolean checker to check if data entered is valid
	bool isValid = false;

	//Variables that will hold the SSN, name, and amount collected of the 
	//employee who collected the least amount of money
	char nameOfMin[21];
	int socialSecurityOfMin;
	float minCollected;

	//Variables that will hold the SSN, name, and salary of the 
	//employee who had the highest salary
	char nameOfMax[21];
	int socialSecurityOfMax;
	float maxSalary = 0;

	//First employee to enter his information, then from the second employee
	//and on the information will be entered as part of the loop
	cout << "enter details, to end enter 0:" << endl;
	cin >> socialSecurityNumber;
	cin >> employeeName;
	cin >> hourlyWage;
	cin >> hoursWorked;
	cin >> moneyCollected;

	
	//These 4 if statements check that the numbers entered are valid
	isValid = numberChecker(socialSecurityNumber);
	if (isValid == false) {
		cout << "ERROR" << endl;
	}

	isValid = numberChecker(hourlyWage);
	if (isValid == false) {
		cout << "ERROR" << endl;
	}

	isValid = numberChecker(hoursWorked);
	if (isValid == false) {
		cout << "ERROR" << endl;
	}

	isValid = numberChecker(moneyCollected);
	if (isValid == false) {
		cout << "ERROR" << endl;
	}

	//Here the program creates a new instance of Employee using the user-entered values
	Employee placeHolder(socialSecurityNumber, employeeName, hourlyWage, hoursWorked, moneyCollected);
	
	//Initializing values of the place holders of the employee who
	//raised the least amount of money and the employee with the 
	//highest salary
	strcpy(nameOfMin, placeHolder.getName());
	socialSecurityOfMin = placeHolder.getSocialSecurityNumber();
	minCollected = placeHolder.getMoneyRaised();
	strcpy(nameOfMax, placeHolder.getName());
	socialSecurityOfMax = placeHolder.getSocialSecurityNumber();
	maxSalary = placeHolder.getTotalSalary();

	//boolean checker for the while loop to iterate if it is true 
	//that there are more employees to enter into the system
	bool isMore = true;

	//while loop to allow the user to enter more employees into the 
	//system and then it checks if the new employee is has the 
	//lowest amount collected or the highest salary, and
	//will change the values accordingly
	while (isMore) {
		
		cin >> socialSecurityNumber;
		if (socialSecurityNumber == 0) {
			break;
		}
		cin >> employeeName;


		cin >> hourlyWage;

		cin >> hoursWorked;

		cin >> moneyCollected;

		//These 4 if statements check that the numbers entered are valid
		isValid = numberChecker(socialSecurityNumber);
		if (isValid == false) {
			cout << "ERROR" << endl;
			continue;
		}

		isValid = numberChecker(hourlyWage);
		if (isValid == false) {
			cout << "ERROR" << endl;
			continue;
		}

		isValid = numberChecker(hoursWorked);
		if (isValid == false) {
			cout << "ERROR" << endl;
			continue;
		}

		isValid = numberChecker(moneyCollected);
		if (isValid == false) {
			cout << "ERROR" << endl;
			continue;
		}
	
		Employee placeHolder(socialSecurityNumber, employeeName, hourlyWage, hoursWorked, moneyCollected);

		//checks if the newest employee entered into the system is the
		//employee who collected the least amount of money, and then 
		//put his details into the varibales of minCollected
		if (placeHolder.getMoneyRaised() < minCollected) {
			strcpy(nameOfMin, placeHolder.getName());
			socialSecurityOfMin = placeHolder.getSocialSecurityNumber();
			minCollected = placeHolder.getMoneyRaised();
		}

		//checks if the newest employee entered into the system is the
		//employee who has the highest salary, and then puts his 
		//details into the employee with the maxSalary fields
		if (placeHolder.getTotalSalary() > maxSalary) {
			strcpy(nameOfMax, placeHolder.getName());
			socialSecurityOfMax = placeHolder.getSocialSecurityNumber();
			maxSalary = placeHolder.getTotalSalary();
		}

	}
	
	//print out the employee infomation of the employee who collected
	//the least amount of money.
	cout << "minimum collected: " << socialSecurityOfMin << " " << nameOfMin << " " << minCollected << endl;

	//print out the information of the employee who had the highest salary
	cout << "highest salary: " << socialSecurityOfMax << " " << nameOfMax << " " << maxSalary;

}

/*
Example of accurate output:

enter details, to end enter 0:
1
aaa
10
10
1000
2
bbb
100
100
1000

0
minimum collected: 1 aaa 1000
highest salary: 2 bbb 10100
*/


