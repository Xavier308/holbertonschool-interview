#include "lists.h"

/**
 * find_listint_loop - Locates the starting node of a cycle in a linked list
 * @head: Pointer to the first element of the list
 *
 * Return: Pointer to the node where the cycle begins, or NULL if none exists
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head || !head->next)
		return (NULL);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow); /* Start of loop */
		}
	}

	return (NULL); /* No cycle found */
}
