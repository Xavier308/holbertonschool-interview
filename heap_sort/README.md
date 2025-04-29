# Heap Sort

## Description
This project implements the Heap Sort algorithm to sort an array of integers in ascending order. The implementation specifically uses the sift-down approach for heap sort.

## Requirements
- All files are compiled on Ubuntu 14.04 LTS
- Compiled with gcc 4.8.4 using flags: -Wall -Werror -Wextra -pedantic
- Code follows Betty style guidelines
- No use of global variables
- Maximum 5 functions per file
- Standard library functions like printf and puts are forbidden (except those provided)

## Files
- `0-heap_sort.c`: Contains the implementation of the heap sort algorithm
- `0-O`: Contains the big O notations for the time complexity in best, average, and worst cases
- `sort.h`: Header file containing all function prototypes

## Function Prototype
```c
void heap_sort(int *array, size_t size);
```

## Compilation
```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

## Algorithm
The implementation uses the sift-down heap sort algorithm, which:
1. Builds a max heap from the input array
2. Repeatedly extracts the maximum element from the heap and rebuilds the heap
3. Prints the array after each swap of elements

## Time Complexity
- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))