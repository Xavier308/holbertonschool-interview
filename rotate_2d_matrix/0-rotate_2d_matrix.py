#!/usr/bin/python3
"""
Rotate a 2D matrix 90 degrees clockwise in place.
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of list of int): 2D matrix to rotate
    """
    n = len(matrix)
    # First, transpose the matrix (swap rows with columns)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Then, reverse each row
    for row in matrix:
        row.reverse()
