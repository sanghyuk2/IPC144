/* -------------------------------------------
Name: Lee Sang Hyuk
Student number:129405171
Email: givemesomefoodplz@gmail.com
Section: SMM
Date: 2018/3/13
----------------------------------------------
Assignment: 1
Milestone:  1
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
