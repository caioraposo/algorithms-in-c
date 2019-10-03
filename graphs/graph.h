#ifndef GRAPH_H
#define GRAPH_H


#include <stdbool.h>


#include "../linked_list/linked_list.h"


struct graph_node {
    int vertice;
    linked_list adjacents;
    struct graph_node *next;
};


typedef struct {
    struct graph_node *head;
} graph;



graph *new_graph();

void print_graph(graph *graph);

void new_vertice(graph *graph, int vertice);

void insert_arest(graph *graph, int ver1, int ver2);

bool is_arest(graph *graph, int ver1, int ver2);

bool is_eulerian(graph *graph);

bool has_eulerian_path(graph *graph);

bool is_hamiltonian(graph *graph);

int total_vertices(graph *graph);


#endif
