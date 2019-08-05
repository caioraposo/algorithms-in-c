#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_search_tree.h"


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;


typedef struct trunk {
    struct trunk *prev;
    char str[10];
} trunk;


trunk *new_trunk(trunk *prev, char str[10]) {
    trunk *new = malloc(sizeof(trunk));
    new->prev = prev;
    strcpy(new->str, str);
    return new;
}


void show_trunks(trunk *trunk) {

    if (trunk == NULL)
        return;

    show_trunks(trunk->prev);

    printf("%s", trunk->str);
}


node *new_node(int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}


node *insert(node *root, int data) {

    if (root == NULL)
        root = new_node(data);
    else if (root->data >= data)
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);

    return root;
}


void print_tree(node *root, trunk *prev, int is_right) {

    if (root == NULL)
        return;

    char prev_str[10] = "     ";
    trunk *trk = new_trunk(prev, prev_str);

    print_tree(root->right, trk, 1);
    
    if (!prev)
        strcpy(trk->str, "----");
    else if (is_right) {
        strcpy(trk->str, ".---");
        strcpy(prev_str, "    |");
    } else {
        strcpy(trk->str, "`---");
        strcpy(prev->str, prev_str);
    }
        
    show_trunks(trk);
    printf("%d\n", root->data);

    if (prev)
        strcpy(prev->str, prev_str);
    strcpy(trk->str, "    |");

    print_tree(root->left, trk, 0);
}


int tree_depth(node *root, int depth) {

    if (root == NULL)
        return depth;

    int right = tree_depth(root->right, depth + 1);
    int left = tree_depth(root->left, depth + 1);

    if (right >= left)
        return right;
    else
        return left;

}


void main() {
    node *root = NULL;
    int depth;
    
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 90);
    root = insert(root, 90);
    root = insert(root, 90);
    root = insert(root, 5);
    root = insert(root, 1);

    print_tree(root, NULL, 0);  

    depth = tree_depth(root, -1);

    printf("\nThe depth of the tree is: %d\n", depth);

    free(root);
}
