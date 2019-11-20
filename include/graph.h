#ifndef GRAPH_H
#define GRAPH_H


#include <stdbool.h>


#include "linked_list.h"


struct graph_node {
    int                 vertice;
    int                 color;
    linked_list         adjacents;
    struct graph_node   *next;
    bool                marked;
};


typedef struct {
    struct graph_node *head;
} graph;



graph *new_graph();


struct graph_node *get_node(struct graph_node *head, int vertice);

void free_graph(struct graph_node *head);
void print_graph(graph *graph);
void new_vertice(graph *graph, int vertice);
void insert_vertice(graph *graph, int vertice);
void insert_arest(graph *graph, int ver1, int ver2);

bool is_arest(graph *graph, int ver1, int ver2);
bool is_eulerian(graph *graph);
bool has_eulerian_path(graph *graph);
bool is_hamiltonian(graph *graph);

int total_vertices(graph *graph);

void DFS(graph *graph, struct graph_node *head);
void BFS(graph *graph, struct graph_node *head);

bool vertice_is_uncolored(struct graph_node *vertice);
bool vertice_adjacents_has_color(graph *graph, linked_list *adjacents, int color);
void color_graph_with(graph *graph, int color);
int get_minimum_chromatic_number(graph *graph);



#endif
