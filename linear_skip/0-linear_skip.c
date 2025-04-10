#include "search.h"

/**
 * linear_skip - Searches for value in sorted skip list
 * @list: Head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to node with value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start = list, *end = NULL;

	if (!list)
		return (NULL);

	/* Use express lane to find range */
	while (start->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			start->express->index, start->express->n);
		if (start->express->n >= value)
		{
			end = start->express;
			break;
		}
		start = start->express;
	}

	/* Handle case when value is in last segment */
	if (!end)
	{
		end = start;
		while (end->next)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		start->index, end->index);

	/* Linear search in found range */
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
