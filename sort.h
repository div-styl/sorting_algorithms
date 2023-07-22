#ifndef sort_H
#define sort_H

/*headers*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*structures*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/*printing list and array*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
/*sorting prototypes*/
void bubble_sort(int *array, size_t size);
/* 2. selection sort */
void swap1(int *x, int *y);
void get_first_min(int array[], size_t size);
void selection_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
/* 3. Quick sort */
void swap2(int *x, int *y);
void get_first_min(int array[], size_t size);
void quickSort(int array[], int low, int high);
void quick_sort(int *array, size_t size);

/*4 . shell sort*/

void shell_sort(int *array, size_t size);
#endif
