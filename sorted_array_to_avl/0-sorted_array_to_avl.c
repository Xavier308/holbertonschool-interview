#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Allocates and initializes a new AVL tree node.
 * @parent: Pointer to the parent node.
 * @value: Integer value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL if memory allocation fails.
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));
if (!node)
	return (NULL);

node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;

return (node);
}

/**
 * sorted_array_to_avl_helper - Constructs a balanced AVL subtree.
 * @array: Sorted array of integers.
 * @start: Starting index of the subarray to convert.
 * @end: Ending index of the subarray to convert.
 * @parent: Pointer to the parent node of the current subtree.
 *
 * Return: Pointer to the root node of the constructed subtree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl_helper(int *array,
int start, int end, avl_t *parent)
{
	if (start > end)
		return (NULL);

	int mid = start + (end - start) / 2;
	avl_t *root = create_avl_node(parent, array[mid]);
if (!root)
	return (NULL);

root->left = sorted_array_to_avl_helper(array, start, mid - 1, root);
root->right = sorted_array_to_avl_helper(array, mid + 1, end, root);

return (root);
}

/**
 * sorted_array_to_avl - Converts a sorted array into a balanced AVL tree.
 * @array: Pointer to the first element of the sorted integer array.
 * @size: Total number of elements in the array.
 *
 * Return: Pointer to the root node of the newly created AVL tree,
 * or NULL if the input is invalid or memory allocation fails.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
