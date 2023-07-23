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
 * get_first_min - get the first minimum value
 * @array: array
 * @size: size of array
 * Return: void
*/
void get_first_min(int array[], size_t size)
{
	size_t i = 1;
	int min = array[0];
	size_t minIndex = 0;

	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			minIndex = i;
		}
		i++;
	}
	if (minIndex != 0)
	{
		swap1(&array[0], &array[minIndex]);
	}
}

/**
 * selection_sort - sort an array of integers in ascending order
 * @array: array
 * @size: size of array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i;

	get_first_min(array, size);

	for (i = 1; i < size - 1; i++)
	{
		size_t j;
		size_t minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		swap1(&array[i], &array[minIndex]);
	}
}
