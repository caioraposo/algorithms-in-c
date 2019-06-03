#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"


void main() {
	node *root = NULL;
	
	
	root = insert(root, 65);
	root = insert(root, 78);
	root = insert(root, 4);
	root = insert(root, 42);

	print_tree(root);

	
	free(root);
}
