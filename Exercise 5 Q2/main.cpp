/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 5 Question 1
*
* This is the given main file, driver function.
* It takes input of 2 Lists and then 
* performs the 3 global List operation on the Lists:
* 1) merges the 2 Lists
* 2) makes the new List into a set
* 3) reverses the set
*/


#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}

/*
 Test Example of the Code Working:

enter sorted values for the first list:
5
4
3
2
1
3
enter sorted values for the second list:
9
8
7
6
5
-3
-5
-999
-9999
-10999
9
the new merged list: 9 8 7 6 5 5 4 3 2 1 -3 -5 -999 -9999 -10999
the new merged set: 9 8 7 6 5 4 3 2 1 -3 -5 -999 -9999 -10999
the new merged reverse: -10999 -9999 -999 -5 -3 1 2 3 4 5 6 7 8 9
*/