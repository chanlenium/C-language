//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include<stdio.h>

int main(void) {
	int numOfDay;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numOfDay);
	while (!((3 <= numOfDay) && (numOfDay <= 10))) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numOfDay);
	}

	printf("\n");
	int High[10] = { 0 }, Low[10] = { 0 };
	int i;
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
	return 0;
}