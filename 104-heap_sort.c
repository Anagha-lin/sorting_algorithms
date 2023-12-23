#include "sort.h"
#include <stdio.h>

/**
 * swap_int - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 **/
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Sifts down the element at index 'root' in a heap
 * @array: Array representing the heap
 * @size: Size of the array/heap
 * @root: Index of the root element
 * @end: Index where the heap portion ends
 **/
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t left_child, swap, root_idx;

    root_idx = root;
    left_child = 2 * root + 1;

    while (left_child <= end)
    {
        swap = root_idx;
        if (array[swap] < array[left_child])
            swap = left_child;
        if (left_child + 1 <= end && array[swap] < array[left_child + 1])
            swap = left_child + 1;
        if (swap == root_idx)
            return;

        swap_int(&array[root_idx], &array[swap]);
        print_array(array, size);
        root_idx = swap;
        left_child = 2 * root_idx + 1;
    }
}

/**
 * heapify - Builds a heap from an array
 * @array: Array to be transformed into a heap
 * @size: Size of the array
 **/
void heapify(int *array, size_t size)
{
    ssize_t i;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (!array || size < 2)
        return;

    heapify(array, size);

    for (end = size - 1; end > 0; end--)
    {
        swap_int(&array[0], &array[end]);
        print_array(array, size);
        sift_down(array, size, 0, end - 1);
    }
}

