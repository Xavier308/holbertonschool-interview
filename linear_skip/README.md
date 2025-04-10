# Linear Skip List Search

## Description
This project implements a linear search algorithm within a skip list data structure. A skip list is an enhanced linked list with an "express lane" that allows for faster traversal, improving search time complexity from O(n) to O(√n).

## Implementation Details
The `linear_skip` function searches for a specific value in a sorted skip list by:
1. Traversing the express lane until finding a node with a value greater than or equal to the target
2. Identifying the range where the value may be located
3. Performing a standard linear search within that range

## Requirements
- Compiled on Ubuntu 14.04 LTS with gcc 4.8.4
- Uses the flags -Wall -Werror -Wextra and -pedantic
- Follows Betty coding style
- No global variables allowed
- Maximum 5 functions per file

## Function Prototype
```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

## Example Usage
```c
res = linear_skip(list, 53);
printf("Found %d at index: %lu\n", 53, res->index);
```

## Data Structure
```c
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
```

## Files
- `0-linear_skip.c`: Implementation of the linear_skip function
- `search.h`: Header file with function prototypes and data structure definition