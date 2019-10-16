#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


int main(void) {
    graph *graph = new_graph();

    /* INSERE OS VÉRTICES */
    new_vertice(graph, 1);
    new_vertice(graph, 2);
    new_vertice(graph, 3);
    new_vertice(graph, 4);
    new_vertice(graph, 5);
    new_vertice(graph, 6);
    new_vertice(graph, 7);
    new_vertice(graph, 8);

    /* INSERE AS ARESTAS */
    insert_arest(graph, 1, 2);
    insert_arest(graph, 1, 3);
    insert_arest(graph, 2, 4);
    insert_arest(graph, 2, 5);
    insert_arest(graph, 3, 6);
    insert_arest(graph, 3, 7);
    insert_arest(graph, 4, 8);
    insert_arest(graph, 5, 8);
    insert_arest(graph, 6, 8);
    insert_arest(graph, 7, 8);

    print_graph(graph);

    printf("\n");

    DFS(graph, graph->head);
}
