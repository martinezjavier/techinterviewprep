#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *create_node(int);
struct node *insert(struct node*, int);
int lookup(struct node *, int);
void print_inorder(struct node *);
void print_preorder(struct node *);
void print_postorder(struct node *);
int size(struct node *);
int max_depth(struct node*);
int min_value(struct node*);
int max_value(struct node*);

int main(void)
{
	struct node *root = NULL;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 10);
	
	printf("Preorder\n");
	print_preorder(root);
	printf("Inorder\n");
	print_inorder(root);
	printf("Postorder\n");
	print_postorder(root);

	printf("The tree size is %d\n", size(root));
	printf("The tree max depth is %d\n", max_depth(root));
	printf("The min value is %d\n", min_value(root));
	printf("The max value is %d\n", max_value(root));
}

struct node *create_node(int data)
{
	struct node *node = (struct node *) malloc(sizeof(struct node));
						   
	if (node == NULL)
		return NULL;

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

struct node *insert(struct node *node, int data)
{
	if (node == NULL)
		return create_node(data);

	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

int lookup(struct node *node, int target)
{
	if (node == NULL)
		return 0;

	if (node->data == target) 
		return 1;

	if (node->data < target)
		lookup(node->right, target);
	else
		lookup(node->left, target);
}

void print_preorder(struct node *node)
{
	if (node == NULL)
		return;

	printf("%d\n", node->data);	

	print_preorder(node->left);

	print_preorder(node->right);

}

void print_inorder(struct node *node)
{
	if (node == NULL)
		return;

	print_inorder(node->left);
	
	printf("%d\n", node->data);

	print_inorder(node->right);
}

void print_postorder(struct node *node)
{
	if (node == NULL)
		return;

	print_postorder(node->left);
	
	print_postorder(node->right);

	printf("%d\n", node->data);
}

int size(struct node *node)
{
	int count = 1;
	if (node == NULL)
		return 0;

	count += (size(node->left) + size(node->right));

	return count;
}

int max_depth(struct node *node)
{
	int ldepth;
	int rdepth;

	if (node == NULL)
		return 0;

	ldepth = max_depth(node->left);
	rdepth = max_depth(node->right);

	if (ldepth > rdepth)
		return ldepth + 1;
	else
		return rdepth + 1;
}

int min_value(struct node *node)
{
	struct node *current = node;

	while(current->left) {
		current = current->left;
	}

	return current->data;
}

int max_value(struct node *node)
{
	struct node *current = node;
	
	while(current->right) {
		current = current->right;	       
	}

	return current->data;
}


