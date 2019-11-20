#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"
#include "../include/linked_list.h"


int main(void) {
    /* Determinar o número mínimo de cores
     * para colorir o grafo sem que dois vétices
     * vizinhos tenham a mesma cor.
     * "Algorítimo guloso"
    */

    graph *graph = new_graph();

    insert_vertice(graph, 1);
    insert_vertice(graph, 2);
    insert_vertice(graph, 3);
    insert_vertice(graph, 4);
    insert_vertice(graph, 5);

    insert_arest(graph, 1, 2);
    insert_arest(graph, 1, 3);
    insert_arest(graph, 2, 4);
    insert_arest(graph, 3, 4);
    insert_arest(graph, 4, 5);

    printf("O numero cromático mínimo é: %d\n\n", get_minimum_chromatic_number(graph));
    print_graph(graph);

    free_graph(graph->head);
}
