/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 4 (only 1 question)
* 
* Header file for the Account class, which is a 
* class that represents bank accounts.
*/
#pragma once
#include <ostream>
#include <string>
using namespace std;

class Account
{
private:
	int accountNumber;
	int code;
	int balance;
	string email;
	static int sumWithdraw;
	static int sumDeposit;
public:

	static int getSumWithdraw();
	static int getSumDeposit();

	Account();
	Account(int, int, int, string);

	int getAccountNumber();
	int getCode();

	void setBalance(int);
	int getBalance();

	void setEmail(string);
	string getEmail();

	void withdraw(int);
	void deposit(int);

	friend istream& operator>>(istream& os, Account& account);


};
