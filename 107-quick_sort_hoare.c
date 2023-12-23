#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array and prints the array
 * @array: The array
 * @size: Size of the array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap(int *array, size_t size, size_t a, size_t b)
{
    if (array[a] != array[b])
    {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        print_array(array, size);
    }
}

/**
 * hoare_partition - Hoare partition scheme for quicksort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partition
 */
size_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap(array, size, i, j);
        }
        else
        {
            return j;
        }
    }
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot = hoare_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

