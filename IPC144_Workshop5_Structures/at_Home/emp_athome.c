//==============================================
// Name:           Dongchan	Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Workshop:       5 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define numOfEmployees 4		

// Declare Struct Employee 
struct Employee
{
	int employeeID, employeeAge;
	double employeeSalary;
};

/* main program */
int main(void)
{
	int option = 0, count = 0, i = 0;;
	int employID = 0, flag = 0, n = 0;
	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[numOfEmployees] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			for (i = 0; i < numOfEmployees; i++) {
				if (emp[i].employeeID > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].employeeID, emp[i].employeeAge, emp[i].employeeSalary);
				}
			}
			printf("\n");
			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			if (count < numOfEmployees) {
				int add_flag = 0;
				int j = 0;
				do{
					if (emp[j].employeeID == 0) {
						printf("Enter Employee ID: ");
						scanf("%d", &emp[j].employeeID);
						printf("Enter Employee Age: ");
						scanf("%d", &emp[j].employeeAge);
						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[j].employeeSalary);
						add_flag = 1;
					}
					else {
						j++;
					}
				} while (add_flag == 0);

				count++;

				printf("\n");
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;

		case 3:	// Update Employee Salary
			flag = 0;
			printf("Update Employee Salary\n");
			printf("======================\n");

			// Prompt the user for the employee identification number using a do-while loop. While the number is not found in the employee array, keep prompting the user
			// Once the number is found, display the current salary for the employee with that identification number and prompt the user to input the new salary. Replace the old salary with the input value.

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &employID);
				for (n = 0; n < numOfEmployees; n++) {
					if (employID == emp[n].employeeID) {
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}
				else {
					printf("The current salary is %.2lf\n", emp[n].employeeSalary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emp[n].employeeSalary);
					printf("\n");
				}

			} while (flag == 0);
			break;

		case 4:	// Remove Employee
			flag = 0;
			printf("Remove Employee\n");
			printf("===============\n");

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &employID);
				for (n = 0; n < numOfEmployees; n++) {
					if (employID == emp[n].employeeID) {
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}
				else {
					printf("Employee %d will be removed\n", emp[n].employeeID);		
					emp[n].employeeID = 0;
					count--;
					printf("\n");
				}
			} while (flag == 0);
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}





// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
