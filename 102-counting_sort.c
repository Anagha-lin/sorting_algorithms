#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_counting_array - Prints the counting array
 * @counting_array: The counting array to be printed
 * @size: The size of the counting array
 */
static void print_counting_array(int *counting_array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", counting_array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array to store the count of each element */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    /* Initialize the counting array */
    for (i = 0; i <= (size_t)max; i++)  /* Cast max to size_t for comparison */
        counting_array[i] = 0;

    /* Populate the counting array with the count of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_counting_array(counting_array, max + 1);

    /* Update the original array based on the counting array */
    size_t j = 0;
    for (i = 0; i <= (size_t)max; i++)  /* Cast max to size_t for comparison */
    {
        while (counting_array[i] > 0)
        {
            array[j] = i;
            j++;
            counting_array[i]--;
        }
    }

    /* Free the counting array */
    free(counting_array);
}

