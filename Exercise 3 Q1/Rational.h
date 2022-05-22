//Eli Hawk 563385586
//C++ Workshop
//Exercise 2 Question 1
//This is the header file for the Rational class
//this class is for Rational numbers and has the fields
//the numerator and denominator, this file also contains
//the declarations for the various methods
#include<iostream>

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational();
    Rational(int num, int denom);
    Rational(const Rational& source);
    void create();
    void create(int num, int denom);
    void setNumerator(int inputNum);
    void setDenominator(int inputDenom);
    int getNumerator() const;
    int getDenominator() const;
    void print() const;
    void rationalReduction();
    Rational add(Rational r2);
    bool operator==(const Rational& r2) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    Rational& operator++();
    Rational operator++(int dummy);
    Rational& operator--();
    Rational operator--(int dummy);
    Rational operator+(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    Rational operator-(const Rational& other) const;
}; 
