# Merge Sort

A simple C implementation of the top-down Merge Sort algorithm with detailed merge output.

## Requirements
- Ubuntu 14.04 LTS
- `gcc 4.8.4` with flags `-Wall -Werror -Wextra -pedantic`
- No global variables; max 5 functions per file
- Only one `malloc`/`free` call in `merge_sort`

## Files
- **sort.h** – function prototypes and include guards  
- **0-merge_sort.c** – Merge Sort implementation with debug prints  
- **print_array.c** – helper to display integer arrays  
- **0-O** – Big O time-complexity notation

## Usage
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
./merge
```