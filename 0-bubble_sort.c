#include "sort.h"

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print array after each swap */
				print_array(array, size);
				swapped = 1;
			}
		}

		/* If no swaps were made, the array is already sorted */
		if (!swapped)
			break;
	}
}

