/* File: 0-merge_sort.c */
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * merge_subarray - merges two sorted halves of an array
 * @array: pointer to the array containing subarrays
 * @start: starting index of the first subarray
 * @mid: starting index of the second subarray
 * @end: index one past the end of the second subarray
 * @buffer: auxiliary buffer for merged output
 */
static void merge_subarray(int *array, size_t start,
	size_t mid, size_t end, int *buffer)
{
	size_t i, j, k, left_size, right_size;

	left_size = mid - start;
	right_size = end - mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, left_size);
	printf("[right]: ");
	print_array(array + mid, right_size);

	i = 0;
	j = 0;
	k = start;

	while (i < left_size && j < right_size)
	{
		if (array[start + i] <= array[mid + j])
			buffer[k++] = array[start + i++];
		else
			buffer[k++] = array[mid + j++];
	}
	while (i < left_size)
		buffer[k++] = array[start + i++];
	while (j < right_size)
		buffer[k++] = array[mid + j++];

	for (i = start; i < end; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + start, left_size + right_size);
}

/**
 * merge_sort_recursive - recursively splits and sorts array segments
 * @array: pointer to the array to sort
 * @start: starting index of the segment
 * @end: index one past the end of the segment
 * @buffer: auxiliary buffer for merging
 */
static void merge_sort_recursive(int *array, size_t start,
	size_t end, int *buffer)
{
	if (end - start < 2)
		return;

	merge_sort_recursive(array, start,
		start + (end - start) / 2, buffer);
	merge_sort_recursive(array,
		start + (end - start) / 2, end, buffer);
	merge_subarray(array, start,
		start + (end - start) / 2, end, buffer);
}


/**
 * merge_sort - sorts an array of integers in ascending order
 *               using the Merge Sort algorithm
 * @array: pointer to the first element of the array to sort
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(size * sizeof(int));
	if (!buffer)
		return;

	merge_sort_recursive(array, 0, size, buffer);
	free(buffer);
}
