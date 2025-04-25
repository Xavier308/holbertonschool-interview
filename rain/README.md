# Rainwater Trapping Algorithm

## Description

This project implements an algorithm to calculate how much rainwater would be trapped between walls of varying heights. Given an array of non-negative integers representing wall heights, the algorithm determines the total amount of water that would be retained after rainfall.

## Problem Statement

- A list of non-negative integers represents the heights of walls with unit width 1
- Calculate how many square units of water will be retained after it rains
- The ends of the list are not walls and won't retain water
- If the list is empty, return 0

## Algorithm Approach

The solution uses the two-pointer technique to efficiently calculate trapped water:
1. Initialize pointers at the left and right ends of the wall array
2. Track maximum heights seen from both directions
3. Move pointers inward, calculating trapped water at each position
4. Return the total accumulated water

## Usage

```python
#!/usr/bin/python3
from "0-rain" import rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Output: 6
```

## Time & Space Complexity

- **Time Complexity**: O(n) where n is the length of the walls array
- **Space Complexity**: O(1) as we only use constant extra space

