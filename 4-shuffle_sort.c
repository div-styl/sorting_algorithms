#include "sort.h"
/**
 * shuffle - Shuffles an array
 * @array: The array to shuffle
 * @size: The size of the array
 * Return: Nothing
* */
void shuffle(int array[], size_t size)
{
  size_t i, j;
  int tmp;
    srand(time(NULL)); /*initialize random seed*/
    for (i = size - 1; i > 0; i--)
    {
        j = rand() % (i + 1); /*pick a random index between 0 and i*/
        tmp = array[i]; /*swap arr[i] with arr[j]*/
        array[i] = array[j];
        array[j] = tmp;
    }
}
/**
 * shuffle_sort - Sorts an array
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
* */
void shuffle_sort(int array[], size_t size) 
{
  size_t i;
  int key, j;
    shuffle(array, size); /*shuffle the array first*/
    for (i = 1; i < size; i++)
  {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        print_array(array, size); 
        array[j+1] = key;
    }
}

