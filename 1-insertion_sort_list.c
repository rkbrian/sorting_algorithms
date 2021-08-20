#include "sort.h"

/**
 * insertion_sort_list - algorithm to sort numbers with insertion sort list
 * @list: doubly linked list to store array numbers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *prev_n = NULL, *next_n = NULL;
	listint_t *head = NULL;

	head = *list, current = head;
	while (current)
	{
		prev_n = current->prev;
		while (prev_n && prev_n->n > current->n)
		{
			next_n = current->next;
			if (prev_n->prev)
				prev_n->prev->next = current;
			current->prev = prev_n->prev;
			prev_n->next = next_n;
			prev_n->prev = current;
			if (next_n)
				next_n->prev = prev_n;
			current->next = prev_n;
			prev_n = current->prev;
			if (head->prev)
				head = head->prev;
			print_list(head);
		}
		current = current->next;
	}
	*list = head;
}
