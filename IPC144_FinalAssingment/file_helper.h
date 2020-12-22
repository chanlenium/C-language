/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Dongchan Oh               dcoh@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/********************************************************/
/* Define the missing members for the RiderInfo data    */
/* used to store Rider information read from a file     */
/********************************************************/
struct RiderInfo
{
	// TODO:  Fill in the missing members:
    char name[30];
    int age;
    char raceLength;
    double startTime;
    double mountainTime;
    double finishTime;
    int withdrawn;

    double recTime; // member variable to store record time of rider (finish Time - satartTime) 
    int hourTime;   // member variable to represent hour part of recTime
    int minTime;    // member variable to represent minute part of recTime
};



/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/********************************************************/
/* Read all the information on one rider from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info);

#endif
