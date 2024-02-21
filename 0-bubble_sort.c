#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	for (i = 0; i < size ; i++)
		for (j = 0; j < (size - 1); j++)
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				for (k = 0; k < size; k++)
				{
					write(1, &array[k], sizeof(int));
					if (k < (size - 1))
						write(1, ", ", 2);
				}
			}
	write(1, "\n", 1);

}

