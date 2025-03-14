#!/usr/bin/python3
"""
This module contains a function to check if a sequence of
integers corresponds to a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Checks whether the provided list of integers is a
    valid UTF-8 encoding sequence.

    Args:
        data (list): A list of integers,
        each representing a single byte.

    Returns:
        bool: True if the list represents a valid UTF-8 encoding,
        False otherwise.
    """

    # Define masks to isolate the first and second most significant
    # bits of a byte.

    # Binary representation of the most significant bit (MSB) mask.
    MASK1 = 0b10000000
    # Binary representation of the second MSB mask.
    MASK2 = 0b01000000

    # Variable to track the number of bytes required by
    # the current UTF-8 character.
    remaining = 0

    for num in data:
        # Mask to only consider the least significant 8 bits of each number.
        num &= 0xFF

        if remaining == 0:
            # Determine how many bytes the current UTF-8 character requires.
            if (num & MASK1) == 0:  # Single-byte character (0xxxxxxx)
                continue
            # Check for multi-byte character headers and set the expected
            # continuation byte count.

            # Invalid format for a start byte
            elif (num & MASK1) and (num & MASK2) == 0:
                return False
            # Two-byte character (110xxxxx)
            elif (num & MASK1) and (num & (MASK1 >> 2)) == 0:
                remaining = 1
            # Three-byte character (1110xxxx)
            elif (num & MASK1) and (num & (MASK1 >> 3)) == 0:
                remaining = 2
            # Four-byte character (11110xxx)
            elif (num & MASK1) and (num & (MASK1 >> 4)) == 0:
                remaining = 3
            else:  # More than four leading ones are not allowed in UTF-8
                return False
        else:
            # Verify that the current byte is a valid continuation
            # byte (10xxxxxx).
            if not (num & MASK1 and not (num & MASK2)):
                return False
            remaining -= 1

    # After processing all data, no bytes should remain to complete
    # a valid UTF-8 character.
    return remaining == 0


# Test cases for the validUTF8 function
if __name__ == "__main__":
    data1 = [65]
    print(validUTF8(data1))  # Expected output: True

    data2 = [
        80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33
    ]
    print(validUTF8(data2))  # Expected output: True

    data3 = [229, 65, 127, 256]
    print(validUTF8(data3))  # Expected output: False
