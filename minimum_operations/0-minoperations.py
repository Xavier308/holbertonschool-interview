#!/usr/bin/python3
"""
This module defines a function to compute the minimum number of operations 
required to produce exactly `n` 'H' characters in a text file, starting with a single 'H'.

Allowed operations:
1. Copy All: Copies the entire content currently in the file.
2. Paste: Appends the previously copied content to the file.

The `minOperations` function calculates the minimum number of operations 
needed using an approach based on prime factorization.

Functions:
    minOperations(n): Returns the minimum number of operations needed.
"""


def minOperations(n):
    """
    Computes the minimum operations required to get exactly n 'H' characters.

    Parameters:
        n (int): The target number of 'H' characters.

    Returns:
        int: The total minimum number of operations needed, 
        or 0 if it is not possible to achieve n.
    """
    if n <= 1:
        return 0  # Impossible to achieve if n <= 1

    operations = 0
    divisor = 2  # Start checking divisors from 2

    while n > 1:
        while n % divisor == 0:  # While divisible, reduce n
            operations += divisor
            n //= divisor
        divisor += 1  # Check next potential divisor

    return operations
