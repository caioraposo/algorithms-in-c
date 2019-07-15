#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void initialize(linked_list *list) {
	list->head = NULL;
	list->tail = NULL;
}


void print_list(linked_list *list) {
	struct nodo *current = list->head;
	
	if (current == NULL) {
		printf("List is Empty!\n\n");
		return;
	}

	while (current != NULL) {
		printf(" %d ->", current->data);
		current = current->next;
	}
	printf(" NULL\n\n");
}


void insert_beggining(linked_list *list, int data) {
	struct nodo *new = malloc(sizeof(struct nodo));
	new->data = data;

	if (list->head == NULL) {
		list->head = new;
		list->tail = new;
	} else {
		new->next = list->head;
		list->head = new;
	}
}


void insert_end(linked_list *list, int data) {
	if (list->head == NULL)
		insert_beggining(list, data);
	else {
		struct nodo *new = malloc(sizeof(struct nodo));
		new->data = data;
		list->tail->next = new;
		list->tail = new;
	}
}


void reverse(linked_list *list) {
	struct nodo *current = list->head;
	struct nodo *next = NULL;
	struct nodo *previous = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = previous;

		previous = current;
		current = next;
	}
	list->head = previous;
}