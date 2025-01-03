#!/usr/bin/python3
"""Module for determining if all boxes can be unlocked.

This module provides a function `canUnlockAll` that checks if all
nested boxes can be unlocked using the keys contained within them.
"""


def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked.

    Starting from the first box, which is initially unlocked,
    this function uses a breadth-first search (BFS) approach
    to try to unlock all subsequent boxes using the keys found
    in each box.

    Args:
        boxes (list of lists of int): The list of boxes with each box
        containing a list of key indices.

    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    if not boxes:
        return False

    unlocked = [False] * len(boxes)
    unlocked[0] = True
    queue = [0]

    while queue:
        box_index = queue.pop(0)

        for key in boxes[box_index]:
            if key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                queue.append(key)

    return all(unlocked)
