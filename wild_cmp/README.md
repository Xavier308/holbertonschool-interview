# Wild Compare

A C programming project that implements wildcard string comparison functionality using recursion.

## Description

This project contains a function that compares two strings and determines if they can be considered identical, with support for wildcard matching using the `*` character. The `*` character can replace any string (including an empty string).

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

**Parameters:**
- `s1`: First string to compare
- `s2`: Second string to compare (may contain wildcard `*`)

**Returns:**
- `1` if strings can be considered identical
- `0` if strings are different

## Usage Example

```c
#include "holberton.h"
#include <stdio.h>

int main(void)
{
    int result;
    
    result = wildcmp("main.c", "*.c");
    printf("%d\n", result); // Output: 1
    
    result = wildcmp("main.c", "m*c");
    printf("%d\n", result); // Output: 1
    
    result = wildcmp("main.c", "m.*c");
    printf("%d\n", result); // Output: 0
    
    return (0);
}
```

