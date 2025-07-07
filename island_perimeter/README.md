# Island Perimeter

A Python project that calculates the perimeter of an island represented in a 2D grid.

## Description

This project implements a function to calculate the perimeter of an island described in a grid where:
- `0` represents water
- `1` represents land
- Each cell is a square with side length of 1
- Cells are connected horizontally/vertically (not diagonally)

## Requirements

- **Python Version**: Python 3.4.3
- **Operating System**: Ubuntu 14.04 LTS
- **Code Style**: PEP 8 (version 1.7)
- **Editors**: `vi`, `vim`, `emacs`
- No external modules allowed
- All functions must be documented
- All files must be executable
- Files must start with `#!/usr/bin/python3`
- Files must end with a new line

## Task

### 0. Island Perimeter

Create a function `island_perimeter(grid)` that returns the perimeter of the island described in the grid.

**Function Specifications:**
- `grid` is a list of lists of integers
- Grid is rectangular (width and height ≤ 100)
- Grid is completely surrounded by water
- Contains only one island (or nothing)
- Island has no "lakes" (internal water not connected to surrounding water)

## Usage

```python
#!/usr/bin/python3
island_perimeter = __import__('0-island_perimeter').island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]

print(island_perimeter(grid))  # Output: 12
```
