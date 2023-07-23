#include "sort.h"

/**
 * swap1 - swap two integers
 * @x: first integer
 * @y: second integer
 * Return: void
 */
void swap1(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - sort an array of integers in ascending order
 * @array: array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		size_t minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap1(&array[i], &array[minIndex]);
			print_array(array, size);
		}
	}
}
