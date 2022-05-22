/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 4 (only 1 question)
*
* Implementation file the Account class methods.
* This file has constructors, setters and getters,
* as well as operator overloading methods, ect..
*/

#include "Clock.h"
#include "Account.h"
#include <iostream>
using namespace std;


int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

/// <summary>
/// default constructor for the Account class
/// sets all three numerical values to 0
/// and the email to an empty to string.
/// </summary>
Account::Account() {
	accountNumber = 0;
	code = 0;
	balance = 0;
	email = "";
}

/// <summary>
/// Constructor that takes user input for the fields.
/// It checks to make sure that the code is a 4 digit number.
/// It checks that the email has a @ and .com or .co.il at the end.
/// </summary>
/// <param name="_accountNum">unique ID number for account</param>
/// <param name="_code">secret passcode for account</param>
/// <param name="_balance">Amount of money user has</param>
/// <param name="_email">user's email address</param>
Account::Account(int _accountNum, int _code, int _balance, string _email) {

	//variables to check that there is .com or .co.il in the email
	int dotComEnd = _email.size() - 4;
	int dotCoIlEnd = _email.size() - 6;
	size_t dotCom = _email.find(".com", dotComEnd);
	size_t dotCo = (_email.find(".co.il", dotCoIlEnd));

	//checks that the code is 4 digits
	if (_code <= 999 or _code > 9999) {
		throw("ERROR: code must be of 4 digits!");
	}
	//checks for a @ in the email
	else if ((_email.find("@")) == string::npos) {
		throw("ERROR: email must contain @!");
	}
	//checks for a .com / .co.il in the email
	else if (dotCom == string::npos and dotCo == string::npos) {
		throw("ERROR: email must end at .com or .co.il!");
	}

	accountNumber = _accountNum;
	code = _code;
	balance = _balance;
	email = _email;
}

/// <summary>
/// returns the user's account number
/// </summary>
/// <returns>int of account number</returns>
int Account::getAccountNumber() {
	return accountNumber;
}

/// <summary>
/// returns the user's passcode
/// </summary>
/// <returns>int of the code</returns>
int Account::getCode() {
	return code;
}

/// <summary>
/// method to set the update the account balance
/// after a deposite or withdrawal
/// </summary>
/// <param name="_addOrRemove"></param>
void Account::setBalance(int _addOrRemove) {
	balance += _addOrRemove;
}

/// <summary>
/// returns the user's account balance 
/// </summary>
/// <returns>int of user's account balance</returns>
int Account::getBalance() {
	return balance;
}


/// <summary>
/// alllows user to reset email linked to his account
/// </summary>
/// <param name="_email">the new email</param>
void Account::setEmail(string _email) {
	//variables to check that there is .com or .co.il in the email
	int dotComEnd = _email.size() - 4;
	int dotCoIlEnd = _email.size() - 6;
	size_t dotCom = _email.find(".com", dotComEnd);
	size_t dotCo = (_email.find(".co.il", dotCoIlEnd));

	//checks for a @ in the email
	if ((_email.find("@")) == string::npos) {
		throw("ERROR: email must contain @!");
	}
	//checks for a .com / .co.il in the email
	else if (dotCom == string::npos and dotCo == string::npos) {
		throw("ERROR: email must end at .com or .co.il!");
	}
	email = _email;
}

/// <summary>
/// returns the email linked to the account
/// </summary>
/// <returns>string of email address</returns>
string Account::getEmail() {
	return email;
}

/// <summary>
/// >> operator overload to input datat into an Account
/// instance.
/// </summary>
/// <param name="input">the istream</param>
/// <param name="account">the account object to input the data into</param>
/// <returns>the istream </returns>
std::istream& operator>>(std::istream& input, Account& account) {
	int newAccountNum = 0;
	int newPassword = 0;
	string newEmail = "";
	input >> newAccountNum >> newPassword >> newEmail;
	account = Account(newAccountNum, newPassword, 0, newEmail);
	return input;


}

/// <summary>
/// Method to allow user to withdraw money from his account.
/// It first checks the account to make sure this withdrawal
/// will not cause him to have an overdraft of more than 6,000
/// and then checks that the withdrawal is less than the max 
/// withdrawal amount of 2500NIS.
/// If all conditions are met the withdrawal is made.
/// </summary>
/// <param name="nis">int of money to withdraw</param>
void Account::withdraw(int nis) {
	if ((getBalance() - nis) < -6000) {
		throw("ERROR: cannot have less than - 6000 NIS!");
	}
	else if (nis > 2500) {
		throw("ERROR: cannot withdraw more than 2500 NIS!");
	}
	setBalance(-nis);
	sumWithdraw += nis;
}

/// <summary>
/// Allows user to deposit money into his account
/// with a max deposite amount of 10,000 NIS.
/// If the user attemptes to deposite >10000
/// an error is thrown.
/// </summary>
/// <param name="nis">int of money to be deposited</param>
void Account::deposit(int nis) {
	if (nis > 10000) {
		throw("ERROR: cannot deposit more than 10000 NIS!");
	}
	setBalance(nis);
	sumDeposit += nis;
}


/// <summary>
/// returns the value of all of the withdrawals summed up
/// </summary>
/// <returns>int of value of sum of withdrawals</returns>
int Account::getSumWithdraw() {
	return sumWithdraw;
}

/// <summary>
/// returns the value of all of the deposits summed up
/// </summary>
/// <returns>int of value of sum of deposits</returns>
int Account::getSumDeposit() {
	return sumDeposit;
}
