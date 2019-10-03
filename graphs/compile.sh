#!/bin/sh

gcc -c ../linked_list/linked_list.c -o linked_list.o
gcc -c graph.c -o graph.o
gcc -Wall -g main.c graph.o linked_list.o
