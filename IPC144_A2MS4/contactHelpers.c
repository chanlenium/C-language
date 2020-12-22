//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Date:           20200323
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

#include <ctype.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
    printf("\n");
}


// getInt:
int getInt(void)
{
    int inputVal, rc, flag = 0;
    char NL = 'x';

    do
    {
        rc = scanf("%d%c", &inputVal, &NL);
        if (rc < 2) {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else if (NL != '\n') {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return inputVal;
}


// getIntInRange:
int getIntInRange(int min, int max)
{
    int inputVal, flag = 0;
    do
    {
        inputVal = getInt();
        if ((inputVal < min) || (inputVal > max))
        {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return inputVal;
}


// yes:
int yes(void)
{
    char inputVal, NL, returnVal = 0;
    int rc, flag = 0;

    do
    {
        rc = scanf("%c%c", &inputVal, &NL);
        if (rc == 0) {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        else if (NL != '\n') {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        else if (!((inputVal == 'Y') || (inputVal == 'y') || (inputVal == 'N') || (inputVal == 'n'))) {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>:");
            clearKeyboard();
        }
        else {
            if ((inputVal == 'Y') || (inputVal == 'y')) {
                returnVal = 1;
            }
            else {
                returnVal = 0;
            }
            flag = 1;
        }
    } while (flag == 0);

    return returnVal;
}


// menu:
int menu(void)
{
    int inputVal, rc, flag = 0;
    char NL = 'x';

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\nSelect an option:> ");

    do
    {
        rc = scanf("%d%c", &inputVal, &NL);
        
        if (rc == 0) {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
        else if (NL != '\n') {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
        else if ((inputVal < 0) || (inputVal > 6)) {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return inputVal;
}


// contactManagerSystem:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] = { 
        { { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } },
        { { "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } },
        { { "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
        { { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } },
    };

    int inputVal, exit_YN, flag = 0;

    do {
        inputVal = menu();

        if (inputVal == 1) {
            displayContacts(&contacts[0], MAXCONTACTS);
            pause();
        }
        else if (inputVal == 2) {
            addContact(&contacts[0], MAXCONTACTS);
            pause();
        }
        else if (inputVal == 3) {
            updateContact(&contacts[0], MAXCONTACTS);
            pause();
        }
        else if (inputVal == 4) {
            deleteContact(&contacts[0], MAXCONTACTS);
            pause();
        }
        else if (inputVal == 5) {
            searchContacts(&contacts[0], MAXCONTACTS);
            pause();
        }
        else if (inputVal == 6) {
            sortContacts(&contacts[0], MAXCONTACTS);
            pause();
        }
        else {
            printf("\nExit the program? (Y)es/(N)o: ");
            exit_YN = yes();
            if (exit_YN == 1)
            {
                printf("\nContact Management System: terminated\n");
                flag = 1;
            }
            else {
                printf("\n");
            }
        }
    } while (flag == 0);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1, digitNum = 0;

    while (needInput == 1) {
        digitNum = 0;
        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10) {
            int i = 0;
            for (i = 0; i < 10; i++) {
                if (isdigit(phoneNum[i]))
                    digitNum++;
            }
            if (digitNum == 10) {
                needInput = 0;
            }
            else {
                printf("Enter a 10-digit phone number: ");
                scanf("%10s", phoneNum);
                clearKeyboard();
            }
        }            
        else {
            printf("Enter a 10-digit phone number: ");
            scanf("%10s", phoneNum);
            clearKeyboard();
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int returnVal = -1;
    int i = 0;
    for (i = 0; i < size; i++) {
        if (strcmp((contacts[i]).numbers.cell, cellNum) == 0) {
            returnVal = i;
        }
    }
    return returnVal;
}

// displayContactHeader
void displayContactHeader(void) {
    printf("\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n", count);
    printf("\n");
}


// displayContact:
void displayContact(const struct Contact* contact) {
    if (strlen(contact->name.middleInitial) > 0) {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }

    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {

    displayContactHeader();

    int count = 0;
    int i = 0;
    for (i = 0; i < MAXCONTACTS; i++) {
        if (strlen(contacts[i].numbers.cell) != 0) {
            displayContact(&contacts[i]);
            count++;
        }
    }

    displayContactFooter(count);
}


// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
    char inputCellNum[11];
    int searchResultVal;

    printf("\n");
    printf("Enter the cell number for the contact: ");
    scanf("%s", inputCellNum);
    clearKeyboard();

    getTenDigitPhone(inputCellNum);
    searchResultVal = findContactIndex(contacts, size, inputCellNum);
    if (searchResultVal == -1) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        printf("\n");
        displayContact(&contacts[searchResultVal]);
        printf("\n");
    }
}


// addContact:
void addContact(struct Contact contacts[], int size) {
    printf("\n");

    int i = 0, slotAvailable = 0;

    do {
        if (strlen((contacts[i]).numbers.cell) == 0) {
            slotAvailable = 1;
        }
        else {
            i++;
        }
    } while (slotAvailable == 0 && i < size);

    if (i == size) {
        printf("*** ERROR: The contact list is full! ***\n");
        printf("\n");
    }
    else {
        getContact(&contacts[i]);
        printf("--- New contact added! ---\n");
        printf("\n");
    }
}


// updateContact:
void updateContact(struct Contact contacts[], int size) {
    printf("\n");

    char inputCellNum[11];
    printf("Enter the cell number for the contact: ");
    scanf("%10s", inputCellNum);
    clearKeyboard();
    getTenDigitPhone(inputCellNum);

    int updateYN = 0, searchIndex = findContactIndex(contacts, size, inputCellNum);

    if (searchIndex == -1) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[searchIndex]);
        printf("\n");

        printf("Do you want to update the name? (y or n): ");
        updateYN = yes();
        if (updateYN == 1) {
            getName(&(contacts[searchIndex].name));
        }

        printf("Do you want to update the address? (y or n): ");
        updateYN = yes();
        if (updateYN == 1) {
            getAddress(&(contacts[searchIndex].address));
        }

        printf("Do you want to update the numbers? (y or n): ");
        updateYN = yes();
        if (updateYN == 1) {
            getNumbers(&(contacts[searchIndex].numbers));
        }

        printf("--- Contact Updated! ---\n");
        printf("\n");
    }
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
    char inputCellNum[11];
    int deleteYN = 0, searchResultVal = -1;

    printf("\n");
    printf("Enter the cell number for the contact: ");
    scanf("%s", inputCellNum);
    clearKeyboard();
    searchResultVal = findContactIndex(contacts, size, inputCellNum);

    if (searchResultVal == -1) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        printf("\nContact found:\n");
        displayContact(&contacts[searchResultVal]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        deleteYN = yes();
        if (deleteYN == 1)
        {
            contacts[searchResultVal].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n");
            printf("\n");
        }
        else if (deleteYN == 0) {
            printf("\n");
        }
    }
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
    int i, j;
    struct Contact tempContacts;

    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[j+1].numbers.cell) > 0) {
                tempContacts = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = tempContacts;
            }
        }
    }
    printf("\n");
    printf("--- Contacts sorted! ---\n");
    printf("\n");
}