/* -------------------------------------------
Name: Lee Sang Hyuk
Student number: 129405171
Email: givemesomefoodplz@gmail.com
Section: SMM
Date: 2018/4/5
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


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
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers *numbersPtr) {
	int result;

	printf("Please enter the contact's cell phone number: ");
	scanf("%s", numbersPtr->cell);
	getTenDigitPhone(numbersPtr->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	result = yes(); //call the function named yes.
	if (result == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%s", numbersPtr->home);
		getTenDigitPhone(numbersPtr->home);

	}

	printf("Do you want to enter a business phone number? (y or n): ");
	result = yes();

	if (result == 1)
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%s", numbersPtr->business);
		getTenDigitPhone(numbersPtr->business);

	}

}


// getContact
void getContact(struct Contact *contactPtr) // call the 3 functions I made.
{
	getName(&(*contactPtr).name);
	getAddress(&(*contactPtr).address);
	getNumbers(&(*contactPtr).numbers);
}
