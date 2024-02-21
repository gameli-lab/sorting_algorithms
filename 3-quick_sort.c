#include "sort.h"
/**
 * swap - swaps ints
 * @a: first int
 * @b: second int
 */


void swap(int *a, int *b)
{
	if (a != b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

/**
 * partition - divides the array
 * @array: array to sort
 * @low: lower part of array
 * @high: higher part of the array
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return i + 1;
}

/**
 * quick_sort_helper -helps sorts ints
 * @array: array to sort
 * @low: lower part of array
 * @high: higher part of the array
 */


void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort_helper(array, low, pi - 1);
		quick_sort_helper(array, pi + 1, high);
	}
}
/**
 * quick_sort - sorts the integers
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}

