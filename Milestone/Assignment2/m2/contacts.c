/* -------------------------------------------
Name: Lee Sang Hyuk
Student number: 129405171
Email: givemesomefoodplz@gmail.com
Section: SMM
Date: 3/28/2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* namePtr) { //Executing function by following caller function. I used namePtr as a variable which can be used in the function below freely.
	char answer; //redefining char answer for using in this function.
	int result;

	printf("Please enter the contact's first name: ");
	scanf("%s", namePtr->firstName); //'->' stands for pointing the address which the value is stored in.
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);
	result = yes(); //call the function yes to judge.
	if (result == 1) { 
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", namePtr->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", namePtr->lastName);

}

// getAddress:
void getAddress(struct Address *addressPtr) { //Executing function by following caller function.
	char answer;
	int result;

	printf("Please enter the contact's street number: ");
	scanf("%d", &addressPtr->streetNumber);
	addressPtr->streetNumber = getInt(); //call the function getInt to get the value.
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", addressPtr->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c", &answer);
	result = yes(); //get the function yes.
	if (result == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &addressPtr->apartmentNumber);
		addressPtr->apartmentNumber = getInt(); 
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", addressPtr->postalCode); 
	printf("Please enter the contact's city: ");
	scanf("%s", addressPtr->city);

}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers *numbersPtr) {
	int result;
	
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", numbersPtr->cell);

		printf("Do you want to enter a home phone number? (y or n): ");
		result = yes(); //call the function named yes.
		if (result == 1)
		{
			printf("Please enter the contact's home phone number: ");
			scanf("%s", numbersPtr->home);

		}

		printf("Do you want to enter a business phone number? (y or n): ");
		result = yes();

		if (result == 1)
		{
			printf("Please enter the contact's business phone number: ");
			scanf("%s", numbersPtr->business);
		}

}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact *contactPtr) // call the 3 functions I made.
{
	getName(&(*contactPtr).name);
	getAddress(&(*contactPtr).address);
	getNumbers(&(*contactPtr).numbers);
}