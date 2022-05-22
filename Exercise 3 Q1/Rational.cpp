//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 1
//This is the method implementation file for the Rational class
//this class is for Rational numbers and has the fields
//the numerator and denominator, some methods include
//operator overloading for most of the common operations
//inlcluding +, -, *, /, o++, ++o, o--, --o, ==, !=, <=, >=
//It also has the constructors including a copy, default and
//regular constructor.

#include "Rational.h"
#include<iostream>
#include <cmath>
using namespace std;


//default constructor for class Rational
Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

/// <summary>
/// constructor with user-chosen values
/// </summary>
/// <param name="num"></param>
/// <param name="denom"></param>
Rational::Rational(int num, int denom) {
    numerator = num;
    denominator = denom;
}
 
/// <summary>
/// Copy Constructor
/// </summary>
Rational::Rational(const Rational& source) {
    numerator = source.numerator;
    denominator = source.denominator;
}




//setter for the numerator
void Rational::setNumerator(int inputNum) {
    numerator = inputNum;
}

//setter for the denominator with input validation
void Rational::setDenominator(int inputDenom) {
    //input validation before assigning the user-inputed value to denominator
    if (inputDenom > 0) {
        denominator = inputDenom;
    }
    else if (inputDenom == 0) {
        denominator = 1;
    }
    else {
        denominator = -(inputDenom);
        numerator = -(numerator);
    }
}

//getter for the numerator
int Rational::getNumerator() const {
    return numerator;
}

//getter for the denomerator
int Rational::getDenominator() const {
    return denominator;
}

/**
* Print function to print the ratioal number object to the console
*/
void Rational::print() const{
    if (numerator == 1 && denominator == 1) {
        std::cout << 1 << "\n";
    }
    std::cout << numerator << "/" << denominator << "\n";
}

//needs to be private---check how to do this
void Rational::rationalReduction() {
    //Store the numerator and denomenator as doubles for the division check to avoid unintended truncation for the while loop
    double num = getNumerator();
    double denom = getDenominator();

    bool foundDivider = false;
    double divider = num;
    //this will ensure that the initial number we are dividing by is less than or equal to both numbers 
    //since if we start dividing by a number greater than it, we will get a fraction in the numerator or denomerator
    if (denom < num) {
        divider = denom;
    }
    /**
       Divide the numeratorand denomerator by the lower of the 2 of them, and check if the both are divisible
       by that number, and if not we check if they are divisible by "divider - 1" until we reach 2 or a number
       that divides both the numerator and denomerator is found, and since it starts from the highest possible 
       divider, once the first divider is found, that will be the divider
    */
    while (divider > 1 and foundDivider == false) {
        if ((num / divider) == std::floor(num / divider) and (denom / divider) == std::floor(denom / divider)) {
            setNumerator(num / divider);
            setDenominator(denom / divider);
            foundDivider = true;
        }
        divider--;
    }

}

//Operator Overload Section

/// <summary>
/// + operator overload in order to add rational number objects together
/// </summary>
/// <param name="other">the Rational number object to be added to the rational number 
/// that called the method</param>
/// <returns> return a Rational that is the sum of the 2 rationals</returns>
Rational Rational::operator+(const Rational& r2) const
{    
    Rational temp;
    int num1 = numerator;
    int denom1 = denominator;

    int num2 = r2.numerator;
    int denom2 = r2.denominator;

    if (denom1 == denom2) {
        temp.denominator = denom1;
        temp.numerator = (num1 + num2);
        temp.rationalReduction();
        return temp;
    }
    //if they do not have the same denominator
    temp.setDenominator(denom1 * denom2);
    temp.setNumerator(num1 * denom2 + num2 * denom1);
    temp.rationalReduction();

    return temp;
}

/// <summary>
/// * operator overload in order to multiply rational number objects 
/// </summary>
/// <param name="other">the Rational number object to be multiplied to the rational  
/// number that called the method</param>
/// <returns> return a Rational that is the product of the 2 rationals</returns>
Rational Rational::operator*(const Rational& other) const
{
    Rational temp;
    temp.numerator = (numerator * other.numerator);
    temp.denominator = (denominator * other.denominator);
    temp.rationalReduction();
    return temp;
}

/// <summary>
/// / operator overload in order to divide rational number objects 
/// </summary>
/// <param name="other">the Rational number object to divide the rational number 
/// that called the method</param>
/// <returns>return a Rational that is the quotient of the 2 rationals</returns>
Rational Rational::operator/(const Rational& other) const
{
    Rational temp;
    temp.numerator = (numerator * other.denominator);
    temp.denominator = (denominator * other.numerator);
    temp.rationalReduction();
    return temp;
}

/// <summary>
/// - operator overload in order to add rational number objects together
/// </summary>
/// <param name="other">the Rational number object to divide the rational number 
/// that called the method</param>
/// <returns>return a Rational that is the quotient of the 2 rationals</returns>
Rational Rational::operator-(const Rational& r2) const{
    Rational temp;
    int num1 = numerator;
    int denom1 = denominator;

    int num2 = r2.numerator;
    int denom2 = r2.denominator;

    if (denom1 == denom2) {
        temp.denominator = denom1;
        temp.numerator = (num1 - num2);
        temp.rationalReduction();
        return temp;
    }
    //if they do not have the same denominator
    temp.denominator = (denom1 * denom2);
    temp.numerator = (num1 * denom2 - num2 * denom1);
    temp.rationalReduction();

    return temp;
}

/// <summary>
/// == operator overload, to allow easy comparison of 2 Rational objects
/// </summary>
/// <param name="other">the rightside operand for the comparison</param>
/// <returns>boolean: true if equal, false otherwise</returns>
bool Rational::operator==(const Rational& other) const
{
    Rational r1(numerator, denominator);
    Rational r2(other.numerator, other.denominator);
    r1.rationalReduction();
    r2.rationalReduction();
    return (r1.numerator == r2.numerator and r1.denominator == r2.denominator);
}

/// <summary>
/// != operator overload, to allow easily determine if 2 objects are not equal
/// </summary>
/// <param name="other">the rightside operand for the comparison</param>
/// <returns>boolean: true if not equal, false otherwise</returns>
bool Rational::operator!=(const Rational& other) const{
    return !(*this == other);
}

/// <summary>
/// < operator overload to check if the right side operand
/// is less than the rightside operand
/// </summary>
/// <param name="other">rightside operand Rational object</param>
/// <returns>boolean: true if less than, false otherwise</returns>
bool Rational::operator<(const Rational& other) const {
    double r1 = (numerator / (float)denominator);
    double r2 = (other.numerator / (float)other.denominator);
    if (r1 < r2) {
        return true;
    }
    return false;
}

/// <summary>
/// > operator overload to check if the right side operand
/// is greater than the rightside operand </summary>
/// <param name="other">rightside operand Rational object</param>
/// <returns>boolean: true if greater than, false otherwise</returns>
bool Rational::operator>(const Rational& other) const {
    double r1 = (numerator / (float)denominator);
    double r2 = (other.numerator / (float)other.denominator);
    if (r1 > r2) {
        return true;
    }
    return false;
}

/// <summary>
/// < operator overload to check if the right side operand
/// is less than or equal to the rightside operand 
/// </summary>
/// <param name="other">rightside operand Rational object</param>
/// <returns>boolean: true if less than or equal, false otherwise</returns>
bool Rational::operator<=(const Rational& other) const {
    double r1 = (numerator / (float)denominator);
    double r2 = (other.numerator / (float)other.denominator);
    if (r1 <= r2) {
        return true;
    }
    return false;
}

/// <summary>
/// >= operator overload to check if the right side operand
/// is greater than or equal to the rightside operand </summary>
/// <param name="other">rightside operand Rational object</param>
/// <returns>boolean: true if greater than orequal, false otherwise</returns>
bool Rational::operator>=(const Rational& other) const {
    double r1 = (numerator / (float)denominator);
    double r2 = (other.numerator / (float)other.denominator);
    if (r1 >= r2) {
        return true;
    }
    return false;
}

/// <summary>
/// ++o operator overload to increment a Rational object, this
/// increments then assigns the new value to the object set 
/// equal to it.
/// </summary>
/// <returns></returns>
Rational& Rational::operator++() // ++o
{
    Rational temp;//intialized to 1/1
    temp = (*this) + temp;
    temp.rationalReduction();
    *this = temp;
    return *this;
}

/// <summary>
/// o++ operator overload incrementer, to assign the object to 
/// another object and only then increment it
/// </summary>
/// <param name="dummy">int to tell the system that this
/// is the o++ method and not ++o</param>
/// <returns>return the original object before it was incremented</returns>
Rational Rational::operator++(int dummy) // o++
{
    Rational res = *this;
    Rational temp;
    temp = *this + temp; //calls the "+" method to add 1 to the rational object
    temp.rationalReduction();
    *this = temp;
    return res; //the original object, without the o++
}

/// <summary>
/// --o operator overload to decrement a Rational object, this
/// decrements then assigns the new value to the object set 
/// equal to it.
/// </summary>
/// <returns>the decremented object</returns>
Rational& Rational::operator--() // --o
{
    Rational temp;//intialized to 1/1
    temp = (*this) - temp;
    temp.rationalReduction();
    *this = temp;
    return *this; //returns the altered object
}

/// <summary>
/// o-- operator overload decrementer, to assign the object to the 
/// set equal to it and then decrement this object
/// </summary>
/// <param name="dummy">int to tell the system that this
/// is the o-- method and not --o</param>
/// <returns>the original object before decrmented</returns>
Rational Rational::operator--(int dummy) // o--
{
    Rational res = *this;
    Rational temp;
    temp = *this - temp; //calls the "+" method to add 1 to the rational object
    temp.rationalReduction();
    *this = temp;
    return res; //the original object, without the o++
}