# UTF-8 Validation

This project implements a method to determine if a given data set represents a valid UTF-8 encoding.

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style (version 1.7.x)

## Task

Implement a function that validates if a data set is a valid UTF-8 encoding:

```python
def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    
    Args:
        data: List of integers where each integer represents 1 byte of data
        
    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
```

### Notes

- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- Only handle the 8 least significant bits of each integer

## Usage

```python
validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```
