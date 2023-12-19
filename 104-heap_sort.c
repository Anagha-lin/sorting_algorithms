#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Repair the heap whose root element is at index start
 * @array: Array to heapify
 * @start: Index of the root of the heap
 * @end: Last index in the heap
 * @size: Size of the array
 **/
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	size_t swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			swap_int(&array[root], &array[swap]);
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - Function to build a heap
 * @array: Array to heapify
 * @size: Size of the array
 **/
void heapify(int *array, size_t size)
{
	int start;

	if ((size % 2) == 0)
		start = (size / 2) - 1;
	else
		start = size / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	end = size - 1;

	while (end > 0)
	{
		swap_int(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

