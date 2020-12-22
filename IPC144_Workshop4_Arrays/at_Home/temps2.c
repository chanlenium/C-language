//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include<stdio.h>

int main(void) {
	int i, numOfDay;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numOfDay);
	while (!((3 <= numOfDay) && (numOfDay <= 10))) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numOfDay);
	}

	printf("\n");
	int High[10] = { 0 }, Low[10] = { 0 };
	for (i = 0; i < numOfDay; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &High[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &Low[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < numOfDay; i++) {
		printf("%d    %d    %d\n", i + 1, High[i], Low[i]);
	}

	int highestTempDay = 1, lowestTempDay = 1;
	int highestTemp = High[highestTempDay - 1], lowestTemp = Low[lowestTempDay - 1];
	for (i = 1; i < numOfDay; i++) {
		if (High[i] > highestTemp) {
			highestTemp = High[i];
			highestTempDay = i + 1;
		}

		if (Low[i] < lowestTemp) {
			lowestTemp = Low[i];
			lowestTempDay = i + 1;
		}
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highestTemp, highestTempDay);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestTempDay);

	int avgTempNum = 0;
	float averageTemp = 0;

	do {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numOfDay);
		scanf("%d", &avgTempNum);
	
		if (avgTempNum < 0) {
			printf("\nGoodbye!\n");
			break;
		}
		else {
			while (!((1 <= avgTempNum) && (avgTempNum <= numOfDay))) {
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", numOfDay);
				scanf("%d", &avgTempNum);
			}

			int sumTemp = 0;
			for (i = 0; i < avgTempNum; i++) {
				sumTemp += (High[i] + Low[i]);
			}
			averageTemp = ((float)sumTemp / (2 * avgTempNum));
			printf("\nThe average temperature up to day %d is: %.2f\n", avgTempNum, averageTemp);
		}
	} while (avgTempNum > 0);

	return 0;
}