# Heap Insert

## Overview
Implementation of a Max Binary Heap with insertion functionality in C. This project covers creating binary tree nodes and inserting values while maintaining the Max Heap property.

## Key Concepts

### Max Binary Heap
- Complete binary tree where each node is greater than or equal to its children
- Root node always contains the maximum value
- Used for efficient priority queues and heap sort

### Binary Tree Structure
```c
struct binary_tree_s
{
    int n;                      // Value stored in node
    struct binary_tree_s *parent; // Parent node
    struct binary_tree_s *left;   // Left child
    struct binary_tree_s *right;  // Right child
};
typedef struct binary_tree_s heap_t;
```

## Implementation Details

### Task 0: Creating Binary Tree Nodes
- Function: `binary_tree_node(binary_tree_t *parent, int value)`
- Creates a new node with specified parent and value
- Node starts with no children

### Task 1: Heap Insertion
- Function: `heap_insert(heap_t **root, int value)`
- Inserts a value into the proper position in the Max Heap
- Steps:
  1. Add node at the next available position (following level-order)
  2. "Bubble up" - Compare with parent and swap if greater
  3. Continue swapping until heap property restored
- Time complexity: O(log n) where n is number of nodes

## Algorithm Insights
- Insertion follows **level-order traversal** to maintain the complete tree property
- Finding the insertion point requires tracking the number of nodes
- The "sift-up" (bubble up) operation is crucial for maintaining the heap property
- Parent-child relationships: parent(i) = floor((i-1)/2), left_child(i) = 2i+1, right_child(i) = 2i+2

## Compilation
```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c main.c heap_insert.c binary_tree_node.c -o heap_insert
```

