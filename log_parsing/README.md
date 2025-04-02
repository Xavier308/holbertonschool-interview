# Log Parsing

## Overview
This project implements a Python script that reads log data from stdin, parses it line by line, and computes metrics based on file sizes and HTTP status codes.

## Problem Statement
Write a script that reads `stdin` line by line and computes metrics:
- Parse log entries following the format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
- Print statistics after every 10 lines and/or after a keyboard interruption (CTRL + C)

## Key Metrics to Track
1. **Total File Size**: Sum of all file sizes from processed log entries
2. **Status Code Counts**: Number of occurrences of each status code (200, 301, 400, 401, 403, 404, 405, 500)

## Algorithm Insights

### Approach
The implementation follows these steps:
1. Read input from stdin line by line
2. Use regex or string parsing to extract file size and status code
3. Track running total of file size and counts of each status code
4. After every 10 lines or upon CTRL+C, print the statistics
5. Handle invalid lines by skipping them

### Time & Space Complexity
- **Time complexity**: O(n) where n is the number of lines
- **Space complexity**: O(1) - only tracking counts and total size

### Error Handling
- Skip lines that don't match the expected format
- Handle keyboard interruptions gracefully
- Only track valid integer status codes from the specified set

## Implementation Notes
- Uses Python 3.4.3
- Follows PEP 8 style guidelines
- Handles signal interrupts to display final statistics
- Uses dictionaries for efficient status code counting

## Example Output
```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
```

## Execution
```
./0-generator.py | ./0-stats.py
```
