#include "sort.h"
#include <stdio.h>

/**
 * merge - Merges left and right arrays into the original array
 * @array: Pointer to array
 * @left: Pointer to the left array
 * @right: Pointer to the right array
 * @size: Size of the array
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_l)
		array[k++] = left[i++];

	while (j < size_r)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort_recursive - Recursively performs merge sort
 * @array: Pointer to array
 * @size: Size of the array
 **/
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (size < 2)
		return;

	mid = size / 2;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);
	merge(array, left, right, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Pointer to array
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_recursive(array, size);
}

