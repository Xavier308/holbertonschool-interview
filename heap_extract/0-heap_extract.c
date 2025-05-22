#include "binary_trees.h"

/**
 * heapify_down - Shift a node down until the heap property is restored.
 * @node: Pointer to the starting node.
 */
void heapify_down(heap_t *node)
{
	heap_t *max_child = NULL;
	int temp;

	while (node)
	{
		max_child = node;

		if (node->left && node->left->n > max_child->n)
			max_child = node->left;
		if (node->right && node->right->n > max_child->n)
			max_child = node->right;

		if (max_child == node)
			break;

		temp = node->n;
		node->n = max_child->n;
		max_child->n = temp;

		node = max_child;
	}
}

/**
 * find_last_node - Locate the last node in a level-order traversal.
 * @root: Pointer to the heap's root.
 *
 * Return: Pointer to the final node visited.
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		root = queue[front++];
		if (root->left)
			queue[rear++] = root->left;
		if (root->right)
			queue[rear++] = root->right;
	}

	return (root);
}

/**
 * heap_extract - Remove and return the root value from a max binary heap.
 * @root: Double pointer to the heap's root node.
 *
 * Return: Extracted value, or 0 if heap is empty.
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = find_last_node(*root);

	(*root)->n = last->n;

	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last);

	heapify_down(*root);

	return (value);
}
