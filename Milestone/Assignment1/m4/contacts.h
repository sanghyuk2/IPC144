/* -------------------------------------------
Name: Lee Sang Hyuk
Student number:129405171
Email: givemesomefoodplz@gmail.com
Section: SMM
Date: 2018/3/13
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};

// Structure type Contact declaration
// Place your code here...
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name*); //This is the prototype of getName function.

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address*); //This is the prototype of getAddress function.

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers*); //This is the prototype of getNumbers function.
