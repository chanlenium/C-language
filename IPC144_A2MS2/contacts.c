//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Date:           20200314             
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

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
void getName(struct Name* name)
{
    char c; int i; int option;


    printf("Please enter the contact's first name: ");
    //scanf("%30[^\n]%*c", name->firstName);
    for (i = 0; i < 29 && (c = getchar()) != '\n'; i++)
    {
        name->firstName[i] = c;
    }
    name->firstName[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }


    printf("Do you want to enter a middle initial(s)? (y or n): ");
    option = yes();
    if (option == 1)
    {
        //scanf("%7[^\n]%*c", name->middleInitial);
        printf("Please enter the contact's middle initial(s): ");
        for (i = 0; i < 6 && (c = getchar()) != '\n'; i++)
        {
            name->middleInitial[i] = c;
        }
        name->middleInitial[i] = '\0';
        if (c != '\n') {
            clearKeyboard();
        }
    }


    printf("Please enter the contact's last name: ");
    //scanf("%35[^\n]%*c", name->lastName);
    for (i = 0; i < 34 && (c = getchar()) != '\n'; i++)
    {
        name->lastName[i] = c;
    }
    name->lastName[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }
}


// getAddress:
void getAddress(struct Address* address)
{
    char c;
    int i, option, flag = 0;

    //scanf("%d%*c", &address->streetNumber);
    printf("Please enter the contact's street number: ");
    do
    {
        address->streetNumber = getInt();
        if (address->streetNumber < 0)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
        else
        {
            flag = 1;
        }

    } while (flag == 0);


    printf("Please enter the contact's street name: ");
    //scanf("%40[^\n]%*c", address->street);
    for (i = 0; i < 39 && (c = getchar()) != '\n'; i++)
    {
        address->street[i] = c;
    }
    address->street[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }


    printf("Do you want to enter an apartment number? (y or n): ");
    option = yes();
    //scanf("%c%*c", &option);
    if (option == 1)
    {
        flag = 0;
        printf("Please enter the contact's apartment number: ");
        //scanf("%d%*c", &address->apartmentNumber);
        do
        {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 0)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
            else
            {
                flag = 1;
            }

        } while (flag == 0);
    }


    printf("Please enter the contact's postal code: ");
    //scanf("%8[^\n]%*c", address->postalCode);
    for (i = 0; i < 7 && (c = getchar()) != '\n'; i++)
    {
        address->postalCode[i] = c;
    }
    address->postalCode[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }


    printf("Please enter the contact's city: ");
    //scanf("%40[^\n]%*c", address->city);
    for (i = 0; i < 39 && (c = getchar()) != '\n'; i++)
    {
        address->city[i] = c;
    }
    address->city[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }
}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* numbers)
{
    char c;
    int i, option;

    printf("Please enter the contact's cell phone number: ");
    //scanf("%10[^\n]%*c", numbers->cell);
    for (i = 0; i < 10 && (c = getchar()) != '\n'; i++)
    {
        numbers->cell[i] = c;
    }
    numbers->cell[i] = '\0';
    if (c != '\n') {
        clearKeyboard();
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    //scanf("%c%*c", &option);
    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's home phone number: ");
        //scanf("%10[^\n]%*c", numbers->home);
        for (i = 0; i < 10 && (c = getchar()) != '\n'; i++)
        {
            numbers->home[i] = c;
        }
        numbers->cell[i] = '\0';
        if (c != '\n') {
            clearKeyboard();
        }
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    //scanf("%c%*c", &option);
    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's business phone number: ");
        //scanf("%10[^\n]%*c", numbers->business);
        for (i = 0; i < 10 && (c = getchar()) != '\n'; i++)
        {
            numbers->business[i] = c;
        }
        numbers->business[i] = '\0';
        if (c != '\n') {
            clearKeyboard();
        }
    }
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact* contact)
{
    getName(&(contact->name));
    getAddress(&(contact->address));
    getNumbers(&(contact->numbers));
}