/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))

int mult[] = {3, 5};

int main(void)
{
	long sum = 0;
	int i;
	int j;

	int l = ARRAY_LEN(mult);
	
	for (i = 0; i < MAX_NUMBERS; i++) {
		for (j = 0; j < l; j++) {
			if (i % mult[j] == 0) {
				printf("%d is multiply of %d\n", i, mult[j]);
				sum += i;
				break;
			}
		}
	}

	printf("Total is %ld\n", sum);
}

