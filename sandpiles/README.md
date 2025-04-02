# Sandpiles

## Overview
This project implements the Abelian sandpile model, a mathematical model that demonstrates self-organized criticality. It focuses on computing the sum of two sandpiles while maintaining stability according to specific toppling rules.

## The Sandpile Model
The Abelian sandpile model works on a grid where each cell contains a number of "sand grains":
- A cell is stable if it contains 3 or fewer grains
- A cell topples when it has more than 3 grains
- During toppling, 4 grains are removed from the cell and 1 grain is added to each of its 4 adjacent neighbors

## Algorithm Insights

### Toppling Process
1. Add the two input grids cell by cell
2. Check if the resulting grid is stable (no cell > 3)
3. If unstable:
   - Print the current grid
   - Create a temporary grid to track which cells will topple
   - For each cell with > 3 grains, distribute grains to neighbors
   - Repeat until stability is achieved

### Key Challenges
- **Concurrent Toppling**: Toppling must occur simultaneously across all unstable cells in each round
- **Border Conditions**: Grains that would fall off the edge of the grid are lost
- **Convergence**: Need to ensure the process eventually stabilizes

### Time & Space Complexity
- **Time complexity**: O(n * m) where n is the number of cells and m is the number of toppling rounds required
- **Space complexity**: O(1) since we're working with fixed-size 3x3 grids

## Implementation Notes
- Fixed 3x3 grid implementation
- No dynamic memory allocation allowed
- Grid must be printed before each toppling round if unstable

## Example
```
Initial grids:
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1

After addition:
4 6 4
6 6 6
4 6 4

After first toppling:
2 5 2
5 6 5
2 5 2

... (more toppling rounds)

Final stable grid:
2 2 2
2 2 2
2 2 2
```

## Resources
- [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg) - Video explanation of the concept
