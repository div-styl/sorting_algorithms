#include "sort.h"
/**
 * swap2 - swap two integers
 * @x: first integer
 * @y: second integer
 * Return: void
 */
void swap2(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - partition the array
 * @array: array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	(void)size;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap2(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap2(&array[i], &array[high]);
		print_array(array, size);
	}

	return i;
}
/**
 * quickSort - quick sort algorithm
 * @array: array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: void
 */
void quickSort(int array[], int low, int high, size_t size)
{
	if (low < high)
	{
		int center = lomuto_partition(array, low, high, size);

		quickSort(array, low, center - 1, size);
		quickSort(array, center + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (!array || size < 2)
		return;

	quickSort(array, low, high, size);
}
