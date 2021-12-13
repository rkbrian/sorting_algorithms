#ifndef DECK_H
#define DECK_H

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * enum kind_e - the suits of card deck to be sorted in order
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
void chain_reaction(deck_node_t **array, int size);
void p_tree_deck(deck_node_t **array, int low_p, int high_p);
int hoare_deck(deck_node_t **array, int low_p, int high_p);
int card_select(const char *value);

#endif /*sort of*/
