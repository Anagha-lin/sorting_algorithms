#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 *
 * @list: Pointer to the head of the doubly linked list
 */
void print_list(const listint_t *list)
{
	while (list != NULL)
	{
	printf("%d", list->n);
	list = list->next;
	if (list != NULL)
	printf(", ");
	}
	printf("\n");
}

