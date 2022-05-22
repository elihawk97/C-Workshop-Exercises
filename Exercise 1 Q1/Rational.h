//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 2
//This is a class header file the class "Rational" which is a class
//of rational numbers that store the numerator and denominator as
//integers and contains the method names for the class
#include<iostream>

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational();
    Rational(int num, int denom);
    void create();
    void create(int num, int denom);
    void setNumerator(int inputNum);
    void setDenominator(int inputDenom);
    int getNumerator() const;
    int getDenominator() const;
    void print() const;
    void rationalReduction();
    Rational add(Rational r2);
    bool equal(Rational r2);
}; 
