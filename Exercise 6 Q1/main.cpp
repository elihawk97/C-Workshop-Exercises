/*
* Eli Hawk 563385586
* Workshop in C++
* Exercise 6 Question 1
*
* This is the driver class file to test the methods 
* of the Employee/PartTime/FullTime classes.
* The main function reads in 3 FullTime and 3 PartTime
* objects then prints them out. It throws an error if
* there is an error in the input. (The provided main 
* file in the assignment)
*/

#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
	    cout << "Enter employee details: " << endl;
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
	    cout << "Enter employee details: " << endl;
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}
	
	cout << endl;


	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl << endl;
	}
	return 0;
}



/* 
----Working Example----
werq
3
3
3
aaa
2341
1234
1234
dsgf
1234
1234
1234
adfgs
423523
1234
1234
1234
sefsrf
1234
543
5432
543
fdgs
5432
5432
412
4324
Employee: werq
Employee ID: 3
Year Seniority: 3
SalaryPerMonth: 0.250000
After Bonus: 0.3125
Employee: aaa
Employee ID: 2341
Year Seniority: 1234
SalaryPerMonth: 102.833336
After Bonus: 602.833
Employee: dsgf
Employee ID: 1234
Year Seniority: 1234
SalaryPerMonth: 102.833336
After Bonus: 602.833
Employee: adfgs
Employee ID: 423523
Year Seniority: 1234
SalaryPerMonth: 1234
After Bonus: 127396
Employee: sefsrf
Employee ID: 1234
Year Seniority: 543
SalaryPerMonth: 5432
After Bonus: 246298
Employee: fdgs
Employee ID: 5432
Year Seniority: 5432
SalaryPerMonth: 412
After Bonus: 148957
*/