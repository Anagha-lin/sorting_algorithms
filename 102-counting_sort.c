#include "sort.h"

/**
 * get_max - Finds the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int max_value = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    return max_value;
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setup.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
        return;

    int max_value = get_max(array, size);
    int *count_array = malloc(sizeof(int) * (max_value + 1));
    if (count_array == NULL)
    {
        free(sorted_array);
        return;
    }

    for (int i = 0; i <= max_value; i++)
        count_array[i] = 0;

    for (int i = 0; i < (int)size; i++)
        count_array[array[i]] += 1;

    for (int i = 1; i <= max_value; i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max_value + 1);

    for (int i = (int)size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]] -= 1;
    }

    for (int i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(count_array);
}

