//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Date:           20200302  
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
int display(struct Name, struct Address, struct Numbers);

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

int main (void)
{

    // Declare variables here:
    struct Name contractName = { "" };
    struct Address contractAddr = { 0, "", 0, "", "" };
    struct Numbers contractPhoneNo = { "" };
    char option;
    int flag = 0;
    
    
    // Display the title
    printf("Contact Management System\n");
    printf("-------------------------\n");

    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    //scanf("%30s%*c", contractName.firstName);
    scanf("%30[^\n]%*c", contractName.firstName);
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%*c", &option);
    if ((option == 'y') || (option == 'Y'))
    {
        printf("Please enter the contact's middle initial(s): ");
        //scanf("%7s%*c", contractName.middleInitial);
        scanf("%7[^\n]%*c", contractName.middleInitial);
    }
    
    printf("Please enter the contact's last name: ");
    //scanf("%35s", contractName.lastName);
    scanf("%35[^\n]%*c", contractName.lastName);
    


    // Contact Address Input:
    do {
        printf("Please enter the contact's street number: ");
        scanf("%d%*c", &contractAddr.streetNumber);
        if (contractAddr.streetNumber <= 0) {
            printf("This field should enforce values grater than 0!!\n");
            flag = 1;
        }
        else {
            flag = 0;
        }
    } while (flag == 1);
    
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", contractAddr.street);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%*c", &option);
    if ((option == 'y') || (option == 'Y'))
    {
        do {
            printf("Please enter the contact's apartment number: ");
            scanf("%d%*c", &contractAddr.apartmentNumber);
            if (contractAddr.apartmentNumber <= 0) {
                printf("This field should enforce values grater than 0!!\n");
                flag = 1;
            }
            else {
                flag = 0;
            }
        } while (flag == 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%8[^\n]%*c", contractAddr.postalCode);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", contractAddr.city);


    // Contact Numbers Input:
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%*c", &option);
    if ((option == 'y') || (option == 'Y'))
    {
        printf("Please enter the contact's cell phone number: ");
        scanf("%10[^\n]%*c", contractPhoneNo.cell);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%*c", &option);
    if ((option == 'y') || (option == 'Y'))
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", contractPhoneNo.home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%*c", &option);
    if ((option == 'y') || (option == 'Y'))
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", contractPhoneNo.business);
    }


    // Display Contact Summary Details
    display(contractName, contractAddr, contractPhoneNo);

    return 0;
}

int display(struct Name contractName, struct Address contractAddr, struct Numbers contractPhoneNo) {
    printf("\nContact Details\n");
    printf("---------------\n");
    printf("Name Details:\n");
    printf("First name: %s\n", contractName.firstName);
    printf("Middle initial(s): %s\n", contractName.middleInitial);
    printf("Last name: %s\n", contractName.lastName);

    printf("\nAddress Details:\n");
    printf("Street number: %d\n", contractAddr.streetNumber);
    printf("Street name: %s\n", contractAddr.street);
    printf("Apartment: %d\n", contractAddr.apartmentNumber);
    printf("Postal code: %s\n", contractAddr.postalCode);
    printf("City: %s\n", contractAddr.city);

    printf("\nPhone Numbers:\n");
    (contractPhoneNo.cell[0] != '\0') ? printf("Cell phone number: %s\n", contractPhoneNo.cell) : printf("No cell phone number\n");
    (contractPhoneNo.home[0] != '\0') ? printf("Home phone number: %s\n", contractPhoneNo.home) : printf("No home phone number\n");
    (contractPhoneNo.business[0] != '\0') ? printf("Business phone number: %s\n", contractPhoneNo.business) : printf("No business phone number\n");

    // Display Completion Message
    printf("\nStructure test for Name, Address, and Numbers Done!\n");

    return 0;
}
/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details:
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details:
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/