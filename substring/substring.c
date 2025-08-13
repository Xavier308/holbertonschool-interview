#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_word_match - Check if extracted word matches any in words array
 * @word: The word to check
 * @words: Array of words
 * @nb_words: Number of words
 * @word_counts: Array to store word counts
 *
 * Return: 1 if word found and counted, 0 otherwise
 */
static int check_word_match(char *word, char const **words,
			    int nb_words, int *word_counts)
{
	int j;

	for (j = 0; j < nb_words; j++)
	{
		if (strcmp(word, words[j]) == 0)
		{
			word_counts[j]++;
			return (1);
		}
	}
	return (0);
}

/**
 * validate_word_counts - Check if each word appears exactly once
 * @word_counts: Array of word counts
 * @nb_words: Number of words
 *
 * Return: 1 if all counts are 1, 0 otherwise
 */
static int validate_word_counts(int *word_counts, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (word_counts[i] != 1)
			return (0);
	}
	return (1);
}

/**
 * check_concatenation - Check if substring is valid concatenation
 * @s: The string to check
 * @pos: Starting position
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 * @word_counts: Array to store counts
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_concatenation(char const *s, int pos, char const **words,
			       int nb_words, int word_len, int *word_counts)
{
	int i, len = strlen(s);
	char *current_word;

	for (i = 0; i < nb_words; i++)
		word_counts[i] = 0;

	if (pos + nb_words * word_len > len)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		current_word = malloc(word_len + 1);
		if (!current_word)
			return (0);

		strncpy(current_word, s + pos + i * word_len, word_len);
		current_word[word_len] = '\0';

		if (!check_word_match(current_word, words, nb_words, word_counts))
		{
			free(current_word);
			return (0);
		}
		free(current_word);
	}
	return (validate_word_counts(word_counts, nb_words));
}

/**
 * add_result - Add index to result array, expanding if needed
 * @result: Pointer to result array
 * @capacity: Pointer to capacity
 * @size: Current size
 * @index: Index to add
 *
 * Return: Updated result array, or NULL on failure
 */
static int *add_result(int **result, int *capacity, int size, int index)
{
	if (size >= *capacity)
	{
		*capacity *= 2;
		*result = realloc(*result, *capacity * sizeof(int));
		if (!*result)
			return (NULL);
	}
	(*result)[size] = index;
	return (*result);
}

/**
 * allocate_arrays - Allocate memory for word counts and result arrays
 * @nb_words: Number of words
 * @word_counts: Pointer to word counts array
 * @result: Pointer to result array
 * @capacity: Initial capacity for result array
 *
 * Return: 1 on success, 0 on failure
 */
static int allocate_arrays(int nb_words, int **word_counts,
			   int **result, int capacity)
{
	*word_counts = malloc(nb_words * sizeof(int));
	*result = malloc(capacity * sizeof(int));
	if (!*word_counts || !*result)
	{
		free(*word_counts);
		free(*result);
		return (0);
	}
	return (1);
}

/**
 * find_substring - Find all substrings that are concatenations of given words
 * @s: The string to scan
 * @words: Array of words to concatenate
 * @nb_words: Number of words in the array
 * @n: Pointer to store the number of results
 *
 * Return: Array of indices where valid substrings start, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result = NULL, *word_counts;
	int i, len, word_len, result_size = 0, result_capacity = 10;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	len = strlen(s);
	word_len = strlen(words[0]);
	if (len < nb_words * word_len)
		return (NULL);

	if (!allocate_arrays(nb_words, &word_counts, &result, result_capacity))
		return (NULL);

	for (i = 0; i <= len - nb_words * word_len; i++)
	{
		if (check_concatenation(s, i, words, nb_words, word_len, word_counts))
		{
			if (!add_result(&result, &result_capacity, result_size, i))
			{
				free(word_counts);
				return (NULL);
			}
			result_size++;
		}
	}

	free(word_counts);
	if (result_size == 0)
	{
		free(result);
		return (NULL);
	}
	*n = result_size;
	return (result);
}
