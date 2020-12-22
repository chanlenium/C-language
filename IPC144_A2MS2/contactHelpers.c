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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
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

// getIntInRange function definition goes here:
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

// yes function definition goes here:
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
            printf("inputVal: %c\n", inputVal);
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

// menu function definition goes here:
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

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int inputVal, exit_YN, flag = 0;

    do {
        inputVal = menu();
        if (inputVal != 0) {
            printf("\n<<< Feature %d is unavailable >>>\n\n", inputVal);
            pause();
            printf("\n");
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