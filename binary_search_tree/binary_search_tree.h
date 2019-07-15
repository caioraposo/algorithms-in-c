#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;


typedef struct trunk {
	struct trunk *prev;
	char str[10];
} trunk;


node *insert(node *root, int data);
void print_tree(node *root, trunk *prev, int is_right);
int tree_depth(node *root, int depth);

#endif
