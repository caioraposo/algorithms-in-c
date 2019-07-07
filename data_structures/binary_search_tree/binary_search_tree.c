#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_search_tree.h"


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
	else if (is_left) {
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
