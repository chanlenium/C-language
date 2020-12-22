/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Dongchan Oh               dcoh@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

// define MAXRIDERS for sizing contacts array (5000)
#define MAXRIDERS 5000

#include<stdio.h>
#include "file_helper.h"

int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report

    printf("******************** Seneca Cycling Race Results ********************");

    FILE* fp = NULL;    // declaration of  file pointer
    struct RiderInfo riderInfo[MAXRIDERS];  // declaration of the RiderInfo structure type variable "riderInfo"
    int nrecs = 0;  // declaration of number of records(lines) in file   

    fp = fopen("data.txt", "r");    // read from the file "data.txt" 
    if (fp != NULL) {   // when opening the file success! 
        while (readFileRecord(fp, &riderInfo[nrecs]) != 1) {    // store record(line) to a data structure array 
            nrecs++;    // count the records(lines)
        }
    }
    else {  // when opening the file fail!
        printf("Failed to open file\n");
    }

    riderManagerSystem(riderInfo, nrecs);   // call riderManagerSystem function with argumnet (riderInfo, nrecs) 

    fclose(fp); // ignore any data left in the file's buffer and closes the connection
	return 0;
}