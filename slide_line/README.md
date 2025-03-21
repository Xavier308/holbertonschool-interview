# Slide Line

## Overview
This project implements a key mechanic from the [2048 game](https://play2048.co/) on a single horizontal line. The goal is to develop a C function that slides and merges an array of integers either to the left or to the right, following the 2048 game rules.

## How it Works
In the 2048 game, players slide tiles on a grid to combine numbers. In this simplified version:

1. Numbers slide to the specified direction (left or right)
2. Identical numbers that are adjacent or separated by zeros will merge into a single number equal to their sum
3. Each number can only be merged once per slide operation

## Function Prototype
```c
int slide_line(int *line, size_t size, int direction);
```

### Parameters
- `line`: Pointer to an array of integers
- `size`: Number of elements in the array
- `direction`: Direction to slide (defined by macros `SLIDE_LEFT` or `SLIDE_RIGHT`)

### Return Value
- Returns `1` upon success
- Returns `0` upon failure (e.g., invalid direction)

## Algorithm
The algorithm works in three steps:

1. **Compact**: Move all non-zero numbers to the target side (left or right)
2. **Merge**: Combine adjacent identical numbers in the specified direction
3. **Compact again**: Move all numbers once more to eliminate any gaps created by merging

## Examples

### Slide Left
```
Input: [2, 2, 0, 0]
Output: [4, 0, 0, 0]
```

```
Input: [2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4]
Output: [4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```

### Slide Right
```
Input: [2, 2, 2, 2]
Output: [0, 0, 4, 4]
```

```
Input: [2, 2, 2, 2, 2]
Output: [0, 0, 2, 4, 4]
```

## No Change Cases
When no merging is possible, the array remains unchanged:
```
Input: [2, 4, 8, 16]
Output: [2, 4, 8, 16] (for both left and right slides)
```

## Implementation Details

The implementation separates the algorithm into smaller functions for better code organization:

1. `compact_left/compact_right`: Move all non-zero values to one side
2. `merge_left/merge_right`: Merge adjacent identical numbers
3. `slide_left/slide_right`: Perform the full slide operation
4. `slide_line`: Main function that chooses the appropriate slide direction

## Compilation and Running
This function can be compiled and tested with the provided main.c file:

```
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
```

The program can be run with arguments specifying the direction and array values:
```
./0-slide_line L 2 2 0 0
```

Where:
- L: Slide left (R for slide right)
- 2 2 0 0: Array values to process