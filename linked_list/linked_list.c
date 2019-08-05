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


void main() {
    int data, choice;
    linked_list list;
    initialize(&list);

    printf(".----- Choose an Option -----.\n");
    printf("| [1] Insert from beggining  |\n");
    printf("| [2] Insert in the end      |\n");
    printf("| [3] Reverse List           |\n");
    printf("| [4] Exit                   |\n");
    printf("'----------------------------'\n\n");
    while (1) {
        print_list(&list);

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Type the value: ");
                scanf("%d", &data);
                insert_beggining(&list, data);
                break;
            case 2:
                printf("Type the value: ");
                scanf("%d", &data);
                insert_end(&list, data);
                break;
            case 3:
                reverse(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Option!\n");
                break;
        }
        printf("\n");
    }
}
