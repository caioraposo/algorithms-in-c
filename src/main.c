#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#include "graph.h"


int main(void) {
    int choice;
    int ver1, ver2;
    int total_colors;

    graph *graph = new_graph();

    printf(".--------- Escolha uma Opcao ---------.\n");
    printf("| [1] Imprimir grafo                  |\n");
    printf("| [2] Inserir vertice                 |\n");
    printf("| [3] Inserir aresta                  |\n");
    printf("| [4] É euleriano                     |\n");
    printf("| [5] Possui caminho euleriano        |\n");
    printf("| [6] Minimo de cores necessárias     |\n");
    printf("| [9] Sair                            |\n");
    printf("'-------------------------------------'\n\n");

    while (true) {

        printf("\nSua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                print_graph(graph);
                break;
            case 2:
                printf("Informe o vertice: ");
                scanf("%d", &ver1);
                new_vertice(graph, ver1);
                break;
            case 3:
                printf("Escolha os vertices (v v): ");
                scanf("%d %d", &ver1, &ver2);
                insert_arest(graph, ver1, ver2);
                break;
            case 4:
                if(is_eulerian(graph))
                    printf("O grafo é euleriano\n");
                else
                    printf("O grafo nao e euleriano\n");
                break;
            case 5:
                if (has_eulerian_path(graph))
                    printf("O grafo possui caminho euleriano\n");
                else
                    printf("O grafo não possui caminho euleriano\n");
                break;
            case 6:
                total_colors = get_minimum_chromatic_number(graph);
                printf("O mínimo de cores necessárias são: %d", total_colors);
                break;
            case 9:
                free_graph(graph->head);
                exit(0);
            default:
                printf("Invalid Option!\n");
                break;
        }
        printf("\n");
    }
}

