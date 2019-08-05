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

	if (balfactor >= -1 && balfactor <= 1)
		return root;


	// Right Rotate
	if (balfactor > 1 && data <= root->left->data)
		return rotate_right(root);

	
	// Left Rotate
	if (balfactor < -1 && data >= root->right->data)
		return rotate_left(root);

	
	// Left Right Rotate
	if (balfactor > 1 && data >= root->left->data) {
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}
	

	// Right Left Rotate
	if (balfactor < -1 && data <= root->right->data) {
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}
	
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


void print_tree(node *root, trunk *prev, int is_right) {

	if (root == NULL)
		return;

	char prev_str[10] = "     ";
	trunk *trk = new_trunk(prev, prev_str);

	print_tree(root->right, trk, 1);
	
	if (!prev)
		strcpy(trk->str, "----");
	else if (is_right) {
		strcpy(trk->str, ".---");
		strcpy(prev_str, "    |");
	} else {
		strcpy(trk->str, "`---");
		strcpy(prev->str, prev_str);
	}
		
	show_trunks(trk);
	printf("%d\n", root->data);

	if (prev)
		strcpy(prev->str, prev_str);
	strcpy(trk->str, "    |");

	print_tree(root->left, trk, 0);
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
	root->left = temp->right;

	temp->right = root;

	return temp;
}


node *rotate_left(node *root) {
	
	node *temp = root->right;
	root->right = temp->left;

	temp->left = root;

	return temp;
}


void main() {

	node *root = NULL;


	root = new_node(10);
	root = insert(root, 5);
	root = insert(root, 10);
	

	root = rotate_right(root);

	print_tree(root, NULL, 0);
	


	printf("\n%d\n", calc_balance_factor(root));

	free(root);
}
