#include "lists.h"

/**
 * check_cycle - Determines whether a cycle exists in a singly linked list.
 * @list: Pointer to the first node of the linked list.
 * Return: 1 if a cycle is detected, 0 if there is no cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);

	slow = list;
	fast = list->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
			return (1);  /* Found a cycle */

		slow = slow->next;
		fast = fast->next->next;
	}

	return (0);  /* No cycle found */
}
