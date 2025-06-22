#!/usr/bin/python3
"""
Module containing the makeChange function.
"""


def makeChange(coins, total):
    """
    Calculates the minimum number of coins required to reach a given total.

    Args:
        coins (list): Available coin denominations.
        total (int): Desired total amount.

    Returns:
        int: Fewest coins needed to reach total, or -1 if it's not achievable.
    """
    if total <= 0:
        return 0

    # Create a list to store the minimal coins needed for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Zero coins are required to make amount 0

    for coin in coins:
        for x in range(coin, total + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
