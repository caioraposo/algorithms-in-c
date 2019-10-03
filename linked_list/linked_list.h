#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>


struct node {
    int data;
    struct node *next;
};


typedef struct linked_list {
    struct node *head;
    struct node *tail;
} linked_list;



/* TODO */
void insert_position(linked_list *list, int data, int position);
void delete(linked_list *list, int position);


void initialize(linked_list *list);
void print_list(linked_list *list);
void insert_beggining(linked_list *list, int data);
void insert_end(linked_list *list, int data);
void reverse(linked_list *list);
int list_size(struct node *head, int size);
bool list_element_exists(linked_list *list, int data);


#endif
