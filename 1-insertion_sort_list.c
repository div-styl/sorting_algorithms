#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: pointer to a pointer to the list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *nnext = NULL, *pprev = NULL;

	/* Check if the list is empty or has only one element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/**
	 * Loop through the list and compare the current node with the next node.
	 * If the current node's value is greater than the next node's value,
	 * swap the nodes and move to the previous node to continue comparing.
	 * If the current node's value is less than or equal to the next node's value,
	 * move to the next node to continue the sorting process.
	 * If the current node is the last node, move to the next node (nnext).
	 * If the current node is the first node, move to the next node (nnext).
	 * The inner while loop performs the swapping
	 * and sorting process for each node
	*/
	for (current = (*list)->next; current != NULL; current = nnext)
	{
		nnext = current->next;
		pprev = current->prev;
		while (pprev != NULL && pprev->n > current->n)
		{
			if (pprev->prev != NULL)
				pprev->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = pprev;
			pprev->next = current->next;
			current->prev = pprev->prev;
			current->next = pprev;
			pprev->prev = current;
			pprev = current->prev;
			print_list(*list);
		}
	}
}
