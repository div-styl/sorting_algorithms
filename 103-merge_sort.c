#include "sort.h"
/**
 * merge - merge two subarrays
 * @array: array to be sorted
 * @temp: temp array
 * @left: left index
 * @mid: mid index
 * @right: right index
 * Return: void
*/
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	for (i = left, j = mid + 1, k = left; k <= right; k++)
	{
		if (i <= mid && (j > right || array[i] <= array[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	for (i = left; i <= right; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
/**
 * merge_sort_helper - helper function for merge sort
 * @array: array to be sorted
 * @temp: temp array
 * @left: left index
 * @right: right index
 * Return: void
*/
void merge_sort_helper(int *array, int *temp, int left, int right)
{
	int mid;

	if (right <= left)
		return;
	mid = (right + left - 1) / 2;
	merge_sort_helper(array, temp, left, mid);
	merge_sort_helper(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}
/**
 * merge_sort - sorting using merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
		int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
