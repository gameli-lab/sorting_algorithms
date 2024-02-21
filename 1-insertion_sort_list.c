#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *  order using the Insertion Sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap temp and temp->prev */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

		/* Update current if temp was moved to the beginning */
			if (temp->prev == NULL)
				current = temp;

		/* Print the list after swapping */
			print_list(*list);
		}
	}
}
