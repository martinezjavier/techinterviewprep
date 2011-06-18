/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>

#define MAX_DIVISOR 20

int check_division(int);

int main(void)
{
	int number = 0;
	int i = 0;

	while(!number) {
		number = check_division(i);
		i++;
	}
	

	printf("The smallest number that can be divided is %d\n", number);
}

int check_division(int number) 
{
	int i;

	for (i = 1; i < MAX_DIVISOR; i++) {
		if (number % i != 0)
		        number = 0;
	}

	return number;
}
