# Substring with Concatenated Words

Find all starting indices in a string where a concatenation of all given words appears exactly once and without intervening characters.

## Prototype

```c
int *find_substring(const char *s, const char **words,
                    int nb_words, int *n);
```

* **s**: String to search.
* **words**: Array of words (same length).
* **nb\_words**: Number of words.
* **n**: Output count of found indices.
* **Return**: Dynamically allocated array of indices or `NULL`.

## Compile & Run

```bash
gcc -Wall -Wextra -Werror -pedantic main.c substring.c
./a.out barfoothefoobarman foo bar
# Output: Indices -> [0, 9]
```

## Example

```bash
./a.out wordgoodgoodgoodbestword word good best good
# Output: Indices -> [8]
```
