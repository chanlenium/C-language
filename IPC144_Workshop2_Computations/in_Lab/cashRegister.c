//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include<stdio.h>

int main() {
	double amt, balance;
	int num_of_Loonies, num_of_Quaters;

	printf("I ENTERED: ");
	scanf("%lf", &amt);

	num_of_Loonies = amt;
	balance = amt - num_of_Loonies;
	printf("Loonies required: %d\t", num_of_Loonies);
	printf("balance owing: $%.2lf\n", balance);

	num_of_Quaters = balance / .25;
	balance = balance - num_of_Quaters * .25;
	printf("Quaters required: %d\t", num_of_Quaters);
	printf("balance owing: $%.2lf\n", balance);

	return 0;
}