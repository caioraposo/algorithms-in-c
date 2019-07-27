#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "avl_tree.h"


typedef struct node {
	int data;
	int balance_factor;
	struct node *left;
	struct node *right;
} node;


typedef struct trunk {
	struct trunk *prev;
	char str[10];
} trunk;


trunk *new_trunk(trunk *prev, char str[10]) {
	trunk *new = malloc(sizeof(trunk));
	new->prev = prev;
	strcpy(new->str, str);
	return new;
}


void show_trunks(trunk *trunk) {

	if (trunk == NULL)
		return;

	show_trunks(trunk->prev);

	printf("%s", trunk->str);
}


node *new_node(int data) {
	node *new = malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}


node *insert(node *root, int data) {
	int balfactor;

	if (root == NULL)
		return new_node(data);
	else if (root->data >= data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	

	balfactor = calc_balance_factor(root);


	// Right Rotate
	if (balfactor > 1 && data < root->left->data)
		return rotate_right(root);

	
	
	
	// Left Rotate
	if (balfactor < -1 && data > root->right->data)
		return rotate_left(root);

	
	// Left Right Rotate
	if (balfactor > 1 && data > root->left->data) {
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}
	

	// Right Left Rotate
	if (balfactor < -1 && data < root->right->data) {
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}
	
	return root;
}


void pre_order(node *root) {
	if (root != NULL) {
		printf("%d ", root->data);

		pre_order(root->left);
		pre_order(root->right);
	} else
		printf(". ");
}


int tree_depth(node *root, int depth) {

	if (root == NULL)
		return depth;

	int right = tree_depth(root->right, depth + 1);
	int left = tree_depth(root->left, depth + 1);

	if (right >= left)
		return right;
	else
		return left;

}


int calc_balance_factor(node *root) {

	if (root == NULL)
		return 0;


	int left_depth = tree_depth(root->left, 0);
	int right_depth = tree_depth(root->right, 0);


	return right_depth - left_depth;

}


node *rotate_right(node *root) {
	node *temp = root->left;
	temp->right = root;

	return temp;
}


node *rotate_left(node *root) {
	node *temp = malloc(sizeof(node));
	
	temp->left = new_node(root->data);

	return temp;
}


void main() {

	node *root = NULL;

	root = insert(root, 10);
	root = insert(root, 50);
	root = insert(root, 100);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 2);
	root = insert(root, 2);
	root = insert(root, 2);

	
	pre_order(root);
	

	
	free(root);
}
