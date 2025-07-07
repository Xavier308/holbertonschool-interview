#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Compute the total perimeter of the island defined by `grid`.

    Args:
        grid (list of list of int): A 2D map where
            - 0 = water
            - 1 = land

    Returns:
        int: The calculated perimeter length.

    Notes:
        * Only horizontal and vertical neighbors count.
        * The map is surrounded by water and contains at most one island.
        * There are no enclosed 'lakes' within the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # land cell detected
                perimeter += 4  # start with four sides
                # subtract shared edge with the cell above, if also land
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                # subtract shared edge with the cell below, if also land
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                # subtract shared edge with the cell to the left, if also land
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                # subtract shared edge with the cell to the right, if also land
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
