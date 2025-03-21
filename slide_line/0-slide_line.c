#include "slide_line.h"

/**
 * reverse_array - Reverses an array of integers in place.
 * @arr: The array to reverse.
 * @size: The number of elements in the array.
 */
static void reverse_array(int *arr, size_t size)
{
	size_t i;
	int tmp;

	for (i = 0; i < size / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}

/**
 * slide_left - Slides and merges the line to the left.
 * @line: Array of integers.
 * @size: Number of elements in the array.
 *
 * This function compresses the non-zero elements, then merges
 * adjacent equal numbers (merging each pair only once) and finally
 * fills the rest of the array with zeros.
 */
static void slide_left(int *line, size_t size)
{
	int temp[size];
	int merged[size];
	size_t i, j, pos = 0;

	/* Compress non-zero elements into a temporary array */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			temp[pos] = line[i];
			pos++;
		}
	}

	/* Merge adjacent numbers */
	for (i = 0, j = 0; i < pos; i++, j++)
	{
		if (i < pos - 1 && temp[i] == temp[i + 1])
		{
			merged[j] = temp[i] * 2;
			i++;  /* Skip the next element since it has been merged */
		}
		else
		{
			merged[j] = temp[i];
		}
	}

	/* Fill the rest of the merged array with zeros */
	for (; j < size; j++)
	{
		merged[j] = 0;
	}

	/* Copy the merged array back to the original line */
	for (i = 0; i < size; i++)
	{
		line[i] = merged[i];
	}
}

/**
 * slide_line - Slides and merges an array of integers in a given direction.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, or 0 on failure (if an invalid direction is provided).
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		/* Reverse the array, slide left, then reverse back to simulate */
		/* right sliding */
		reverse_array(line, size);
		slide_left(line, size);
		reverse_array(line, size);
	}
	return (1);
}
