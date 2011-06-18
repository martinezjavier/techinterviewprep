/* 
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 100

int main(void)
{
	int sum_squares = 0;
	int square_sum = 0;
	int i;
	int diff = 0;

	for (i = 0; i <= MAX_NUMBER; i++) {
		sum_squares += i*i;
		square_sum += i;
	}

	square_sum *= square_sum;

	diff = abs(square_sum - sum_squares);

	printf("The difference is %d\n", diff);
}
