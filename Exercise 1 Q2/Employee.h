//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This program allows the user to enter information about
//employees working at the "Give From the Heart" organization
//and it will output the employee that raised the least amount
//of money and the employee that had the highest salary
//this is the class object for the "Employee" object of the program
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>

class Employee {
private:
    int SocialSecurityNumber;
    char name[21];
    int hoursWorked;
    float hourlyWage;
    float moneyRaised;
    float totalSalary;
    void calculateTotalSalary();


public:
    Employee();
    Employee(int socialSecurity, const char *employeeName, float wage, int numberOfHours, int collected);
    void setSocialSecurityNumber(int);
    int getSocialSecurityNumber() const;

    void setName(const char *employeeName);
    char *getName() const;

    void setHoursWorked(int);
    int getHoursWorked() const;

    void setHourlyWage(float);
    float getHourlyWage() const;

    void setMoneyRaised(float);
    float getMoneyRaised() const;
    
    float getTotalSalary();


};
#endif