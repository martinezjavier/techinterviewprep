/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>

#define NUMBER 600851475143

int is_prime(unsigned long long i);

int main(void) 
{
	unsigned long long i;
	unsigned long long largest_prime = 0;

	for (i = 2; i < 100; i++)
		if (is_prime(i) && NUMBER % i == 0)
			largest_prime = i;
	
	printf("The largest prime is %lld\n", largest_prime);
}

int is_prime(unsigned long long i)
{
	unsigned long long j;
	int prime = 1;

	for(j = 2; j < sqrt(i); j++)
		if (i % j == 0)
			prime = 0;

	return prime;
}
