#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of int in ascending order using Counting sort
 * @array: Pointer to the array
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value, j;
	int *count_array, *temp_array;
	size_t i;

	if (!array || size < 2)
		return;

	max_value = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count_array = calloc((max_value + 1), sizeof(int));

	if (!count_array)
		return;

	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}

	for (j = 1; j <= max_value; j++)
	{
		count_array[j] += count_array[j - 1];
	}

	print_array(count_array, max_value + 1);

	temp_array = malloc(sizeof(int) * size);

	if (!temp_array)
	{
		free(count_array);
		return;
	}

		for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		temp_array[count_array[array[i]]] = array[i];
	}

		for (i = 0; i < size; i++)
	{
		array[i] = temp_array[i];
	}

		free(temp_array);
		free(count_array);
}

