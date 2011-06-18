#include <stdio.h>
#include <stdarg.h>

void print_numbers(int number, ...);

int main(void)
{
	print_numbers(1);
	print_numbers(1, 2, 3);
	print_numbers(1, 2, 3, 4, 5);

}

void print_numbers(int number, ...)
{
	va_list numbers;
	int i;

	va_start(numbers, number);
	for (i = number; i >= 0; i = va_arg(numbers, int)) 
		printf("%d ", i);
	va_end(numbers);
	
	printf("\n");
}
