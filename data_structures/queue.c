#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];

int head = 0, tail = 0;
int count = 0;

int empty();
int front();
int pop();
int push(int);
int size();
int isfull();
void print_queue();

int main(void)
{
	printf("Queue empty = %d\n", empty());

        push(1);
	push(2);
	push(3);
	push(4);
        push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);

	printf("Queue empty = %d\n", empty());

	print_queue();

	printf("Removed element %d\n", pop());
	printf("Removed element %d\n", pop());

	print_queue();      

	push(22);
	push(33);
	push(44);

	print_queue();
}

int empty() 
{
//	return head == tail;
	return !count;
}

int pop()
{
	int value;

	if (empty()) {
		printf("An element cannot be removed from the queue, it is empty!\n");
		return 0;
	}

	value = queue[head];

	head++;
	head %= MAX_SIZE;

	count--;

	return value;
}

int push(int element)
{
	if (isfull()) {
		printf("The element %d cannont be added - queue is full\n", element);
		return 1;		
	}

	queue[tail] = element;

	tail = (tail + 1) % MAX_SIZE;

	count++;
}

int size()
{
	return tail + MAX_SIZE - head;
}

int isfull()
{
	return count == MAX_SIZE;
}

void print_queue()
{
	int idx;

	for (idx = head; idx < head + count; idx++)
		printf("%d ", queue[idx % MAX_SIZE]);  

	printf("\n");
}

