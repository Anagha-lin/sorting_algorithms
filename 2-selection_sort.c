#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: Pointer to the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    /* Your implementation here */
    listint_t *insert_val, *first_iteration, *current;

    if (list == NULL || *list == NULL)
        return;

    for (current = (*list)->next; current != NULL; current = current->next)
    {
        for (first_iteration = current; first_iteration->prev != NULL; first_iteration = first_iteration->prev)
        {
            if (first_iteration->n < first_iteration->prev->n)
            {
                insert_val = first_iteration->prev;
                swap_nodes(list, &first_iteration, insert_val);
                print_list(*list);
            }
            else
            {
                break;
            }
        }
    }
}

