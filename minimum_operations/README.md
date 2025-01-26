# Minimum Operations

## Description
This project implements a solution to calculate the minimum number of operations needed to achieve a specific number of 'H' characters in a text file, given that only two operations are available: 'Copy All' and 'Paste'.

## Project Information
- **Author**: Carrie Ybay
- **Role**: Software Engineer at Holberton School
- **Weight**: 1

## Requirements

### Environment
- Ubuntu 14.04 LTS
- Python 3.4.3

### General Requirements
- Allowed editors: vi, vim, emacs
- All files must end with a newline
- First line of all files must be exactly `#!/usr/bin/python3`
- A README.md file at the root of the project folder is mandatory
- Code must be documented
- Code must follow PEP 8 style guidelines (version 1.7.x)
- All files must be executable

## Task: Minimum Operations

### Problem Statement
Given a text file containing a single character 'H' and only two available operations (Copy All and Paste), write a method that calculates the minimum number of operations needed to achieve exactly n 'H' characters in the file.

### Function Prototype
```python
def minOperations(n)
```

### Parameters
- `n`: The desired number of 'H' characters

### Return Value
- Returns an integer representing the minimum number of operations
- Returns 0 if n is impossible to achieve

### Example
```python
n = 9
# Steps:
# H → Copy All → Paste → HH → Paste → HHH → Copy All → Paste → HHHHHH → Paste → HHHHHHHHH
# Number of operations: 6

n = 4
# Result: 4 operations

n = 12
# Result: 7 operations
```

### Usage
```python
#!/usr/bin/python3
minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
```
