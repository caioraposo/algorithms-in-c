#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10


struct nodo {
    int data;
    struct nodo *next;
};


typedef struct linked_list {
    struct nodo *head;
    struct nodo *tail;
} linked_list;


void initialize(linked_list *list) {
    list->head = NULL;
    list->tail = NULL;
}


void print_list(linked_list *list) {
    struct nodo *current = list->head;
    
    if (current == NULL) {
        printf("List is Empty!\n");
        return;
    }

    while (current != NULL) {
        printf(" %d -", current->data);
        current = current->next;
    }
    printf(" NULL\n");
}


void print_graph(linked_list graph[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("[%d]", i);
        print_list(&graph[i]);
    }
}


void insert_beggining(linked_list *list, int data) {
    struct nodo *new = malloc(sizeof(struct nodo));
    new->data = data;

    if (list->head == NULL) {
        list->head = new;
        list->tail = new;
    } else {
        new->next = list->head;
        list->head = new;
    }
}


void insert_end(linked_list *list, int data) {
    if (list->head == NULL)
        insert_beggining(list, data);
    else {
        struct nodo *new = malloc(sizeof(struct nodo));
        new->data = data;
        list->tail->next = new;
        list->tail = new;
    }
}


void reverse(linked_list *list) {
    struct nodo *current = list->head;
    struct nodo *next = NULL;
    struct nodo *previous = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    list->head = previous;
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
    struct nodo *current = temp->head;
    while (true) {
        if (current->data == ver2)
            return true;
        if (current->next == NULL)
            break;
        current = current->next;
    }
    return false;
}


void print_menu(linked_list graph[]) {
    int choice;
    int ver1, ver2;
    bool existe;

    while (1) {
        printf(".--------- Escolha uma Opcao ---------.\n");
        printf("| [1] Verificar aresta no grafo       |\n");
        printf("| [2] Exibir os vétices vizinhos      |\n");
        printf("| [3] Inserir aresta                  |\n");
        printf("| [4] Sair                            |\n");
        printf("'-------------------------------------'\n\n");
        
        printf("Grafo:\n");
        print_graph(graph);
        printf("\nSua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite os vértices (v v): ");
                scanf("%d %d", &ver1, &ver2); 
                existe = existe_aresta(graph, ver1, ver2);
                if (existe)
                    printf("Existe!\n");
                else
                    printf("Não existe!\n");
                break;
            case 2:
                printf("Informe o vertice: ");
                scanf("%d", &ver1);
                print_list(&graph[ver1]);
                break;
            case 3:
                printf("Informe os vertices (v v): ");
                scanf("%d %d", &ver1, &ver2);
                new_aresta(graph, ver1, ver2);
                break;
            case 4:
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

    print_menu(graph); 


    if (existe_aresta(graph, 1, 2))
        printf("Existe!\n");
}


