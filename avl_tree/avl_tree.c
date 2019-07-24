#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

	if (root == NULL)
		root = new_node(data);
	else if (root->data >= data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);

	return root;
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

/* NOT WORKING */
int calc_balance_factor(node *root, int balfactor) {
	
	if (root == NULL)
		return balfactor;

	int left_factor = calc_balance_factor(root->left, balfactor - 1);
	int right_factor = calc_balance_factor(root->right, balfactor + 1);

	return left_factor - right_factor;

}


void main() {

	node *root = NULL;

	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 912);
	root = insert(root, 43);
	root = insert(root, 3);

	print_tree(root, NULL, 0);

}
