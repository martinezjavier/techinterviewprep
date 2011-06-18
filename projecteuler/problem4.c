/* 
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <string.h>

#define BUF_LEN 100
#define MAX 999

int is_palindromic(int number);

int main(void)
{
	int i, j;
	int max_palindromic = 0;
	int result;

	for (i = 100; i < MAX; i++)
		for (j = 100; j < MAX; j++) {
			result = i * j;
			if (is_palindromic(result) && result > max_palindromic)
				max_palindromic = result;
		}
	
	printf("Max palindromic = %d\n", max_palindromic);
}

int is_palindromic(int number)
{
	char buffer[BUF_LEN];
	int i,j;
	int palindromic = 1;

	snprintf(buffer, BUF_LEN, "%d", number);

	for (i = 0, j = strlen(buffer)-1; i < j; i++, j--)
		if (buffer[i] != buffer[j])
			palindromic = 0;

	return palindromic;
}
