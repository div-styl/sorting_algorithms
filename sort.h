#ifndef sort_H
#define sort_H

/*headers*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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

/*printing list and array and create it*/
listint_t *create_listint(const int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*sorting prototypes*/
void insertion_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);

/* 2. selection sort */
void swap1(int *x, int *y);
void get_first_min(int array[], size_t size);
void selection_sort(int *array, size_t size);

/* 3. Quick sort */
int lomuto_partition(int *array, int low, int high, size_t size);
void swap2(int *x, int *y);
void get_first_min(int array[], size_t size);
void quickSort(int array[], int low, int high, size_t size);
void quick_sort(int *array, size_t size);
/* V4.0. Shuffle sort */
void shuffle(int array[], size_t size);
void shuffle_sort(int array[], size_t size);

/* 4. Shell sort */
void shell_sort(int *array, size_t size);
/* 5. cocktail_sort_list */
void cocktail_sort_list(listint_t **list);
/*6 counting_sort*/
void counting_sort(int *array, size_t size);
/*7. merge sort*/
void merge_sort(int *array, size_t size);
/*8. heap_sort*/
void heap_sort(int *array, size_t size);
/*11. Quick Sort - Hoare Partition scheme */

void swap3(int *a, int *b);
int partition2(int arr[], int low, int high, size_t size);
void quickSort2(int arr[], int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* sort_H */
