#include <stdio.h>

void permute(int numbers[], int start, int size);
void printv(int numbers[], int size);
void swap(int *x, int *y);

int main(void)
{
	int numbers[] = {1, 2, 3};

	permute(numbers, 0, sizeof(numbers)/sizeof(numbers[0]));
}

void permute(int numbers[], int start, int size)
{
	int i, aux;

	if (start == size)
		printv(numbers, size);
	else {
		for (i = start; i < size; i++) {
			swap(&numbers[start], &numbers[i]);
			permute(numbers, start + 1, size);
			swap(&numbers[start], &numbers[i]);
		}
	}       
}

void swap(int *x, int *y)
{
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

void printv(int numbers[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", numbers[i]);
	printf("\n");
}
