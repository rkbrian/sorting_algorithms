#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void p_tree(int *array, int low_p, int high_p, size_t size);
size_t lomuto(int *array, int low_p, int high_p, size_t size);
/* advanced tasks */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void node_switch(listint_t *prev_n, listint_t *current, listint_t *next_n,
		listint_t *print_n);
void counting_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void recur_bitonic(int *arr, int len, int lowi, int seglen, int flag);
void seg_merge(int *arr, int len, int lowi, int seglen, int flag);
void quick_sort_hoare(int *array, size_t size);
size_t hoare(int *array, int low_p, int high_p, size_t size);

#endif /*sort of*/
