#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))

#define MAX_SIZE 20

void merge_sort(int [], int, int);
void merge(int [], int, int, int);
void print_array(int [], int);

int main(void) 
{
	int array[] = {5, 26, 10, 11, 1};
	merge_sort(array, 0, ARRAY_LEN(array) - 1);
	print_array(array, ARRAY_LEN(array));
}

void print_array(int array[], int len)
{
	int i;

	for (i = 0; i < len; i++) 
		printf("%d ", array[i]);
	printf("\n");      
}

void merge_sort(int array[], int lo, int hi)
{      
	int mid;

	if (lo < hi) {
		mid = (lo + hi)/2;

		merge_sort(array, lo, mid);
		merge_sort(array, mid + 1, hi);              
		merge(array, lo, mid, hi);
	}
}

void merge(int array[], int lo, int mid, int hi)
{
	int aux[MAX_SIZE];
	int i,j,idx, k;

	memset(aux, 0, sizeof(int));

	i = lo;
	j = mid + 1;
	idx = lo;

	while (i <= mid && j <= hi) {
		if (array[i] <= array[j]) {
			aux[idx] = array[i];
			i++;
		} else {
			aux[idx] = array[j];
			j++;
		}
		idx++;
	}

	if (i <= mid) {
		for (k = i; k <= mid; k++) {
			aux[idx] = array[k];
			idx++;
		}
	} else {
		for (k = j; k <= hi; k++) {
			aux[idx] = array[k];
			idx++;
		}
	}

	for (k = lo; k <= hi; k++) {
		array[k] = aux[k];
	}
}

