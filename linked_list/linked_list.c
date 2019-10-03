#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


void initialize(linked_list *list) {
    list->head = NULL;
    list->tail = NULL;
}


void print_list(linked_list *list) {
    struct node *current = list->head;
    
    if (current == NULL) {
        printf("List is Empty!\n");
        return;
    }

    while (current != NULL) {
        printf(" %d ->", current->data);
        current = current->next;
    }
    printf(" NULL\n\n");
}


void insert_beggining(linked_list *list, int data) {
    struct node *new = malloc(sizeof(struct node));
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
        struct node *new = malloc(sizeof(struct node));
        new->data = data;
        list->tail->next = new;
        list->tail = new;
    }
}


int list_size(struct node *head, int size) {
    if (head == NULL)
        return size;

    size++;
    return list_size(head->next, size);
}


void reverse(linked_list *list) {
    struct node *current = list->head;
    struct node *next = NULL;
    struct node *previous = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    list->head = previous;
}


bool list_element_exists(linked_list *list, int data) {
    struct node *current = list->head;

    if (current == NULL)
        return false;

    while (current != NULL) {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}
