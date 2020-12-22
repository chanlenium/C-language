//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        NNM
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main() {
	double amountOwing, balanceOwing, GST;
	int num_of_Loonies, num_of_Quarters, num_of_Dimes, num_of_Nickels, num_of_Pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing);

	GST = amountOwing * .13 + .005;
	printf("GST: %.2lf\n", GST);

	balanceOwing = amountOwing + GST;
	printf("Balance owing: $%.2lf\n", balanceOwing);

	num_of_Loonies = balanceOwing;
	printf("Loonies required: %d, ", num_of_Loonies);
	balanceOwing = balanceOwing - num_of_Loonies;
	printf("balance owing $%.2lf\n", balanceOwing);

	num_of_Quarters = (balanceOwing * 100) / 25;
	printf("Quarters required: %d, ", num_of_Quarters);
	balanceOwing = (int)(balanceOwing * 100) % 25;
	printf("balance owing $%.2lf\n", (float)balanceOwing / 100);

	num_of_Dimes = balanceOwing / 10;
	printf("Dimes required: %d, ", num_of_Dimes);
	balanceOwing = (int)balanceOwing % 10;
	printf("balance owing $%.2lf\n", (float)balanceOwing / 100);

	num_of_Nickels = balanceOwing / 5;
	printf("Nickels required: %d, ", num_of_Nickels);
	balanceOwing = (int)balanceOwing % 5;
	printf("balance owing $%.2lf\n", (float)balanceOwing / 100);

	num_of_Pennies = balanceOwing;
	printf("Pennies required: %d, ", num_of_Pennies);
	balanceOwing = (int)balanceOwing % 1;
	printf("balance owing $%.2lf\n", (float)balanceOwing / 100);

	return 0;
}