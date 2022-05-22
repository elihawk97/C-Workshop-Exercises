/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 2
*
* This is the driver class to test the functions of
* the RoundList class. The main prompts the user to
* choose an action to perform on the RoundList and 
* performs that method. The program terminates when
* the user enters 0. (This is the provided function
* in the assignment)
*/

#include "RoundList.h"
#include <iostream>
using namespace std;

enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY, PRINT
};

int main() {
	RoundList roundList;
	int choice;
	cout << "Enter your choice: \n";
	cin >> choice;
	while (choice != EXIT) {
		int num;
		switch (choice) {
		case ADD:
			cout << "Enter a number: \n";
			cin >> num;
			roundList.add(num);
			break;
		case ADD_TO_END:
			cout << "Enter a number: \n";
			cin >> num;
			roundList.addToEnd(num);
			break;
		case REMOVE_FIRST:
			try {
				roundList.removeFirst();
			}
			catch (const char* error) {
				//ignore error
			}
			break;
		case SEARCH:
			cout << "Enter a number: ";
			cin >> num;
			cout << roundList.search(num) << endl;
			break;
		case CLEAR:
			roundList.clear();
			break;
		case EMPTY:
			if (roundList.isEmpty())
				cout << "Empty" << endl;
			else
				cout << "Not empty" << endl;
			break;
		case PRINT:
			cout << roundList << endl;
			break;
		default: cout << "ERROR!" << endl;
		}
		cout << "Enter your choice: \n";
		cin >> choice;
	}
	return 0;
}

/*
--Test Code Example Running--
Enter your choice:
1
Enter a number:
3
Enter your choice:
1
Enter a number:
3
Enter your choice:
1
Enter a number:
5342
Enter your choice:
1
Enter a number:
532
Enter your choice:
1
Enter a number:
5234
Enter your choice:
2
Enter a number:
321
Enter your choice:
3
Enter your choice:
321
ERROR!
Enter your choice:
4
Enter a number: 321
5342
Enter your choice:
212
ERROR!
Enter your choice:
4
Enter a number: 5
532
Enter your choice:
5
Enter your choice:
6
Empty
Enter your choice:
6
Empty
Enter your choice:
7

Enter your choice:
7

Enter your choice:
1
Enter a number:
32
Enter your choice:
11
ERROR!
Enter your choice:
1
Enter a number:
32
Enter your choice:

1
Enter a number:
32
Enter your choice:
1
Enter a number:
867
Enter your choice:
7
867 32 32 32
Enter your choice:
6
Not empty
Enter your choice:
7
867 32 32 32
Enter your choice:
5
Enter your choice:
7

Enter your choice:
0
*/