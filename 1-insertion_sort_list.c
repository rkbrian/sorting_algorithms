#include "sort.h"

/**
 * insertion_sort_list - algorithm to sort numbers with insertion sort list
 * @list: doubly linked list to store array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t current = NULL, anchor = NULL, next_n = NULL, head = NULL;
	int tmp_num;

	head = *list, current = head;
	while (current && current->next)
	{
		anchor = current;
		next_n = current->next;
		while (next_n->n < current->n)
		{
			tmp_num = current->n;
			current->n = next_n->n;
			next_n->n = tmp_num;
			if (current->prev)
				next_n = current, current = current->prev;
		}
		current = anchor->next;
	}
	*list = head;
}

/**
 * create_listint - function to create doubly linked list
 * @array: unsorted array
 * @size: size of array
 * Return: doubly linked list
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *current = NULL, *prev_n = NULL, *head = NULL;
	size_t i;

	if (array == NULL || size <= 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		current = malloc(sizeof(listint_t));
		if (current == NULL)
		{
			for (i--; i >= 0; i--)
				current = current->prev, free(current);
			return (NULL);
		}
		if (i > 0)
			current->prev = prev_n;
		current->n = array[i];
		if (i == 0)
			current->prev = NULL, current->next = NULL, prev_n = current, head = current;
		else
			current->next = NULL, prev_n->next = current, prev_n = current;
	}
	return (head);
}
