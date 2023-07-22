#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 * 
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
        *   For example, if array size is 1000 and gap is 200,
        *  we can create 5 subarrays of size 200
        * subarray 1: 0, 200, 400, 600, 800
        * subarray 2: 1, 201, 401, 601, 801
        * subarray 3: 2, 202, 402, 602, 802
        * subarray 4: 3, 203, 403, 603, 803
        * subarray 5: 4, 204, 404, 604, 804
        * After insertion sort on all subarrays, we get the gap to 100
        * subarray 1: 0, 100, 200, 300, 400, 500, 600, 700, 800, 900
        * subarray 2: 1, 101, 201, 301, 401, 501, 601, 701, 801, 901
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
            /**
             * shift earlier gap-sorted elements up until the correct
             * location for a[i] is found
             * The loop below does insertion sort for a[i] with gap
             * as gap
            */
            while (j > gap - 1 && array[j - gap] >= temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            /**
             * put temp (the original a[i]) in its correct location
             * in this subarray
             * Note that we use j-gap because j is decremented
             * by gap
            */
            array[j] = temp;
        }
        /*calculate the next gap*/
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}