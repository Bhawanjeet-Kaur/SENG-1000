/*
* FILE : m2.cpp
* PROJECT : SENG1000- major assignment 2
* PROGRAMMER : 8958829
* FIRST VERSION : 2024-02-08
* DESCRIPTION :
* Write a program that calculates powers using a function that you create.
*/
#include <stdio.h>
#include <stdbool.h>
int getNum();
int powerCalculation(int, int);
int kCheckLoop = 0;
int main(void)
{
	int base = 1;
	int exponent = 1;
	int solution;
	int userChoice;
	while (kCheckLoop == 0)
	{
		printf("\n\nMenu:\n\t1. Change base\n\t2. Change exponent\n\t3. Display base raised to exponent\n\t4. Exit program\nOption ? ");
		userChoice = getNum();
		if (userChoice == 1)
		{
			printf("Enter new base: ");
			base = getNum();
			//continue;
		}
		else if (userChoice == 2)
		{
			printf("Enter new exponent: ");
			exponent = getNum();
			//continue;
		}
		else if (userChoice == 3)
		{
			solution = powerCalculation(base, exponent);
			printf("%d raised to the power of %d is %d\n", base, exponent, solution);
			//continue;
		}
		else if (userChoice == 4)
		{
			kCheckLoop = 1;
			//break;
		}
		else
		{
			printf("Invalid entry");
			//continue;
		}
	}
}
/*powerCalculation() function contains two parameters in it. It is taking in a base number and an exponent for that
* base number. The function will calculate the power of that base using while loop and an assignment operator.
*/
int powerCalculation(int base, int exponent)
{
	int calculatedPower = 1;
	while (exponent >= 1)
	{
		calculatedPower *= base;
		exponent--;
	}
	return calculatedPower;
}
/*getNum() function is a void function and is used to get an input from the user. And if the user does not enters any number, then the
* default number will be -1.
*/
#pragma warning(disable: 4996)
int getNum(void)
{
	/* we will see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: indent and brace this function consistent with
	your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}