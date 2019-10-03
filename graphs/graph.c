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


bool existe_vertice(graph *graph, int vertice) {
    struct graph_node *current = graph->head;

    while (current != NULL) {
        if (current->vertice == vertice)
            return true;
        current = current->next;
    }
    return false;
}


void new_vertice(graph *graph, int vertice) {
    if (existe_vertice(graph, vertice)) {
        printf("Vertice already exists!\n");
        return;
    }
    insert_vertice(graph, vertice);
}



// bool existe_aresta(linked_list graph[], int ver1, int ver2) {
//     if (ver1 > MAX || ver2 > MAX) {
//         printf("Vertice não existe no grafo\n");
//         return false;
//     }
// 
//     linked_list *temp = &graph[ver1];
//     struct node *current = temp->head;
//     while (true) {
//         if (current->data == ver2)
//             return true;
//         if (current->next == NULL)
//             break;
//         current = current->next;
//     }
//     return false;
// }


// int even_vertices(linked_list *graph, int vertice, int even) {
//     linked_list *temp = &graph[vertice];
//     struct node *current = temp->head;
// 
//     if (vertice == MAX)
//         return even;
//     
//     if (list_size(current, 0) % 2 != 0)
//         even++;
// 
//     vertice++;
//     return even_vertices(graph, vertice, even);
// }
// 
// 
// bool is_eulerian(linked_list *graph){
//     if (even_vertices(graph, 0, 0) > 0)
//         return false;
//     return true;
// }
// 
// 
// bool has_eulerian_path(graph *graph) {
//     if (even_vertices(graph, 0, 0) >= 3)
//         return false;
//     return true;
// }
// 
// 
// int total_vertices(graph *graph) {
//     return num_vertices(graph, 0, 0);
// }
// 
// 
// int num_vertices(graph *graph, int vertice, int sum_vertices){
//     linked_list *temp = &graph[vertice];
//     struct node *current = temp->head;
//     
//     if(vertice == MAX)
//         return sum_vertices;
// 
//     if(current != NULL)
//         sum_vertices++;
//     
//     vertice++;
//     return num_vertices(graph, vertice, sum_vertices);
// }
// 
// 
