#include "sort.h"

/**
 * insertion_sort_list - algorithm to sort numbers with insertion sort list
 * @list: doubly linked list to store array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t current = NULL, prev_n = NULL, next_n = NULL, anchor = NULL;
	int tmp_num;

	current = *list;
	while (current)
	{
		anchor = current;

		next_n = current->next;
		if (next_n->n < current->n)
		{
			prev_n = current->prev;
			tmp_num = current->n;
			current->n = prev_n->n;
			prev->n = tmp_num;
		}

	}
}

/**
 * create_listint - function to create doubly linked list
 * @array: unsorted array
 * @size: size of array
 * Return: doubly linked list
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *current = NULL, *prev_n = NULL, *next_n = NULL, *head = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (current)
			current->prev = prev_node, current = current->next
		current = malloc(sizeof(listint_t));
		if (current == NULL)
		{
			for (i--; i >= 0; i--)
				current = current->prev, free(current);
			return (NULL);
		}
		current->n = array[i];
		if (i == 0)
			head = current, current->prev = NULL;
		prev_n->next = current, prev_n = current;
	}

	return (head);
}
