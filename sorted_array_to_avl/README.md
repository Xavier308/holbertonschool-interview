# Sorted Array to AVL Tree

A C program that converts a sorted array into a balanced AVL tree without using rotations.

## Description

This project implements a function that builds an AVL (Adelson-Velsky and Landis) tree from a sorted array of integers. The implementation uses a recursive approach with a divide-and-conquer strategy to ensure the tree is balanced.

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4 with flags: -Wall -Werror -Wextra -pedantic
- Betty coding style

## Files

- `0-sorted_array_to_avl.c`: Main implementation of the array to AVL tree conversion
- `binary_trees.h`: Header file with necessary structures and function prototypes

## Data Structures

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
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

## Function Prototype

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

## Approach

The implementation uses a binary search approach to:
1. Find the middle element of the array to use as the root node
2. Recursively build the left subtree from elements before the middle
3. Recursively build the right subtree from elements after the middle

This naturally creates a balanced tree without needing rotations.

## Usage

```
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
$ ./0-sorted_array_to_avl
```
