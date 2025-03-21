# Menger Sponge

## Overview
This project implements a 2D version of the Menger Sponge, a fractal cube first described by Austrian mathematician Karl Menger in 1926. The goal is to develop a C function that draws a 2D Menger Sponge of a given level.

## What is a Menger Sponge?
A Menger Sponge is a 3D fractal that's constructed by dividing a cube into 27 smaller cubes (a 3×3×3 grid), and then removing the central cube and the six cubes that share a face with it, leaving 20 cubes. This process is then repeated recursively for each of the remaining smaller cubes.

In this project, we'll implement a simplified 2D version of this concept.

## 2D Menger Sponge Rules
The 2D version follows similar principles:

1. A level N sponge is a 3×3 square of level N-1 sponges, except for the center one, which is left empty
2. A level 0 sponge is represented by a single '#' character
3. The size of a level N Menger sponge is calculated as 3^N

## Function Prototype
```c
void menger(int level);
```

### Parameters
- `level`: The level of the Menger Sponge to draw
  - If level is lower than 0, the function does nothing

## Visual Examples

### Level 0
```
#
```
A single '#' character representing a 1×1 square.

### Level 1
```
###
# #
###
```
A 3×3 square where the center is empty.

### Level 2
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```
A 9×9 grid made of 8 level-1 sponges arranged in a square, with the center left empty.

## Approach
The algorithm uses recursion and mathematical properties of the Menger Sponge to determine which positions should be filled with '#' characters:

1. Calculate the total size of the sponge (3^level)
2. For each position (row, col), determine if it should be filled or empty
3. A position is empty if, at any level of subdivision, it would be in the center of a 3×3 grid

## Compilation and Running
This function can be compiled and tested with the provided main.c file:

```
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

The program can be run with an argument specifying the level:
```
./0-menger 2
```

## Mathematical Note
The pattern follows the principle that a cell at position (row, col) is empty if and only if there exists some power of 3 such that both:
- (row / 3^i) % 3 == 1
- (col / 3^i) % 3 == 1

This mathematical property is what creates the recursive "holes" in the structure.
