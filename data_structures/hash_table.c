#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 20
#define MAX_ELEMENTS 100

struct node {
	int value;
	char key[MAX_STRING];
	struct node *next;
};

struct node *hash_table[MAX_ELEMENTS];

int size = 0;

int hash_function(char *);
void put(char *, int);
int get(char *);
int delete(char *);
struct node* create_node(char *, int);
void insert_node(struct node*, int);
int remove_node(char *, int); 
int hash_table_size();
int isempty();
void print_hash_table();
void print_hash_table_row(struct node *, int);

int main(void)
{
	char *strings[] = { "perro", "gato", "javier", "tami"};
	int i, len;

	for (i = 0; i < 4; i++)
		put(strings[i], i);

	printf("Hash table size is %d\n", hash_table_size());

	print_hash_table();
}

int hash_function(char *key)
{
	int index = 0, i;
	int len = strlen(key);

	for (i = 0; i < len; i++)
		index += key[i];

	return index % MAX_ELEMENTS;
}

void put(char *key, int value)
{
	int index;
	struct node *node = create_node(key, value);

	index = hash_function(key);

	insert_node(node, index);	
}

int delete(char *key)
{
	int index; 

	index = hash_function(key);

	return remove_node(key, index);
}

struct node *create_node(char *key, int value)
{
	struct node *node = (struct node*)malloc(sizeof(struct node));

	if (node == NULL)
		return NULL;

	strncpy(node->key, key, MAX_STRING);
	node->value = value;
	node->next = NULL;

	return node;
}

void insert_node(struct node *node, int index)
{
	struct node *current;

	if (hash_table[index] == NULL)
		hash_table[index] = node;
	else {
		current = hash_table[index];

		while(current->next) {
			current = current->next;
		}

		current->next = node;
	}

	size++;
}

int remove_node(char *key, int index)
{
	int retval;
	struct node *current = hash_table[index];
	struct node *last = hash_table[index];      

	while(!strncmp(current->key, key, MAX_STRING) && current->next) {
		last = current;
		current = current->next;
	}

	retval = current->value;
	last->next = current->next;
	
	free(current);
	size--;
	return retval;      
}

int hash_table_size()
{
	return size;
}

int isempty()
{
	return !size;
}

void print_hash_table()
{
	int i;
	for (i = 0; i < MAX_ELEMENTS; i++) {
		if (hash_table[i] != NULL)
			print_hash_table_row(hash_table[i], i);
	}
}

void print_hash_table_row(struct node *node, int idx)
{
	struct node *current = node;

	printf("idx=%d ", idx);

	while(current) {
		printf("<%s, %d> ", current->key, current->value);
		current = current->next;
	}

	printf("\n----------------------\n");
}
