#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - Find all starting indices where a concatenation of
 *                  all words appears exactly once with no gaps.
 * @s: Input string to scan.
 * @words: Array of words (all same length).
 * @nb_words: Number of words.
 * @n: Output: number of indices returned.
 *
 * Return: Malloc'd array of indices or NULL. On NULL, *n is set to 0.
 */
int *find_substring(const char *s, const char **words,
	int nb_words, int *n);

#endif /* SUBSTRING_H */
