/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 5 Question 1
*
* This is the given main file, driver function.
* It tests takes an input of a List and then has
* options for the user to perform any of the 4 
* operations on the List:
* 1) insert new element
* 2) remove an element from the list
* 3) Assign - copy one list to another
* 4) print a list
*/

#include "List.h"
enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };
int main()
{
	List lst;
	List lst2;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-4\n";
	cin >> choice;
	while (choice != EXIT)
	{
		switch (choice)
		{
		case INSERT:
			cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case REMOVE:
			cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		case ASSIGN:
			lst2 = lst;
			cout << "list 2: " << lst2 << endl;
			cout << "list 1: ";
		case PRINT:
			cout << lst << endl;
			break;
		default:cout << "ERROR\n";
		}
		cout << "choose 0-4\n";
		cin >> choice;
	}
	return 0;
}


/*
Test Example of Code Working
enter the list values
5
4
3
2
1
-3
-77
4
choose 0-4
1
enter a value to insert
3
choose 0-4
4
5 4 3 3 2 1 -3 -77
choose 0-4
2
enter a value to remove
3
choose 0-4
4
5 4 3 2 1 -3 -77
choose 0-4
2
enter a value to remove
3
choose 0-4
4
5 4 2 1 -3 -77
choose 0-4
3
list 2: 5 4 2 1 -3 -77
list 1: 5 4 2 1 -3 -77
choose 0-4
0
*/