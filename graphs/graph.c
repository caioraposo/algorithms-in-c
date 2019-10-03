#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../linked_list/linked_list.h"
#include "graph.h"


graph *new_graph() {
    graph *graph = malloc(sizeof(graph));
    graph->head = NULL;
    return graph;
}


struct graph_node *new_graph_node(int vertice) {
    struct graph_node *new = malloc(sizeof(struct graph_node));
    new->vertice = vertice;
    return new;
}


void print_graph(graph *graph) {
    struct graph_node *current = graph->head;
    
    if (current == NULL) {
        printf("Graph is Empty!\n");
        return;
    }

    while (current != NULL) {
        printf("[%d] ", current->vertice);
        // Adjacents is a linked list, so it uses the linked list function.
        print_list(&(current->adjacents));
        current = current->next;
    }
}


void insert_vertice(graph *graph, int vertice) {
    struct graph_node *new = new_graph_node(vertice);

    if (graph->head == NULL)
        graph->head = new;
    else {
        new->next = graph->head;
        graph->head = new;
    }
}


bool is_vertice(graph *graph, int vertice) {
    struct graph_node *current = graph->head;

    while (current != NULL) {
        if (current->vertice == vertice)
            return true;
        current = current->next;
    }
    return false;
}


void new_vertice(graph *graph, int vertice) {
    if (is_vertice(graph, vertice)) {
        printf("Vertice already exists!\n");
        return;
    }
    insert_vertice(graph, vertice);
}


struct graph_node *get_node(graph *graph, int vertice) {
    struct graph_node *current = graph->head;

    while (current != NULL) {
        if (current->vertice == vertice)
            return current;
        current = current->next;
    }
    return NULL;
}

void insert_arest(graph *graph, int ver1, int ver2) {
   
    if (!(is_vertice(graph, ver1) && is_vertice(graph, ver2))) {
        printf("ERROR: Vertice not in graph!");
        return;
    }

    if (is_arest(graph, ver1, ver2)) {
        printf("Arest already exists!\n");
        return;
    }
    
    linked_list *list1 = &(get_node(graph, ver1)->adjacents);
    linked_list *list2 = &(get_node(graph, ver2)->adjacents);

    insert_beggining(list1, ver2);
    insert_beggining(list2, ver1);

}



bool is_arest(graph *graph, int ver1, int ver2) {
    
    // Returns false if one of the vertices doesn't exists in graph
    if (!(is_vertice(graph, ver1) && is_vertice(graph, ver2)))
        return false;

    struct graph_node *current = graph->head;

    while (current != NULL) {
        if (current->vertice == ver1) {
            if (list_element_exists(&(current->adjacents), ver2))
                return true;
        }
        current = current->next;
    }
    return false;
}

/*
int even_vertices(linked_list *graph, int vertice, int even) {
    linked_list *temp = &graph[vertice];
    struct node *current = temp->head;

    if (vertice == MAX)
        return even;
    
    if (list_size(current, 0) % 2 != 0)
        even++;

    vertice++;
    return even_vertices(graph, vertice, even);
}


bool is_eulerian(linked_list *graph){
    if (even_vertices(graph, 0, 0) > 0)
        return false;
    return true;
}


bool has_eulerian_path(graph *graph) {
    if (even_vertices(graph, 0, 0) >= 3)
        return false;
    return true;
}


int total_vertices(graph *graph) {
    return num_vertices(graph, 0, 0);
}


int num_vertices(graph *graph, int vertice, int sum_vertices){
    linked_list *temp = &graph[vertice];
    struct node *current = temp->head;
    
    if(vertice == MAX)
        return sum_vertices;

    if(current != NULL)
        sum_vertices++;
    
    vertice++;
    return num_vertices(graph, vertice, sum_vertices);
}

*/
