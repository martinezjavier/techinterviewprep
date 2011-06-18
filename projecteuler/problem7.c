/* 
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

#include <stdio.h>
#include <math.h>

#define MAX 10001

int is_prime(long long i);

int main(void) 
{
	long long i = 3;
	long long prime = 0;
	int prime_count = 1;

	while (prime_count < MAX) {
		if (is_prime(i)) {
			prime_count++;
		}
		i += 2;
	}

	i -= 2;

	printf("The prime %d prime number is %lld\n", MAX, i);
}

int is_prime(long long i)
{
	long j;
	int prime = 1;
	
	int sq = sqrt(i);
	

	for(j = 2; j <= sq; j++)
		if (i % j == 0)
			prime = 0;

	return prime;
}


