/* -------------------------------------------
Name: Lee Sang Hyuk          
Student number: 129405171
Email: givemesomefoodplz@gmail.com          
Section: SMM       
Date: 4/11/2018           
----------------------------------------------
Assignment: 2
Milestone:  4
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


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
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
		printf("\n");
		if (option_answer == EOF || option_answer == 0 || NL != '\n')
			clearKeyboard(); //If the conditions above are matched, clear the buffer.

		else if ((option_choice >= 0) && (option_choice <= 6) && (NL = '\n')) // to make a conditions invidividually.
			break;
		else {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
			scanf("%d", &option_choice);
			clearKeyboard(); //clearing the buffer.
		}
	} while (option_choice < 0 || option_choice > 6);

	return option_choice; //return the option_choice value.

}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	struct Contact contact[MAXCONTACTS] = {
		{
			{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } },
			{
				{ "Maggie", "R.", "Greene" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9051112222", "9052223333", "9053334444" } },
				{
					{ "Morgan", "A.", "Jones" },
					{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
					{ "7051112222", "7052223333", "7053334444" } },
					{
						{ "Sasha",{ '\0' }, "Williams" },
						{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
						{ "9052223333", "9052223333", "9054445555" } },
	};

	int contact_choice;
	int flag = 0; //make a flag to get in the function.
	
	while (flag == 0)
	{
		contact_choice = menu();
		switch (contact_choice) { // match the contact_choice with the cases below.
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause(); //call the function named pause to make a pause.
			
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			
			break;
		case 6:
			sortContacts(contact, MAXCONTACTS);
			pause();
			
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			flag = yes();
			break;

		default:
			break;
		}
		printf("\n");

	} 
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
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
	int i, index = -1; 
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) //If they are identical, execute the function below
			index = i; //as instruction, if they(cell number in contacts struct, cellNum) are matched retrun the index positioned in the array
	}

	return index; //if they are not matched, return the index value as -1.
}

// displayContactHeader
void displayContactHeader(void)
{
	
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int size)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}

// displayContact:
void displayContact(const struct Contact* contactptr)
{
	if (strcmp(contactptr->name.middleInitial, "\0") == 0) // address->member is same as *(address).member the reason why we use -> is to make it more clear.
		printf(" %s %s\n", contactptr->name.firstName, contactptr->name.lastName);
	else
		printf(" %s %s %s\n", contactptr->name.firstName, contactptr->name.middleInitial, contactptr->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contactptr->numbers.cell, contactptr->numbers.home, contactptr->numbers.business);
	if (contactptr->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contactptr->address.streetNumber, contactptr->address.street, contactptr->address.apartmentNumber, contactptr->address.city, contactptr->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contactptr->address.streetNumber, contactptr->address.street, contactptr->address.city, contactptr->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	int k, contact_count = 0;
	displayContactHeader(); //call the displayContactHeader function
	for (k = 0; k < size; k++)
	{
		if (*contact[k].numbers.cell > 0)
		{
			displayContact(&contact[k]); //call the function based on the contact[k].
			contact_count++;
		}
	}
	displayContactFooter(contact_count);

}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	char cellNum[11];
	int index;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum); //To check if the number is 10, call the function.
	index = findContactIndex(contact, size, cellNum);
	if (index > 0) {
		printf("\n");
		displayContact(&contact[index]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}

// addContact:
void addContact(struct Contact contact[], int size)
{
	int i, j, contact_count = 0;

	for (i = 0; i < size; i++)
	{
		if (strlen((contact[i]).numbers.cell) != 0) //If there is a space, beyond the address to type another one.
			contact_count++;
	}

	if (contact_count == size) //If the space is full, print the caution below.
		printf("*** ERROR: The contact list is full! ***\n");
	else
	{
		for (j = 0; j < size; j++)
		{
			if (strlen((contact[j]).numbers.cell) == 0)
			{
				getContact(&contact[j]); //To add a new contact, call the function getContact.
				printf("--- New contact added! ---\n");
				j = size; //Initialize the size as a new value for j.
			}
		}
	}

}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
	int update_1, update_2, update_3;
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	int index = findContactIndex(contact, size, cellNum);

	if (index < 0)
		printf("*** Contact NOT FOUND ***\n");
	else 
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[index]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		update_1 = yes();
		if (update_1 == 1)
			getName(&contact[index].name);

		printf("Do you want to update the address? (y or n): ");
		update_2 = yes();
		if (update_2 == 1)
			getAddress(&contact[index].address);

		printf("Do you want to update the numbers? (y or n): ");
		update_3 = yes();
		if (update_3 == 1) {
			getNumbers(&contact[index].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	int index = findContactIndex(contact, size, cellNum);
	if (index < 0)
		printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		int answer = yes();
		if (answer == 1) {
			strcpy((contact[index]).numbers.cell, "\0");
			printf("--- Contact deleted! ---\n");
		}

	}
}


// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
	int i, j;
	struct Contact temp = {
		{
			{ '\0' , '\0' , '\0' },
			{ 0, '\0' , 0, '\0', '\0' },
			{ '\0' , '\0' , '\0' }
		}
	};


	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(contact[j].numbers.cell, contact[j + 1].numbers.cell) > 0) { //compare the index between the first string and the second one based on alphabetical order.
				temp = contact[j];
				contact[j] = contact[j + 1]; //changing the sort.
				contact[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}