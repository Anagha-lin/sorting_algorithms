#include "sort.h"
#include <stdio.h>

/**
 * print_subarray - Prints a subarray of integers
 * @array: Array to be printed
 * @start: Starting index of the subarray
 * @size: Size of the subarray
 **/
void print_subarray(int *array, size_t start, size_t size)
{
	size_t i;

	for (i = start; i < start + size; i++)
	{
	printf("%d", array[i]);
	if (i < start + size - 1)
	printf(", ");
	}
}

/**
 * bitonic_merge - Merges two halves of an array in the specified order
 * @array: Array to be merged
 * @start: Starting index of the first half
 * @size: Size of each half to be merged
 * @dir: 1 for ascending order, 0 for descending order
 **/
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t i, step;

	if (size > 1)
	{
	step = size / 2;
	for (i = start; i < start + step; i++)
	{
		if ((array[i] > array[i + step]) == dir)
		{
		int temp = array[i];
		array[i] = array[i + step];

		array[i + step] = temp;
		printf("Merging [%lu/%lu] (%s):\n", size, size * 2, dir ? "UP" : "DOWN");
		print_subarray(array, start, size * 2);
		printf("\n");
		}
	}
	bitonic_merge(array, start, step, dir);
	bitonic_merge(array, start + step, step, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively applies Bitonic sort
 * @array: Array to be sorted
 * @start: Starting index of the subarray to be sorted
 * @size: Size of the subarray to be sorted
 * @dir: 1 for ascending order, 0 for descending order
 **/
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	size_t step;

	if (size > 1)
	{
	step = size / 2;
	bitonic_sort_recursive(array, start, step, 1);
	bitonic_sort_recursive(array, start + step, step, 0);
	bitonic_merge(array, start, size, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of int in ascending order using the Bitonic sort algthm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2 || (size & (size - 1)) != 0)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

