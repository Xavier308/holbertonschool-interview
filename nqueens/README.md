# N Queens Problem

## Overview

This project implements a solution to the classic N Queens puzzle using a backtracking algorithm. The challenge is to place N chess queens on an N×N chessboard so that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.

## Algorithm Explanation

The solution uses a backtracking approach, which is a form of recursive depth-first search:

1. **Representation**: The board is represented using a one-dimensional array where:
   - The index represents the row
   - The value at that index represents the column where a queen is placed

2. **Safety Check**: Before placing a queen, we verify if the position is safe by checking:
   - No queen exists in the same column
   - No queen exists in the same diagonal (both rising and falling diagonals)

3. **Backtracking Process**:
   - Start with an empty board
   - Place queens row by row, beginning at row 0
   - For each row, try placing a queen in each column
   - When a safe position is found, place the queen and move to the next row
   - If no safe position is found in a row, backtrack to the previous row and try a different position
   - When all N queens are placed (we reach row N), record the solution

4. **Output Format**:
   - Each solution is printed as a list of coordinates `[row, column]`
   - Each coordinate represents the position of a queen on the board

## Usage

```bash
./0-nqueens.py N
```

Where `N` is an integer greater than or equal to 4.

## Requirements

- Python 3.4.3 or later
- The only allowed import is the `sys` module

## Examples

For N = 4:
```
./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

For N = 6:
```
./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

## Time Complexity

The time complexity is O(N!), as in the worst case, the algorithm might need to explore all possible arrangements of N queens on an N×N board.

