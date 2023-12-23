#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort (Hoare partition).
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    ssize_t pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

