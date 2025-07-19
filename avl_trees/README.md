# AVL Trees

A C programming project focused on implementing and validating AVL (Adelson-Velsky and Landis) trees - self-balancing binary search trees.

## Description

This project implements functions to work with AVL trees, which are binary search trees that automatically maintain balance by ensuring the height difference between left and right subtrees never exceeds 1.

## Requirements

- **Environment**: Ubuntu 14.04 LTS
- **Compiler**: gcc 4.8.4 with flags: `-Wall -Werror -Wextra -pedantic`
- **Code Style**: Betty style (checked with `betty-style.pl` and `betty-doc.pl`)
- **Files**: All files must end with a newline
- **Functions**: Maximum 5 functions per file
- **Global Variables**: Not allowed

## Data Structures

### Binary Tree Node
```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
```

## Tasks

### 0. Is AVL
**File**: `0-binary_tree_is_avl.c`

**Prototype**: `int binary_tree_is_avl(const binary_tree_t *tree);`

**Description**: Function that checks if a binary tree is a valid AVL tree.

**Return Values**:
- `1` if the tree is a valid AVL tree
- `0` if the tree is not a valid AVL tree or is NULL

**AVL Tree Properties**:
- Must be a Binary Search Tree (BST)
- Height difference between left and right subtrees ≤ 1
- Both left and right subtrees must also be valid BSTs

## Files

- `binary_trees.h` - Header file containing all function prototypes and data structures
- `0-binary_tree_is_avl.c` - Implementation of AVL validation function

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
```
