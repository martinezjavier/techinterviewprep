#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))

#define MAX_SIZE 20

void quick_sort(int [], int, int);
int partition(int [], int, int);
void print_array(int [], int);
void swap(int *, int *);

int main(void) 
{
	int array[] = {5, 26, 10, 11, 1};
	quick_sort(array, 0, ARRAY_LEN(array) - 1);
	print_array(array, ARRAY_LEN(array));
}

void print_array(int array[], int len)
{
	int i;

	for (i = 0; i < len; i++) 
		printf("%d ", array[i]);
	printf("\n");      
}

void quick_sort(int array[], int l, int h)
{      
	int p;

	if ( h - l > 0) {
		p = partition(array, l, h);

		quick_sort(array, l, p - 1);
		quick_sort(array, p + 1, h);
	}
}

int partition(int array[], int l, int h)
{
	int i;
	int p;
	int firsthigh;

	p = h;
	firsthigh = l;

	for (i = l; i < h; i++) {
		if (array[i] < array[p]) {
			swap(&array[i], &array[firsthigh]);
			firsthigh++;
		}
	}

	swap(&array[p], &array[firsthigh]);

	return firsthigh;
}

void swap(int *a, int *b)
{
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
}



