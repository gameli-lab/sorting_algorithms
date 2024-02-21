#include "sort.h"



void printArray(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)

		printf("%d ", array[i]);

    printf("\n");
}



void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;
	/*int i, j, k, min, temp;*/

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++) 
			if (array[j] < array[min])
				min = j;
	}

        if (min != i)
	{
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

	/*for (k = 0; k < size - 1; k++)
		write(1, &array[k],sizeof(int));*/
	printArray(array, size);
}
