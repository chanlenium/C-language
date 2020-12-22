//==============================================
// Name:           Dongchan	Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 4
#define High_Limit 40
#define Low_Limit -40

#include<stdio.h>

int main(void) {
	printf("---=== IPC Temperature Analyzer ===---\n");
	int day, high_Inval, low_Inval;
	int highestT, lowestT, highestTDay, lowestTDay;
	float meanLowtemp = 0, meanHightemp = 0, meanOveralltemp = 0;

	for (day = 1; day <= NUMS; day++) {
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &high_Inval);

		printf("\nEnter the low value for day %d: ", day);
		scanf("%d", &low_Inval);
		printf("\n");


		if ((high_Inval <= High_Limit) && (low_Inval >= Low_Limit) && (high_Inval > low_Inval)) {
			meanLowtemp += low_Inval;
			meanHightemp += high_Inval;
			meanOveralltemp += (low_Inval + high_Inval);

			if (day == 1) {
				highestT = high_Inval;
				lowestT = low_Inval;
				highestTDay = day;
				lowestTDay = day;
			}
			else {
				if (high_Inval > highestT) {
					highestT = high_Inval;
					highestTDay = day;
				}
				if (low_Inval < lowestT) {
					lowestT = low_Inval;
					lowestTDay = day;
				}
			}
		}
		else {
			printf("Incorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n\n", Low_Limit, High_Limit);
			day--;
		}	
	}

	printf("The average (mean) LOW temperature was: %.2lf\n", (meanLowtemp / NUMS));
	printf("The average (mean) HIGH temperature was: %.2lf\n", (meanHightemp / NUMS));
	printf("The average (mean) temperature was: %.2lf\n", (meanOveralltemp / (2*NUMS)));
	printf("The highest temperature was %d, on day %d\n", highestT, highestTDay);
	printf("The lowest temperature was %d, on day %d\n", lowestT, lowestTDay);

	return 0;
}


