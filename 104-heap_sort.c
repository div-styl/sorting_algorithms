#include "sort.h"
/**
 * heapify - heapify a subtree rooted with node i
 * @array: array to sort
 * @n: size of the array
 * @i: index
 * @size: size of the array
 * Return: void
*/
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;
	int n = size;

	for (i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i, size);
	for (i = n - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array, i, 0, size);
	}
}
