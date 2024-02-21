#include "sort.h"



void swap(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quick_sort_helper(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort_helper(array, low, pi - 1);
        quick_sort_helper(array, pi + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    quick_sort_helper(array, 0, size - 1);
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, size);

    // Printing the sorted array
    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

