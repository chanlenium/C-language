//==============================================
// Name:           Dongchan	Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 3
#define High_Limit 40
#define Low_Limit -40

#include<stdio.h>

int main(void) {
	printf("---=== IPC Temperature Analyzer ===---\n");
	int day, high_Inval, low_Inval;
	for (day = 1; day <= NUMS; day++) {
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &high_Inval);

		printf("\nEnter the low value for day %d: ", day);
		scanf("%d", &low_Inval);
		printf("\n");

		
		while ((high_Inval >= High_Limit) || (low_Inval <= Low_Limit) || (high_Inval < low_Inval)) {
			printf("Incorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n\n", Low_Limit, High_Limit);
			day--;
			break;
		}
	}

	return 0;	
}

