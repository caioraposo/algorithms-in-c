#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../linked_list/linked_list.h"

#define MAX 10

void print_graph(linked_list graph[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("[%d]", i);
        print_list(&graph[i]);
    }
}


void new_aresta(linked_list graph[], int ver1, int ver2) {
    if (ver1 > MAX || ver2 > MAX) {
        printf("Vertice não existe no grafo\n");
        return;
    }
    insert_beggining(&graph[ver1], ver2);
    insert_beggining(&graph[ver2], ver1);
}



bool existe_aresta(linked_list graph[], int ver1, int ver2) {
    if (ver1 > MAX || ver2 > MAX) {
        printf("Vertice não existe no grafo\n");
        return false;
    }

    linked_list *temp = &graph[ver1];
    struct node *current = temp->head;
    while (true) {
        if (current->data == ver2)
            return true;
        if (current->next == NULL)
            break;
        current = current->next;
    }
    return false;
}


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


bool has_eulerian_path(linked_list *graph) {
    if (even_vertices(graph, 0, 0) >= 3)
        return false;
    return true;
}


int num_vertices(linked_list *graph, int vertice, int sum_vertices){
    linked_list *temp = &graph[vertice];
    struct node *current = temp->head;
    
    if(vertice == MAX)
        return sum_vertices;

    if(current != NULL)
        sum_vertices++;
    
    vertice++;
    return num_vertices(graph, vertice, sum_vertices);
}


void print_menu(linked_list graph[]) {
    int choice;
    int ver1, ver2;
    bool existe;

    printf(".--------- Escolha uma Opcao ---------.\n");
    printf("| [1] Imprimir grafo                  |\n");
    printf("| [2] Inserir aresta                  |\n");
    printf("| [3] Possui caminho euleriano        |\n");
    printf("| [4] É euleriano                     |\n");
    printf("| [9] Sair                            |\n");
    printf("'-------------------------------------'\n\n");

    while (true) {
        
        printf("\nSua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Grafo:\n");
                print_graph(graph);
                break;
            case 2:
                printf("Informe os vertices (v v): ");
                scanf("%d %d", &ver1, &ver2);
                new_aresta(graph, ver1, ver2);
                break;
            case 3:
                if (has_eulerian_path(graph))
                    printf("O grafo possui caminho euleriano\n");
                else
                    printf("O grafo não possui caminho euleriano\n");
                break;
            case 4:
                if(is_eulerian(graph))
                    printf("O grafo é euleriano\n");
                else
                    printf("O grafo nao e euleriano\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Option!\n");
                break;
        }
        printf("\n");
    }
}


void main() {

    linked_list graph[MAX];

    int i;
    for (i = 0; i < MAX; i++)
        initialize(&graph[i]);

    
    new_aresta(graph, 1, 2);

    printf("%d\n", num_vertices(graph, 0, 0));

}


