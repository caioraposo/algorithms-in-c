#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 50



void insert(int array[], int index, int data) {
	if (index > SIZE)
		printf("ERROR: tried to insert beyond the array size.\n");
	else
		array[index] = data;
}


void delete(int array[], int index) {
	array[index] = NULL;
}


void print_array(int array[]) {
	int i;
	for (i = 0; i < SIZE; i++)
		printf("%d ", array[i]);

	printf("\n");
}


void fill_with_random_numbers(int array[]) {
	int i;
	for (i = 0; i < SIZE; i++)
		array[i] = rand();	
}


void main() {
	srand(time(0));

	int *ptr = malloc(sizeof(int) * SIZE);

	int array[SIZE];
	
	insert(ptr, 51, 50);
	fill_with_random_numbers(ptr);
	fill_with_random_numbers(array);
	print_array(ptr);
	print_array(array);

	free(ptr);
}
