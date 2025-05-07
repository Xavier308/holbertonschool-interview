# Advanced Binary Search

This project implements an **advanced binary search** algorithm that always returns the **first** occurrence of a given value in a sorted array of integers.  

Unlike the standard binary search, this version handles duplicate values by recursively exploring the left subarray until the earliest index is found.

## Requirements

- **Editors:** vi, vim, emacs  
- **OS:** Ubuntu 14.04 LTS  
- **Compiler:** gcc 4.8.4 with flags `-Wall -Werror -Wextra -pedantic`  
- **Style:** Betty (checked with `betty-style.pl` and `betty-doc.pl`)  
- **No global variables**  
- **Max 5 functions per file**  
- **Allowed library calls:** only `printf`  

## Files

- `search_algos.h` — Header file with function prototype.  
- `0-advanced_binary.c` — Implementation of the advanced binary search.  

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-advanced_binary.c main.c -o advanced_binary
```
