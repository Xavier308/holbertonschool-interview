#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A double pointer to the head of the list.
 * Description: This function reverses the order of the nodes in a linked list.
 *              It iterates through the list, reversing the direction
 *              of each node's next pointer until the entire list is reversed.
 * Return: A pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * find_middle - Finds the middle node of a linked list.
 * @head: A pointer to the head of the list.
 * Description: This function uses the fast and slow pointer technique to
 *              find the middle of the list. The fast pointer moves at twice
 *              the speed of the slow pointer. When the fast pointer reaches
 *              the end of the list, the slow pointer will be at the middle.
 * Return: A pointer to the middle node of the list.
 */
listint_t *find_middle(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: A double pointer to the head of the list.
 * Description: Determines if a linked list is a palindrome by comparing
 *              the first half of the list with the reversed second half.
 *              If they are identical, the list is a palindrome.
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle, *second_half, *first_half;
	int is_pal = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	middle = find_middle(*head);
	second_half = reverse_listint(&middle);

	first_half = *head;
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_pal = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	reverse_listint(&middle); /* Restore original list */
	return (is_pal);
}
