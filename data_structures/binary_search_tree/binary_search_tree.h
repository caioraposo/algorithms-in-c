#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


struct node {
	int data;
	struct node *left;
	struct node *right;
};


typedef struct trunk {
	struct trunk *prev;
	char str[10];
} trunk;


typedef struct node node;


node *insert(node *root, int data);
void print_tree(node *root, trunk *prev, int is_right);

#endif
