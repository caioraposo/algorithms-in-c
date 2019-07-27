#include "../binary_search_tree/binary_search_tree.h"



#ifndef AVL_TREE_H
#define AVL_TREE_H

/* A avl tree is a binary search tree with additional features */

node *rotate_left(node *root);
node *rotate_right(node *root);
int calc_balance_factor(node *root);



#endif
