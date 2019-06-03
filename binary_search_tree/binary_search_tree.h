#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node node;


node *insert(node *root, int data);
void print_tree(node *root);

#endif
