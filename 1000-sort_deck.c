#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * card_compare - Compare two cards
 * @a: First card
 * @b: Second card
 * Return: Difference between the kinds or values of the cards
 */
int card_compare(const void *a, const void *b)
{
    const card_t *card_a = (*(deck_node_t **)a)->card;
    const card_t *card_b = (*(deck_node_t **)b)->card;

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;

    return strcmp(card_a->value, card_b->value);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0;
    deck_node_t *current = *deck;
    deck_node_t **array;
    size_t i;

    while (current)
    {
        count++;
        current = current->next;
    }

    array = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
    if (!array)
        return;

    for (i = 0; i < count; i++)
    {
        array[i] = current;
        current = current->next;
    }

    qsort(array, count, sizeof(deck_node_t *), card_compare);

    for (i = 0; i < count - 1; i++)
    {
        array[i]->next = array[i + 1];
        array[i + 1]->prev = array[i];
    }

    array[0]->prev = NULL;
    array[count - 1]->next = NULL;

    *deck = array[0];

    free(array);
}

