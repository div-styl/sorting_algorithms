#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/*chech if the array is null and size must be up to 2 elements*/
	if (array == NULL || size < 2)
		return;
	/*split the array into half*/
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/**
	 * Start with the largest gap and work down to a gap of 1
	 * Perform insertion sort on all subarrays with gap
	 *	For example, if size is 1000 and gap is 500,
	 *	we can consider the subarrays array[0..499],
	 *	array[500..999] and array[1000..1499]
	*/
	while (gap > 0)
	{
		/**
		 * Do a gapped insertion sort for this gap size.
		 * The first gap elements a[0..gap-1] are already in gapped order
		 * keep adding one more element until the entire array is
		 * gap sorted
		*/
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		/*calculate the next gap*/
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
