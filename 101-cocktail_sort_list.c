#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node1: first node
 * @node2: second node
 * @list: doubly linked list
 * Return: void
*/
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp = NULL;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	temp = node2->next;
	node2->next = node1;
	node1->next = temp;
	node2->prev = node1->prev;
	node1->prev = node2;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 * Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	bool swapped = false;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = *list;

	while (swapped == false)
	{
		swapped = true;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				print_list(*list);
				swapped = false;
			}
			else
				current = current->next;
		}
		if (swapped == true)
			break;
		swapped = false;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				print_list(*list);
				swapped = false;
			}
			else
				current = current->prev;
		}
	}
}
