#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"


void main() {
	node *root = NULL;
	int depth;
	
	root = insert(root, 8);
	root = insert(root, 15);
	root = insert(root, 4);
	root = insert(root, 90);
	root = insert(root, 90);
	root = insert(root, 90);
	root = insert(root, 5);
	root = insert(root, 1);

	print_tree(root, NULL, 0);	

	depth = tree_depth(root, -1);

	printf("\nThe depth of the tree is: %d\n", depth);

	free(root);
}
