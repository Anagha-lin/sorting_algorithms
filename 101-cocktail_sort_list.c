#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 * @head: Pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	if (!head || !node1 || !*node1 || !node2)
	return;

	if ((*node1)->prev)
	(*node1)->prev->next = node2;
	else
	*head = node2;

	if (node2->next)
	node2->next->prev = *node1;

	(*node1)->next = node2->next;
	node2->prev = (*node1)->prev;
	(*node1)->prev = node2;
	node2->next = *node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *		in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (!list || !*list)
	return;

	while (swapped)
	{
	swapped = 0;

	/* Forward iteration (similar to bubble sort) */
	for (start = *list; start->next != end; start = start->next)
	{
	if (start->n > start->next->n)
	{
	swap_nodes(list, &start, start->next);
	print_list(*list);
	swapped = 1;
	}
	}

		if (!swapped)
		break;

		swapped = 0;

			/* Backward iteration */
			for (end = start; end->prev != NULL; end = end->prev)
			{
			if (end->prev->n > end->n)
			{
			swap_nodes(list, &(end->prev), end);
			print_list(*list);
			swapped = 1;
			}
		}
	}
}

