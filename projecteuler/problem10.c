/* 
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <math.h>

#define MAX 2000000

int is_prime(long long i);

int main(void) 
{
	long long i;
	long long sum = 2;

	for (i = 3; i < MAX; i+=2) {
		printf("%ld\n", i);
		if (is_prime(i))
			sum += i;
	}

	printf("The sum is %lld\n", sum);
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


