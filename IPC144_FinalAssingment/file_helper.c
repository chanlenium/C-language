/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Dongchan Oh               dcoh@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <math.h>
#include "file_helper.h"

/********************************************************/
/* Read from the opened file the time (HH:MM) parts of  */
/* the record and return the time as decimal hours      */
/********************************************************/
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one rider from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info)
{
	int result = 1, ch;

	if (!feof(fp))  // when fp has not attempted to rea the end-of-file mark
	{
		result = 0;
		
		// read from file and assign to data structure
		fscanf(fp, "%[^,]%*c", info->name);
		fscanf(fp, "%d", &info->age);
		fscanf(fp, " %c", &info->raceLength);
		info->startTime = readTime(fp);
		info->mountainTime = readTime(fp);
		info->finishTime = readTime(fp);

		// Last Field (withdrawn: may not be present)
		ch = fgetc(fp);
		info->withdrawn = 0;

		if (ch == ' ') 
		{
			ch = fgetc(fp);
			info->withdrawn = (ch == 'W');
			ch = fgetc(fp);
		}
        
        if (info->withdrawn == 0) {
            info->recTime = info->finishTime - info->startTime; //record time of rider

            // Represent recTime as hour and minute parts
            info->hourTime = (int)(info->recTime);
            info->minTime = (int)round((info->recTime - info->hourTime) * 60);     
        }
        else {
            info->recTime = 100000; // when the rider is withdrawn, his/her recTime is set to big number
        }

		
		// clear input file buffer until end of line (record):
		while (!feof(fp) && ch != '\n')
		{
			ch = fgetc(fp);
		}
	}

	return result;
}

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// selectCategory
char selectCategory(void)
{
    printf("Which category (S, M, L): ");
    char inputVal, NL;
    int rc, flag = 0;

    do
    {
        rc = scanf("%c%c", &inputVal, &NL); // receive user input
        if (rc == 0) { // when scanf() did not fill any address
            printf("*** INVALID ENTRY *** <Only (S,s) or (M,m) or (L,l) are acceptable>: ");
            clearKeyboard();    // clear buffer
        }
        else if (NL != '\n') {
            printf("*** INVALID ENTRY *** <Only (S,s) or (M,m) or (L,l) are acceptable>: ");
            clearKeyboard();
        }
        else if (!((inputVal == 'S') || (inputVal == 's') || (inputVal == 'M') || (inputVal == 'm') || (inputVal == 'L') || (inputVal == 'l'))) {    // when the value of input is out of range
            printf("*** INVALID ENTRY *** <Only (S,s) or (M,m) or (L,l) are acceptable>: ");
        }
        else {
            if (inputVal >= 97) {   // when user input is small letter
                inputVal = inputVal - 32;   // Convert small letter to capital letter
            }
            flag = 1;   // exit loop
        }
    } while (flag == 0);

    return inputVal;    // return user input category value
}

// sortRiders: sorting rider information by record time(recTime) of riders
void sortRiders(struct RiderInfo* riders, int numOfRiders, int mode) {
    int i, j;
    struct RiderInfo tempRider;

    for (i = numOfRiders - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (mode == 0) {    // sort by descending order
                if (riders[j].recTime > riders[j + 1].recTime) {
                    tempRider = riders[j];
                    riders[j] = riders[j + 1];
                    riders[j + 1] = tempRider;
                }
            }else if(mode == 1) {   // sort by ascending order
                if (riders[j].recTime < riders[j + 1].recTime) {
                    tempRider = riders[j];
                    riders[j] = riders[j + 1];
                    riders[j + 1] = tempRider;
                }
            }
            
        }
    }    
}

// displayRider: display detail information of a single rider
void displayRider(struct RiderInfo* rider, int menuVal) {
    if (menuVal == 1 || menuVal == 3) { // when the user selects menu 1 or 3
        // print rider information according to age group
        if((rider->age >= 16) && (rider->age <= 20))
            printf("%-22s %8s %3d:%02d\n", rider->name, "Junior", rider->hourTime, rider->minTime);
        else if ((rider->age >= 21) && (rider->age <= 34))
            printf("%-22s %8s %3d:%02d\n", rider->name, "Adult", rider->hourTime, rider->minTime);
        else if (rider->age >= 35)
            printf("%-22s %8s %3d:%02d\n", rider->name, "Senior", rider->hourTime, rider->minTime);
    }
    else if (menuVal == 2) { // when the user selects menu 2
        if (rider->withdrawn == 1) {  // When the rider is withdrawn, print the rider's recTime value is "N/A"
            // print rider information according to age group
            if ((rider->age >= 16) && (rider->age <= 20))
                printf("%-22s %8s %6s %9s\n", rider->name, "Junior", "N/A", "Yes");
            else if ((rider->age >= 21) && (rider->age <= 34))
                printf("%-22s %8s %6s %9s\n", rider->name, "Adult", "N/A", "Yes");
            else if (rider->age >= 35)
                printf("%-22s %8s %6s %9s\n", rider->name, "Senior", "N/A", "Yes");
        }
        else { 
            // print rider information according to age group
            if ((rider->age >= 16) && (rider->age <= 20))
                printf("%-22s %8s %3d:%02d %9s\n", rider->name, "Junior", rider->hourTime, rider->minTime, "No");
            else if ((rider->age >= 21) && (rider->age <= 34))
                printf("%-22s %8s %3d:%02d %9s\n", rider->name, "Adult", rider->hourTime, rider->minTime, "No");
            else if (rider->age >= 35)
                printf("%-22s %8s %3d:%02d %9s\n", rider->name, "Senior", rider->hourTime, rider->minTime, "No");
        }
    }
    else if (menuVal == 4) {    // when the user selects menu 4
        char category[7];   // declare char array variable to store the expression of category
        if (rider->raceLength == 'S') {
            strcpy(category, "50 km");
        }
        else if (rider->raceLength == 'M') {
            strcpy(category, "75 km");
        }
        else if (rider->raceLength == 'L') {
            strcpy(category, "100 km");
        }

        // print rider information according to age group
        if ((rider->age >= 16) && (rider->age <= 20))
            printf("%-20s %9s %9s %2d:%02d\n", rider->name, "Junior", category, rider->hourTime, rider->minTime);
        else if ((rider->age >= 21) && (rider->age <= 34))
            printf("%-20s %9s %9s %2d:%02d\n", rider->name, "Adult", category, rider->hourTime, rider->minTime);
        else if (rider->age >= 35)
            printf("%-20s %9s %9s %2d:%02d\n", rider->name, "Senior", category, rider->hourTime, rider->minTime);
    }
}


// displayRiders: display riders information according to the menu input
void displayRiders(struct RiderInfo* riders, int numOfRiders, int menuVal) {
    int i = 0;
    printf("\n");

    if (menuVal == 1) { // Print top 3 riders in a category    
        printf("Rider                 Age Group   Time\n");
        printf("--------------------------------------\n");
        if (numOfRiders == 0) { // When the number of riders in selected category is zero
            printf("Not Awarded\n");
        }
        else {
            for (i = 0; i < numOfRiders; i++) {
                displayRider(&riders[i], menuVal);  // call disPlayRider func() to display detail information of the rider
            }
        }
    }
    else if (menuVal == 2) {    // Print all riders in a category
        printf("Rider                 Age Group   Time  Withdrew\n");
        printf("------------------------------------------------\n");
        if (numOfRiders == 0) { // When the number of riders in selected category is zero
            printf("No Rider\n");
        }
        else {
            for (i = 0; i < numOfRiders; i++) {
                displayRider(&riders[i], menuVal);  // call disPlayRider func() to display detail information of the rider
            }
        }
    }
    else if (menuVal == 3) {    // Print last 3 riders in a category
        printf("Rider                 Age Group   Time\n");
        printf("--------------------------------------\n");
        if (numOfRiders == 0) { // When the number of riders in selected category is zero
            printf("No Rider\n");
        }
        else {
            for (i = 0; i < numOfRiders; i++) {
                displayRider(&riders[i], menuVal);  // call disPlayRider func() to display detail information of the rider
            }
        }
    }
    else if (menuVal == 4) {    // Print winners in all categories
        printf("Rider                Age Group  Category  Time\n");
        printf("----------------------------------------------\n");
        if (numOfRiders == 0) { // When the number of riders in selected category is zero
            printf("Not Awarded\n");
        }
        else {
            for (i = 0; i < numOfRiders; i++) {
                if (riders[i].age == 0) { // When the number of riders in selected category is zero
                    printf("Not Awarded\n");
                }
                else {
                    displayRider(&riders[i], menuVal);  // call disPlayRider func() to display detail information of the rider
                }
            }
        }
    }
}

void displayTop3(struct RiderInfo* riderInfo, int numOfRiders, int menuVal) {
    char category = selectCategory();   // call selectCategory func() to know whick category is selected by user
    
    // declare RiderInfo type variable "categorizedRider" to store rider information corresponding to the category selected by user
    struct RiderInfo categorizedRider[10] = {'0'};   

    int i, numOfCategoriedRiders = 0;

    // Store rider information when the rider is in the category selected by user
    for (i = 0; i < numOfRiders; i++) {
        if (riderInfo[i].raceLength == category && riderInfo[i].withdrawn == 0) { // except withdrawn riders
            categorizedRider[numOfCategoriedRiders] = riderInfo[i];
            numOfCategoriedRiders++;
        }
    }

    // call sortRiders func() to sort "categorizedRider" according to the mode (0: descending order, 1: ascending order)
    sortRiders(&categorizedRider[0], numOfCategoriedRiders, 0);

    // call displayRiders func() to display categoried user information
    displayRiders(&categorizedRider[0], (numOfCategoriedRiders>3)?3:numOfCategoriedRiders, menuVal);
}


void displayAll(struct RiderInfo* riderInfo, int numOfRiders, int menuVal) {
    char category = selectCategory();   // call selectCategory func() to know whick category is selected by user

    // declare RiderInfo type variable "categorizedRider" to store rider information corresponding to the category selected by user
    struct RiderInfo categorizedRider[10] = { '0' };

    int i, numOfCategoriedRiders = 0;

    // Store rider information when the rider is in the category selected by user
    for (i = 0; i < numOfRiders; i++) {
        if (riderInfo[i].raceLength == category) {
            categorizedRider[numOfCategoriedRiders] = riderInfo[i];
            numOfCategoriedRiders++;
        }
    }

    // call sortRiders func() to sort "categorizedRider" according to the mode (0: descending order, 1: ascending order)
    sortRiders(&categorizedRider[0], numOfCategoriedRiders, 0);

    // call displayRiders func() to display categoried all users' information
    displayRiders(&categorizedRider[0], numOfCategoriedRiders, menuVal);
}


void displayLast3(struct RiderInfo* riderInfo, int numOfRiders, int menuVal) {
    char category = selectCategory();   // call selectCategory func() to know whick category is selected by user

    // declare RiderInfo type variable "categorizedRider" to store rider information corresponding to the category selected by user
    struct RiderInfo categorizedRider[10] = { '0' };
    
    int i, numOfCategoriedRiders = 0;

    for (i = 0; i < numOfRiders; i++) {
        if (riderInfo[i].raceLength == category && riderInfo[i].withdrawn == 0) { // except withdrawn riders
            categorizedRider[numOfCategoriedRiders] = riderInfo[i];
            numOfCategoriedRiders++;
        }
    }

    // call sortRiders func() to sort "categorizedRider" according to the mode (0: descending order, 1: ascending order)
    sortRiders(&categorizedRider[0], numOfCategoriedRiders, 1);

    // declare RiderInfo type variable "last3Rider" to store last 3 riders' information
    struct RiderInfo last3Rider[3] = { '0' };
    int numOfLast3Users = (numOfCategoriedRiders > 3) ? 3 : numOfCategoriedRiders;

    for (int i = 0; i < numOfLast3Users; i++) {
        last3Rider[i] = categorizedRider[i];
    }

    // call sortRiders func() to sort "last3Rider" according to the mode (0: descending order, 1: ascending order)
    sortRiders(&last3Rider[0], numOfLast3Users, 0);

    // call displayRiders func() to display last 3 users' information
    displayRiders(&last3Rider[0], numOfLast3Users, menuVal);
}

void displayWinner(struct RiderInfo* riderInfo, int numOfRiders, int menuVal) {
    // declare RiderInfo type variable "winnerRider" to store rider information for each category
    struct RiderInfo winnerRider[3] = { '0' };

    // declare int array type variable "winnerIndex" to store winner's index for each category
    int winnerIndex[3] = { 0 }; // index[0]: group S, index[1]: group M, index[2]: group L
    
    // declare & initialize double array type variable "winnerTime" to derive best record Time for each category
    double winnerTime[3] = { 10000000, 10000000, 10000000 };
   
    for (int i = 0; i < numOfRiders; i++) {
        if (riderInfo[i].raceLength == 'S' && riderInfo[i].withdrawn == 0) { // For group S, except withdrawn riders
            if (riderInfo[i].recTime < winnerTime[0]) {
                winnerIndex[0] = i;
                winnerTime[0] = riderInfo[i].recTime;
                winnerRider[0] = riderInfo[i];
            }
        }
        else if (riderInfo[i].raceLength == 'M' && riderInfo[i].withdrawn == 0) { // For group M, except withdrawn riders
            if (riderInfo[i].recTime < winnerTime[1]) {
                winnerIndex[1] = i;
                winnerTime[1] = riderInfo[i].recTime;
                winnerRider[1] = riderInfo[i];
            }
        }
        else if (riderInfo[i].raceLength == 'L' && riderInfo[i].withdrawn == 0) { // For group L, except withdrawn riders
            if (riderInfo[i].recTime < winnerTime[2]) {
                winnerIndex[2] = i;
                winnerTime[2] = riderInfo[i].recTime;
                winnerRider[2] = riderInfo[i];
            }
        }
    }
    // call displayRiders func() to display winners information for each group
    displayRiders(&winnerRider[0], 3, menuVal);
}

// menu: view the menu
int menu(void)
{
    int inputVal, rc, flag = 0;
    char NL = 'x';
    
    printf("\nWhat would you like to do ?\n");
    printf("0. Exit\n");
    printf("1. Print top 3 riders in a category\n");
    printf("2. Print all riders in a category\n");
    printf("3. Print last 3 riders in a category\n");
    printf("4. Print winners in all categories\n");
    printf(": ");

    do
    {
        rc = scanf("%d%c", &inputVal, &NL); // receive user input

        if (rc == 0) { // when scanf() did not fill any address
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();    // clear buffer
        }
        else if (NL != '\n') {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else if ((inputVal < 0) || (inputVal > 4)) {    // when the value of input is out of range
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 4>: ");
        }
        else {
            flag = 1;   // change the value of flag when the input is normal
        }
    } while (flag == 0);

    return inputVal;    // return selected menu number
}

void riderManagerSystem(struct RiderInfo* riderInfo, int numOfRiders)
{
    int inputVal, flag = 0;

    do {
        inputVal = menu();  // call the menu()
        printf("\n");

        if (inputVal == 1) {
            displayTop3(&riderInfo[0], numOfRiders, inputVal);  // call the function to display Top3
        }
        else if (inputVal == 2) {
            displayAll(&riderInfo[0], numOfRiders, inputVal);  // call the function to display all riders
        }
        else if (inputVal == 3) {
            displayLast3(&riderInfo[0], numOfRiders, inputVal);  // call the function to display Last3
        }
        else if (inputVal == 4) {
            displayWinner(&riderInfo[0], numOfRiders, inputVal);  // call the function to display Winners
        }
        else {  // When the number of menu is zero (Exit)
            printf("Keep on Riding!\n");
            flag = 1;   // change flag ( = exit while loop )
        }
    } while (flag == 0);
}