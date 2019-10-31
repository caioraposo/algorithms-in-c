#!/bin/sh

clang -c -g ../linked_list/linked_list.c -o linked_list.o
clang -c -g graph.c -o graph.o
clang -Wall -g main.c graph.o linked_list.o
clang -Wall -g test_dfs.c graph.o linked_list.o -o test
