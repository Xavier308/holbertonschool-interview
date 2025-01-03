#!/usr/bin/python3

def canUnlockAll(boxes):
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
