#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	int *count, *output, max, i, j;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] = count[array[j]] + 1;
	for (i = 1; i <= max; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max + 1);
	for (j = size - 1; j >= 0; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]] = count[array[j]] - 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
