#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];

int size = 0;

int push(int);
int pop();
int stack_top();
void print_stack();

int main(void)
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	print_stack();

	printf("Deleting element %d\n", pop());
	printf("Deleting element %d\n", pop());
	printf("Deleting element %d\n", pop());

	print_stack();

	printf("Deleting element %d\n", pop());
	printf("Deleting element %d\n", pop());
	printf("Deleting element %d\n", pop());
	
}

int push(int element)
{
	if (size == MAX_SIZE - 1) {
		printf("Cannot inset element %d stack is full\n", element);
		return -1;
	}

	stack[size++] = element;

	return 0;
}

int pop()
{
	if (size == 0) {
		printf("Cannot delete element stack is empty\n");
		return -1;
	}

	return stack[--size];
}

int stack_top()
{
	if (size == 0) {
		printf("Cannot obtain top stack is empty\n");
		return -1;
	}

	return stack[size - 1];
}

void print_stack()
{
	int i;

	for (i = size; i > 0; i--) {
		printf("%d\n", stack[i - 1]);
		printf("--------\n");
        }
}
