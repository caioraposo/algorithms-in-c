#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"


void main() {
	node *root = NULL;
	
	int data, choice;
	printf(".----- Choose an Option -----.\n");
	printf("| [1] Insert element         |\n");
	printf("| [4] Exit                   |\n");
	printf("'----------------------------'\n\n");
	while (1) {
		print_tree(root, NULL, 0);
		printf("\n");

		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Type the value: ");
				scanf("%d", &data);
				root = insert(root, data);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Option!\n");
				break;
		}
		printf("\n");
	}
	

	free(root);
}
