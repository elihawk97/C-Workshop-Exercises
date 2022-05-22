/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 4 (only 1 question)
*
* This is the given Driver function to test the methods.
* I added in some try-catch statements for user-input
* validation.
*
* This program creates 10 bannk account objects and then
* performs the method operations on them.
*/

#include <iostream>
#include "Account.h"
#include "Clock.h"

using namespace std;

enum ACTION {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_DEPOSIT,
	SUM_WITHDRAW
};
ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << "\n";
	int x;
	cin >> x;
	return (ACTION)x;
}
int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i >= size)
		throw "ERROR: no such account number\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
	cout << c << "\t";
	switch (ac) {
	case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
	case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the deposit:\n ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
	for (int j = 0; j < i; j++)
		if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
			throw "ERROR: account number must be unique!\n";
}
int main() {
	const int SIZE = 10;

	Clock c(8, 0, 0);

	Account bank[SIZE];
	cout << "enter account number, code and email for " << SIZE << " accounts:\n" << endl;
	for (int i = 0; i < SIZE; i++) {
		try {
			cin >> bank[i];
			checkAccount(bank, i);
		}
		catch (const char* msg) {
			cout << c << '\t' << msg << endl;
			i--;
		}
	}
	ACTION ac = menu();
	while (ac) {
		cout << "\n";
		switch (ac) {
		case BALANCE:
			getBalance(bank, SIZE, c);
			break;
		case WITHDRAW:
			try {
				cashWithdraw(bank, SIZE, c);
			}
			catch (const char* errorMsg) {
				cout << c << "\t" << errorMsg << endl;
			}
			break;
		case DEPOSIT:
			try {
				cashDeposit(bank, SIZE, c);
			}
			catch (const char* errorMsg) {
				cout << c << "\t" << errorMsg << endl;
			}
			break;
		case SUM_DEPOSIT:c += 60;
			printTransaction(bank[0], SUM_DEPOSIT, c);
			break;
		case SUM_WITHDRAW:c += 60;
			printTransaction(bank[0], SUM_WITHDRAW, c);
		}

		ac = menu();
	}

	return 0;
}

/*
Code Example:

enter account number, code and email for 10 accounts:

1
1234
w@r.com
2
1234
w@e.com
3
1234
rfsdfasf@asdfas.com
4
1234
adsfasdf213@asdf.co.il
5
1234
sadfas@sad.com
6
1234
eli@hawk.com
7
1234
eli.h@gmail.com
8
1234
rel@sd.com
9
1234
w@com.com
9
1234
e.2@gmail.com
08:00:00        ERROR: account number must be unique!

10
12345
e@g.com
08:00:00        ERROR: code must be of 4 digits!
10
1234
elihawk.com
08:00:00        ERROR: email must contain @!
10
1234
eli@hawk.conm
08:00:00        ERROR: email must end at .com or .co.il!
10
1234
elihawk@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
1

please enter account number:
1
please enter the code:
1234
08:00:20        account #: 1    balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2

please enter account number:
1
please enter the code:
1234
enter the amount of the deposit:
 10000
08:00:50        account #: 1    new balance: 10000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
1

please enter account number:
1
please enter the code:
1234
08:01:10        account #: 1    balance: 10000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2

please enter account number:
1
please enter the code:
1234
enter the amount of the deposit:
 10001
08:01:10        ERROR: cannot deposit more than 10000 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3

please enter account number:
1
please enter the code:
1234
enter the amount of money to withdraw:
 2500
08:02:00        account #: 1    new balance: 7500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3

please enter account number:
4
please enter the code:
1234
enter the amount of money to withdraw:
 2600
08:02:00        ERROR: cannot withdraw more than 2500 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3

please enter account number:
6
please enter the code:
12345
08:02:00        ERROR: wrong code!

enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
4

08:03:00        sum of all deposits: 10000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
5

08:04:00        sum of all withdrawals: 2500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
0
*/