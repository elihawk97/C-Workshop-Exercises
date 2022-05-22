//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This is a the implementation of the "Rational" objects methods
//which contains constructors, setter, getter, and other fucntions 
//for the "Rational" object

#include "Rational.h"
#include<iostream>
#include <cmath>


//default constructor for class Rational
Rational::Rational() {
    create();
}

//constructor with user-chosen values
Rational::Rational(int num, int denom) {
    create(num, denom);
}

/**
* This void method populates the rational number object with default values
* it is called on from the default constructor
* @return void
*/
void Rational::create() {
    setNumerator(1);
    setDenominator(1);
}

/**
* This void method populates the rational number object with user defined values
* it is called on from the constructor with user input values
* @param num - is the numerator for the rational number
* @param denom - is the denominator for the rational number
* @return void
*/
void Rational::create(int num, int denom) {
    setNumerator(num);
    setDenominator(denom);
}

//setter for the numerator
void Rational::setNumerator(int inputNum) {
    numerator = inputNum;
}

//setter for the denominator with input validation
void Rational::setDenominator(int inputDenom) {
    //input validation before assigning the user-inputed value to denominator
    //handling corner cases of inputs of 0 or negative numbers
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
    std::cout << numerator << "/" << denominator;
}

//private method, so the user can not directly access it
//this method reduces the fraction into simplest form
void Rational::rationalReduction() {
    //Store the numerator and denomenator as doubles for the division check 
    //to avoid unintended truncation for the while loop
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
    if(numerator == 0){
        denominator = 1;
    }

}

//addition of rational numbers 
Rational Rational::add(Rational r2) {
    //numerator
    Rational r3(1,1);
    int num1 = getNumerator();
    int denom1 = getDenominator();
    
    int num2 = r2.getNumerator();
    int denom2 = r2.getDenominator();

    if (denom1 == denom2) {
        r3.setDenominator(denom1);
        r3.setNumerator(num1 + num2);
        r3.rationalReduction();
        return r3;
    }
    //if they do not have the same denominator
    r3.setDenominator(denom1 * denom2);
    r3.setNumerator(num1 * denom2 + num2 * denom1);
    r3.rationalReduction();

    return r3;
}

//compares 2 rational numbers to check if they are equivalent
bool Rational::equal(Rational r2) {
    if (getNumerator() == r2.getNumerator() and getDenominator() == r2.getDenominator()) {
        return true;
    }
    return false;
}

