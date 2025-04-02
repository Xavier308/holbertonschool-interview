# Linked List Palindrome

## Overview
This project implements a function in C to determine whether a singly linked list is a palindrome - a sequence that reads the same forward and backward.

## Problem Statement
Write a function that checks if a singly linked list is a palindrome.
- Prototype: `int is_palindrome(listint_t **head);`
- Return: `0` if it is not a palindrome, `1` if it is a palindrome
- An empty list is considered a palindrome

## Approach & Algorithm Insights

### Efficient Solution
The optimal solution uses a three-step approach:
1. Find the middle of the linked list using slow/fast pointer technique
2. Reverse the second half of the linked list
3. Compare the first half with the reversed second half

### Time & Space Complexity
- **Time complexity**: O(n) - we traverse the list only a constant number of times
- **Space complexity**: O(1) - no extra space proportional to input size is used

### Alternative Approaches
1. **Stack method**: Push all elements onto a stack, then compare with original list (O(n) time, O(n) space)
2. **Recursive approach**: Use recursion to reach the end of the list while comparing (O(n) time, O(n) space due to call stack)

## Implementation Details
- The `is_palindrome` function handles edge cases (NULL or single element lists)
- No global variables are used
- Betty coding style is followed

## Example
```
List: 1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1
Result: Linked list is a palindrome
```

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```
