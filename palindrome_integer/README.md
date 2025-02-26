# Palindrome Integer

## Description
This project implements a function that checks whether an unsigned integer is a palindrome. A palindrome reads the same backward as forward (e.g., 121, 12321).

## Requirements
- Ubuntu 14.04 LTS
- GCC 4.8.4 with flags: -Wall -Werror -Wextra -pedantic
- Betty style compliance

## Files
- `0-is_palindrome.c`: Contains the implementation of the palindrome checking function
- `palindrome.h`: Header file with function prototypes

## Function Prototype
```c
int is_palindrome(unsigned long n);
```
- Returns 1 if n is a palindrome, 0 otherwise
- No dynamic memory allocation allowed

## Example Usage
```bash
$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
$ ./palindrome 121
121 is a palindrome.
$ ./palindrome 12345
12345 is not a palindrome.
$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
```