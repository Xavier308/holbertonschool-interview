# Infinite Multiplication

Program that multiplies two big numbers.

## Requirements

- Use `gcc -Wall -Werror -Wextra -pedantic`
- Only allowed functions: `malloc`, `free`, `exit`, `_putchar`
- No global variables
- Betty style code

## Usage

```bash
gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
./mul num1 num2
```

## Examples

```bash
$ ./mul 10 98
980

$ ./mul 123
Error

$ ./mul 123 abc
Error
```

## What it does

- Multiplies two positive numbers of any size
- Prints result or "Error" if wrong input
- Exit with status 98 on error

## Files

- `0-mul.c` - main program
- `holberton.h` - header file
