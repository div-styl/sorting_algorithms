#include "sort.h"
/**
 *  swap - swaps two integers
 * @x: pointer to first integer
 * @y: pointer to second integer
 * Return: void
 */
void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
    /*printf("Swapped %d and %d\n", *x, *y);
    printf("tmp: %d\n", tmp);*/
}
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    bool swapping;

    /**
     * check wither the array is null or not and size of array should
     * has 2 elements at least
     * if not return void
    */
    if (array == NULL || size < 2)
        return;

    /**
     * loop through the array and compare each element with the next one
     * if the next element is greater than the current one swap them
     * and print the array
     * if no swapping happened break the loop
     * and print the array
     *
     * i is the number of iterations
     * j is the index of the array
     * swapping is a flag to check if any swapping happened
     * if no swapping happened break the loop
     * and print the array
     * 
     * the first loop is to loop through the array
     * the second loop is to compare each element with the next one
    */
    for (i = 0; i < size - 1; i++)
    {
        swapping = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapping = true;
                print_array(array, size);
            }
        }
        if (swapping == false)
            break;
    }
}