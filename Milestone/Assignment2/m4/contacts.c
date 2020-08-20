/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* namePtr) { //Executing function by following caller function. I used namePtr as a variable which can be used in the function below freely.
	int result;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", namePtr->firstName); //'->' stands for pointing the address which the value is stored in.
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	result = yes(); //call the function yes to judge.
	if (result == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", namePtr->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", namePtr->lastName);
	clearKeyboard();

}

// getAddress:
void getAddress(struct Address *addressPtr) { //Executing function by following caller function.
	
	int result;

	printf("Please enter the contact's street number: ");
	addressPtr->streetNumber = getInt(); //call the function getInt to get the value.
	printf("Please enter the contact's street name: ");
	scanf(" %35[^\n]", addressPtr->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	result = yes(); //get the function yes.
	if (result == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &addressPtr->apartmentNumber);
		clearKeyboard(); //clearing buffer.
	}
	else
		addressPtr->apartmentNumber = 0;

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", addressPtr->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", addressPtr->city);
	clearKeyboard();

}

// getNumbers:
void getNumbers(struct Numbers *numbersPtr) {
	int result;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbersPtr->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	result = yes(); //call the function named yes.
	if (result == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbersPtr->home);

	} else
		strcpy(numbersPtr->home, "\0"); // copy string at second address to the first one.

	printf("Do you want to enter a business phone number? (y or n): ");
	result = yes();

	if (result == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbersPtr->business);
	} else 
		strcpy(numbersPtr->business, "\0");

}

// getContact:
void getContact(struct Contact *contactPtr) // call the 3 functions I made.
{
	getName(&(*contactPtr).name);
	getAddress(&(*contactPtr).address);
	getNumbers(&(*contactPtr).numbers);
}