#include "sort.h"

void swap2(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            swap2(&array[j], &array[i]);

            i++;
        }
    }
    swap2(&array[i], &array[high]);

    return i;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int center = partition(array, low, high);

        quickSort(array, low, center - 1);
        quickSort(array, center + 1, high);
    }
}

void quick_sort(int *array, size_t size)
{
    int low = 0;
    int high = size - 1;

    quickSort(array, low, high);
}