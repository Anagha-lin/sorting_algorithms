#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Returns the maximum value in an array
 * @array: Array to find the maximum value
 * @size: Size of the array
 * Return: Maximum value in the array
 **/
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Performs counting sort on an array based on significant place
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Current exponent place value
 **/
void countingSort(int *array, size_t size, int exp)
{
	int *output = NULL;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so that count[i] now has actual position of this digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to array[], so that array[] now has sorted num accordin to the current digit */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the current array */
	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the LSD Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}

