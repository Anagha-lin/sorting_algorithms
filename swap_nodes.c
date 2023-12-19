#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @head: Pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
    if (*node1 == node2)
        return;

    if (node2->prev != NULL)
        node2->prev->next = *node1;
    else
        *head = *node1;

    if ((*node1)->prev != NULL)
        (*node1)->prev->next = node2;
    else
        *head = node2;

    if (node2->next != NULL)
        node2->next->prev = *node1;

    if ((*node1)->next != NULL)
        (*node1)->next->prev = node2;

    listint_t *temp = (*node1)->prev;
    (*node1)->prev = node2->prev;
    node2->prev = temp;

    temp = (*node1)->next;
    (*node1)->next = node2->next;
    node2->next = temp;
}

