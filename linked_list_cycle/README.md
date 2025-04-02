# Linked List Cycle

## Overview
This project implements a function in C to detect if a singly linked list contains a cycle - a condition where a node's next pointer points back to a previous node, creating an infinite loop.

## Problem Statement
Write a function that checks if a singly linked list has a cycle in it.
- Prototype: `int check_cycle(listint_t *list);`
- Return: `0` if there is no cycle, `1` if there is a cycle

## Algorithm Insights

### Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
The optimal solution uses two pointers moving at different speeds:
1. Slow pointer (tortoise) moves one step at a time
2. Fast pointer (hare) moves two steps at a time
3. If there is a cycle, the fast pointer will eventually meet the slow pointer
4. If there is no cycle, the fast pointer will reach the end of the list

### Time & Space Complexity
- **Time complexity**: O(n) where n is the number of nodes
- **Space complexity**: O(1) - only two pointers are used regardless of input size

### Why It Works
- In a cycle, a fast pointer moving twice as fast as a slow pointer will eventually catch up
- The distance between them decreases by 1 in each iteration

## Implementation Notes
- The function handles edge cases (NULL list)
- No additional memory allocation required
- Only allowed functions: write, printf, putchar, puts, malloc, free
- Solution must be efficient in both time and space complexity

## Example
```
List: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
Result: Linked list has no cycle

List with cycle: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -┐
                                         ^                    |
                                         └--------------------┘
Result: Linked list has a cycle
```

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```
