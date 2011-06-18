#include <stdio.h>

#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))

void bubble_sort(int [], int);
void print_array(int [], int);

int main(void) 
{
	int array[] = {5, 26, 10, 11, 1};
	bubble_sort(array, ARRAY_LEN(array));
	print_array(array, ARRAY_LEN(array));
}

void print_array(int array[], int len)
{
	int i;

	for (i = 0; i < len; i++) 
		printf("%d ", array[i]);
	printf("\n");      
}

void bubble_sort(int array[], int len)
{
	int i, band;
	int aux;

	band = 1;

	while (band) {	      
		for (i = 0, band = 0; i < len - 1; i++) {
			if (array[i] > array[i + 1]) {
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				band = 1;
			}
		}
	 }
}

