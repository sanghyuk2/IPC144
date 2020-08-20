/* -------------------------------------------
Name: Lee Sang Hyuk
Student number: 129405171
Email: givemesomefoodplz@gmail.com
Section: SMM
Date: 2018/3/20
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name* namePtr) { //Executing function by following caller function. I used namePtr as a variable which can be used in the function below freely.
	char answer; //redefining char answer for using in this function.

	printf("Please enter the contact's first name: ");
	scanf("%s", namePtr->firstName); //'->' stands for pointing the address which the value is stored in.
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'y' || answer == 'Y') //If the condition is satisfied, execute the function below.
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", namePtr->middleInitial);
		printf("Please enter the contact's last name: ");
		scanf("%s", namePtr->lastName);
	}

}


// getAddress:
void getAddress(struct Address *addressPtr) { //Executing function by following caller function.
	char answer;
	printf("Please enter the contact's street number: ");
	scanf("%d", &addressPtr->streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%s", addressPtr->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'y' || answer == 'Y') //If the condition is satisfied, execute the function below.
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &addressPtr->apartmentNumber);
		printf("Please enter the contact's postal code: ");
		scanf(" %7[^\n]", addressPtr->postalCode); //'%7[^\n]' stands for accepting space in the test user typed in scanf.
		printf("Please enter the contact's city: ");
		scanf("%s", addressPtr->city);
	}

}


// getNumbers:
void getNumbers(struct Numbers *numbersPtr) {
	char answer;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &answer);
	if (answer == 'y' || answer == 'Y') //If the condition is satisfied, execute the function below.
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", numbersPtr->cell);
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &answer);
		if (answer == 'y' || answer == 'Y')
		{
			printf("Please enter the contact's home phone number: ");
			scanf("%s", numbersPtr->home);
			printf("Do you want to enter a business phone number? (y or n): ");
			scanf(" %c", &answer);
			if (answer == 'y' || answer == 'Y')
			{
				printf("Please enter the contact's business phone number: ");
				scanf("%s", numbersPtr->business);
			}
		}
	}

}


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contactPtr) {

}