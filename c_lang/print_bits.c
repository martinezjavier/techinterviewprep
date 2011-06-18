#include <stdio.h>

void print_bits(char c);
void do_print_bits(char c, int idx);

int main(void)
{
	print_bits('0');
	print_bits('A');
	print_bits('a');
}

void print_bits(char c)
{
	int i;

	printf("Char %c bits = ", c);

	do_print_bits(c, sizeof(c)*8); 

	printf("\n");
}

void do_print_bits(char c, int idx)
{       
	int one;

	if (idx == 0)
		return;

	if (c & 1)
		one = 1;
	else
		one = 0;

	idx--;
	c >>= 1;

	do_print_bits(c, idx);

	if (one)
		printf("1");
	else
		printf("0");
}
