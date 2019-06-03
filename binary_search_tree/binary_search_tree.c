#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"


node *new_node(int data) {
	node *new = malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}


node *insert(node *root, int data) {

	if (root == NULL)
		root = new_node(data);
	else if (root->data >= data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);

	return root;
}


void print_tree(node *root) {
	if (root != NULL) {
		printf("%d ", root->data);

		print_tree(root->left);
		print_tree(root->right);
	} else
		printf(". ");
}
