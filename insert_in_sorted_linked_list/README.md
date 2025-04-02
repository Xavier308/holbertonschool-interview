# Insert in Sorted Linked List

## Overview
This project implements a function in C that inserts a number into a sorted singly linked list while maintaining the sorted order.

## Problem Statement
Write a function that inserts a number into a sorted singly linked list.
- Prototype: `listint_t *insert_node(listint_t **head, int number);`
- Return: the address of the new node, or NULL if it failed

## Algorithm Insights

### Approach
The solution requires traversing the linked list to find the correct position for insertion:
1. Create a new node with the given number
2. Handle edge cases:
   - Empty list (insert as first node)
   - Value smaller than head (insert before head)
3. Traverse the list to find insertion position
4. Insert the new node between two existing nodes

### Time & Space Complexity
- **Time complexity**: O(n) in worst case - may need to traverse entire list
- **Space complexity**: O(1) - only creating one new node

### Edge Cases to Consider
- Empty list: Need to set the new node as the head
- Insert at beginning: Number is smaller than the first node
- Insert at end: Number is larger than all existing nodes
- Insert in middle: Find correct position to maintain sorted order

## Implementation Notes
- Function should allocate memory for the new node
- Check for memory allocation failure
- Properly update pointers to maintain list integrity
- Must follow Betty coding style

## Example
```
Original list: 0 -> 1 -> 2 -> 3 -> 4 -> 98 -> 402 -> 1024
Insert 27
Result: 0 -> 1 -> 2 -> 3 -> 4 -> 27 -> 98 -> 402 -> 1024
```

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
```

