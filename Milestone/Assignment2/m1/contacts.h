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


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
// Place your code here...
// NOTE: Modify the C String arrays sizes according to the
//       Assignment-2 Milestone-1 specifications
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};


// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...



//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name*);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address*);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers*);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact*);