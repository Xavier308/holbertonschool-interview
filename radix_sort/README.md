# Radix Sort

Implementation of the Radix Sort algorithm in C using the LSD (Least Significant Digit) approach.

## Task

Implement `radix_sort()` function that sorts an array of integers in ascending order.

## Requirements

- Compile with `gcc -Wall -Werror -Wextra -pedantic`
- Follow Betty coding style
- No global variables allowed
- Use only `malloc`, `free`, and provided `print_array` function
- Print array after each significant digit pass

## Files

- `0-radix_sort.c` - Main implementation
- `sort.h` - Header file with function prototypes
- `print_array.c` - Utility function (provided)

## Usage

```c
void radix_sort(int *array, size_t size);
```
