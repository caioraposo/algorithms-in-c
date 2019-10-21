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
    new->marked = false;
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


struct graph_node *get_node(struct graph_node *head, int vertice) {

    while (head != NULL) {
        if (head->vertice == vertice)
            return head;
        head = head->next;
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
    
    linked_list *list1 = &(get_node(graph->head, ver1)->adjacents);
    linked_list *list2 = &(get_node(graph->head, ver2)->adjacents);

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


void DFS(graph *graph, struct graph_node *head) {

    if (head == NULL)
        return;

    head->marked = true;
    printf("%d -> ", head->vertice);

    
    linked_list *list = &(head->adjacents);
    struct node *current = list->head;
    while (current != NULL) {
        // Get vertice of adjacents head
        struct graph_node *graph_current = get_node(graph->head, current->data);
        
        if (graph_current->marked == false)
            DFS(graph, graph_current);

        current = current->next;
    }
}

int even_vertices(struct graph_node *graph_head, int evens) {

    if (graph_head == NULL)
        return evens;
    
    linked_list *list = &(graph_head->adjacents);

    if (list_size(list->head, 0) % 2 != 0)
        evens++;

    return even_vertices(graph_head->next, evens);
}


bool is_eulerian(graph *graph){
    if (even_vertices(graph->head, 0) > 0)
        return false;
    return true;
}


bool has_eulerian_path(graph *graph) {
    if (even_vertices(graph->head, 0) >= 3)
        return false;
    return true;
}


int graph_size(struct graph_node *graph_head, int sum_vertices){
    
    if(graph_head == NULL)
        return sum_vertices;
    
    sum_vertices++;
    return graph_size(graph_head->next, sum_vertices);
}

