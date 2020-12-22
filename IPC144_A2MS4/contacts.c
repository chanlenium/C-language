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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+


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
    else if (option == 0) {
        *name->middleInitial = '\0';
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
void getNumbers(struct Numbers* numbers)
{
    int option;

    printf("Please enter the contact's cell phone number: ");
    scanf("%10s", numbers->cell);
    clearKeyboard();
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10s", numbers->home);
        clearKeyboard();
        getTenDigitPhone(numbers->home);
    }
    else if (option == 0) {
        *numbers->home = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    option = yes();
    if (option == 1)
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10s", numbers->business);
        clearKeyboard();
        getTenDigitPhone(numbers->business);
    }
    else if (option == 0) {
        *numbers->business = '\0';
    }
}

// getContact:
void getContact(struct Contact* contact)
{
    getName(&(contact->name));
    getAddress(&(contact->address));
    getNumbers(&(contact->numbers));
}