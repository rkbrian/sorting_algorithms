#include "deck.h"

/**
 * chain_reaction - link all the card nodes in the same suits
 * @array: array of card nodes
 * @size: card amount of the same suits
 */
void chain_reaction(deck_node_t **array, int size)
{
	int i = 0;

	while (i < size)
	{
		if (i == 0)
			array[i]->prev = NULL;
		else
			array[i]->prev = array[i - 1];
		if (i == size - 1)
			array[i]->next = NULL;
		else
			array[i]->next = array[i + 1];
		i++;
	}
}

/**
 * p_tree_deck - generate pivot tree
 * @array: unsorted array of nodes
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 */
void p_tree_deck(deck_node_t **array, int low_p, int high_p)
{
	int party;

	if (low_p < high_p)
	{
		party = hoare_deck(array, low_p, high_p);
		p_tree_deck(array, low_p, party - 1);
		p_tree_deck(array, party, high_p);
	}
}

/**
 * hoare_deck - Hoare partition to sorting array and return new array section
 * @array: unsorted array
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 * Return: next pivot, the index for splitting
 */
int hoare_deck(deck_node_t **array, int low_p, int high_p)
{
	int i, j, pivot;
	deck_node_t *tmp = NULL;

	pivot = card_select(array[high_p]->card->value);
	while (low_p < high_p)
	{
		i = low_p, j = high_p;
		while (card_select(array[i]->card->value) < pivot)
			i++;
		while (card_select(array[j]->card->value) > pivot)
			j--;
		if (j <= i)
			return (j);
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
	return (high_p);
}

/**
 * card_select - select cards
 * @value: card value
 * Return: value in integer
 */
int card_select(const char *value)
{
	if (value[0] == 'A')
		return (ACE);
	else if (value[0] == 'J')
		return (JACK);
	else if (value[0] == 'Q')
		return (QUEEN);
	else if (value[0] == 'K')
		return (KING);
	return (atoi(value));
}

/**
 * sort_deck - function that sorts a deck of cards.
 *  Notes: no qsort, it requires const ptr return
 * @deck: deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	int a = 0, b = 0, c = 0, d = 0;
	deck_node_t *head = NULL, *current = NULL, *tmp = NULL;
	deck_node_t *Spades[52], *Hearts[52], *Clubs[52], *Diamonds[52];

	head = *deck, current = head;
	while (current)
	{
		tmp = current, current = current->next;
		if (tmp->card->kind == SPADE)
			Spades[a] = tmp, tmp->next = NULL, tmp->prev = NULL, a++;
		if (tmp->card->kind == HEART)
			Hearts[b] = tmp, tmp->next = NULL, tmp->prev = NULL, b++;
		if (tmp->card->kind == CLUB)
			Clubs[c] = tmp, tmp->next = NULL, tmp->prev = NULL, c++;
		if (tmp->card->kind == DIAMOND)
			Diamonds[d] = tmp, tmp->next = NULL, tmp->prev = NULL, d++;
	}
	p_tree_deck(Spades, 0, a - 1), p_tree_deck(Hearts, 0, b - 1);
	p_tree_deck(Clubs, 0, c - 1), p_tree_deck(Diamonds, 0, d - 1);
	chain_reaction(Spades, a), chain_reaction(Hearts, b);
	chain_reaction(Clubs, c), chain_reaction(Diamonds, d);
	Spades[a - 1]->next = Hearts[0], Hearts[0]->prev = Spades[a - 1];
	Hearts[b - 1]->next = Clubs[0], Clubs[0]->prev = Hearts[b - 1];
	Clubs[c - 1]->next = Diamonds[0], Diamonds[0]->prev = Clubs[c - 1];
	*deck = Spades[0];
}
