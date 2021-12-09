#include "sort.h"

/**
 * cocktail_sort_list - algorithm to sort numbers with cocktail sort list
 * @list: doubly linked list to store array numbers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *head = NULL, *tail = NULL, *print_h = NULL;
	int left = 0, right = 0, i = 0;

	if (list == NULL)
		return;
	head = *list, tail = *list, print_h = head;
	while (tail->next)
		tail = tail->next, right++;
	while (left < right)
	{
		current = head;
		for (i = left; i < right; i++)
		{
			if (current->next && current->n > current->next->n)
				node_switch(current, current->next, current->next->next, print_h);
			else
				current = current->next;
		}
		right--, i = 0;
		while (tail->prev)
			tail = tail->prev;
		while (i < right)
			tail = tail->next, i++;
		current = tail;
		for (i = right; i > left; i--)
		{
			if (current->prev && current->prev->n > current->n)
				node_switch(current->prev, current, current->next, print_h);
			else
				current = current->prev;
		}
		left++, i = 0;
		while (head->prev)
			head = head->prev;
		while (i < left)
			head = head->next, i++;
	}
	while (print_h->prev)
		print_h = print_h->prev;
	*list = print_h;
}

/**
 * node_switch - switch nodes in doubly linked list
 * @prev_n: previous node
 * @current: current node
 * @next_n: next node
 * @print_h: true head node, also for printing purpose
 */
void node_switch(listint_t *prev_n, listint_t *current, listint_t *next_n,
		listint_t *print_h)
{
	next_n = current->next;
	if (prev_n->prev)
		prev_n->prev->next = current;
	current->prev = prev_n->prev, prev_n->next = next_n, prev_n->prev = current;
	if (next_n)
		next_n->prev = prev_n;
	current->next = prev_n;
	while (print_h->prev)
		print_h = print_h->prev;
	print_list(print_h);
}
