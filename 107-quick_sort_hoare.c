#include "sort.h"

void swap3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition2(int arr[], int low, int high, size_t size)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {

        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i > j)
            return j;

        swap3(&arr[i], &arr[j]);

        print_array(arr, size);
    }
}

void quickSort2(int arr[], int low, int high, size_t size)
{
    if (low < high)
    {

        int pi = partition2(arr, low, high, size);

        quickSort2(arr, low, pi, size);
        quickSort2(arr, pi + 1, high, size);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    int high = size - 1;

    quickSort2(array, 0, high, size);
}
