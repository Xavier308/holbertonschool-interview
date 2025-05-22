# Heap Extract

A C implementation of a function that extracts the root node from a Max Binary Heap.

## Function

- `heap_extract()` - Extracts and returns the root value, replaces it with the last level-order node, and rebuilds the heap

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with flags: `-Wall -Werror -Wextra -pedantic`
- Betty coding style
- Max 5 functions per file


## Files

* **0-heap\_extract.c**: `heap_extract` implementation
* **binary\_tree\_print.c**: utility to visualize the heap
* **libheap.a**: provided test library (do not modify)
* **0-main.c**: example test harness (not graded)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic \
  0-main.c 0-heap_extract.c binary_tree_print.c libheap.a \
  -o heap_extract
```

## Usage

```bash
./heap_extract
```

## Function Signature

```c
int heap_extract(heap_t **root);
```

* **Description**: Removes the root node, replaces it with the last node, restores heap order, and returns the original max value.

```c
int heap_extract(heap_t **root);
```

Returns the extracted root value or 0 on failure.
