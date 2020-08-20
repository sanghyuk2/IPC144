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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h> 


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	int NL;
	while ((NL = getchar()) != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	int value, flag = 1;
	char NL = 0;
	scanf("%d%c", &value, &NL);

	do {

		if (NL != '\n') //If the NL is not the new line, conduct the function below.
		{
			clearKeyboard(); //clearing the keyboard.
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &NL);
		}
		else
			flag = 0; //use flag to get out from the function.

	} while (flag == 1);

	return value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
	int InRange;

	InRange = getInt(); //Call the getInt function and the returned value.

	while (InRange < min || InRange > max) //If the returned value is in range between min and max.
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		scanf("%d", &InRange);
	}

	return InRange;
}


// yes:
int yes(void) {
	int result, flag = 1;
	char answer, NL = 0;


	scanf(" %c%c", &answer, &NL); //To accept the whitespace, make a blank before the '%'sign.

	while (flag == 1) //make a flag as a condition to conduct the function below.
	{
		if (NL != '\n' || (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')))
		{
			clearKeyboard(); //Call the clearKeyboard function to clear the buffer.
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &answer, &NL); //accept yes or no in the answer and accept the new line in the address named NL. 
		}
		else
			flag = 0; //make a flag as a 0 to get out of the function.
	}

	if (answer == 'y' || answer == 'Y')
		result = 1;
	else if (answer == 'n' || answer == 'N')
		result = 0;

	return result; //return the result value.
}


// menu:
int menu(void) {
	int option_choice;
	char NL = 0;
	do {

		printf("Contact Management System\n");
		printf("-------------------------\n");
		printf("1. Display contacts\n");
		printf("2. Add a contact\n");
		printf("3. Update a contact\n");
		printf("4. Delete a contact\n");
		printf("5. Search contacts by cell phone number\n");
		printf("6. Sort contacts by cell phone number\n");
		printf("0. Exit\n\n");
		printf("Select an option:> ");

		int option_answer = scanf("%d%c", &option_choice, &NL);

		if (option_answer == EOF || option_answer == 0 || NL != '\n')
			clearKeyboard(); //If the conditions above are matched, clear the buffer.

		else if ((option_choice >= 0) && (option_choice <= 6) && (NL = '\n')) // to make a conditions invidividually.
			break;
		else {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
			scanf("%d", &option_choice);
			clearKeyboard();
		}
	} while (option_choice < 0 || option_choice > 6);

	return option_choice; //return the option_choice value.

}


// ContactManagerSystem:
void ContactManagerSystem(void) {
	int contact_choice;
	int flag = 1;
	char yes_or_no;
	do {
		contact_choice = menu();
		switch (contact_choice) { // match the contact_choice with the cases below.
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause(); //call the function named pause to make a pause.
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			scanf(" %c", &yes_or_no);
			printf("\n");
			if (yes_or_no == 'Y' || yes_or_no == 'y') {
				printf("Contact Management System: terminated\n");
				flag = 0; // decide a flag as 0 to get out of the function.
				break;
			}
			else if (yes_or_no == 'N' || yes_or_no == 'n')
				break;
		default:
			break;
		}

	} while (flag == 1);
}


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int);
{

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact*)
{

}



// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact[], int)
{

}



// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact[], int)
{

}



// addContact:
// Put empty function definition below:
void addContact(struct Contact[], int)
{

}



// updateContact:
// Put empty function definition below:
void updateContact(struct Contact[], int)
{

}



// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact[], int)
{

}



// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact[], int)
{

}