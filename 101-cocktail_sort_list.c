#include "sort.h"

/**
 * cocktail_sort_list - algorithm to sort numbers with cocktail sort list
 * @list: doubly linked list to store array numbers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *prev_n = NULL, *next_n = NULL;
	listint_t *head = NULL, *tail = NULL, *print_h = NULL;

	if (list == NULL)
		return;
	head = *list, tail = head, print_h = head;
	while (tail->next)
		tail = tail->next;
	while (tail->n != head->n && tail->next != head)
	{
		current = head;
		while (current)
		{
			prev_n = current->prev;
			if (prev_n && prev_n->n > current->n)
				shake_right(prev_n, current, next_n, head, tail, print_h);
			current = current->next;
		}
		tail = tail->prev, current = tail;
		while (current)
		{
			next_n = current->next;
			if (next_n && current->n > next_n->n)
				shake_left(prev_n, current, next_n, head, tail, print_h);
			current = current->prev;
		}
		head = head->next;
	}
	while (print_h->prev)
		print_h = print_h->prev;
        *list = print_h;
}

/**
 * shake_right - switch nodes forward in doubly linked list
 * @prev_n: previous node
 * @current: current node
 * @next_n: next node
 * @head: head node for sorting range
 * @tail: tail node for sorting range
 * @print_h: true head node, also for printing purpose
 */
void shake_right(listint_t *prev_n, listint_t *current, listint_t *next_n,
		 listint_t *head, listint_t *tail, listint_t *print_h)
{
	next_n = current->next;
	if (prev_n->prev)
		prev_n->prev->next = current;
	current->prev = prev_n->prev, prev_n->next = next_n, prev_n->prev = current;
	if (next_n)
		next_n->prev = prev_n;
	current->next = prev_n;
	if (head->n == prev_n->n)
		head = head->prev;
	if (tail->n == current->n)
		tail = tail->next;
	while (print_h->prev)
		print_h = print_h->prev;
	print_list(print_h);
}

/**
 * shake_left - switch nodes backward in doubly linked list
 * @prev_n: previous node
 * @current: current node
 * @next_n: next node
 * @head: head node for sorting range
 * @tail: tail node for sorting range
 * @print_h: true head node, also for printing purpose
 */
void shake_left(listint_t *prev_n, listint_t *current, listint_t *next_n,
		listint_t *head, listint_t *tail, listint_t *print_h)
{
	prev_n = current->prev;
	if (next_n->next)
		next_n->next->prev = current;
	current->next = next_n->next, next_n->prev = prev_n, next_n->next = current;
	if (prev_n)
		prev_n->next = next_n;
	current->prev = next_n;
	if (head->n == current->n)
		head = head->prev;
	if (tail->n == next_n->n)
		tail = tail->next;
	while (print_h->prev)
		print_h = print_h->prev;
	print_list(print_h);
}
