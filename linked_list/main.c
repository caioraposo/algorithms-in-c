#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


void main() {
    int data, choice;
    linked_list list;
    initialize(&list);
    
    printf(".----- Choose an Option -----.\n");
    printf("| [1] Insert from beggining  |\n");
    printf("| [2] Insert in the end      |\n");
    printf("| [3] Reverse List           |\n");
    printf("| [4] List Size              |\n");
    printf("| [5] Exit                   |\n");
    printf("'----------------------------'\n\n");
    while (1) {
        print_list(&list);

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Type the value: ");
                scanf("%d", &data);
                insert_beggining(&list, data);
                break;
            case 2:
                printf("Type the value: ");
                scanf("%d", &data);
                insert_end(&list, data);
                break;
            case 3:
                reverse(&list);
                break;
            case 4:
                printf("List size: %d\n", list_size(list.head, 0));
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid Option!\n");
                break;
        }
        printf("\n");
    }
}
