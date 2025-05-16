# Reddit Keyword Counter

## Description
This project provides a recursive function that interacts with the Reddit API to count and sort the occurrences of specified keywords in hot article titles.

## Features
- Queries the Reddit API for hot posts in a specified subreddit
- Counts occurrences of given keywords in post titles (case-insensitive)
- Displays results sorted by count (descending) and alphabetically when counts are equal
- Handles word variations properly (ignores punctuation)
- Implements proper error handling for invalid subreddits

## Requirements
- Python 3.4.3
- Requests library

## Usage
```
python3 0-count.py <subreddit> <list of keywords>
```

Example:
```
python3 0-count.py programming 'python java javascript react'
```

## Function Prototype
```python
def count_words(subreddit, word_list)
```

## Notes
- Words with no matches are not displayed
- Keywords must be space-delimited in the input
- The function uses recursion to handle Reddit's pagination
- Results reflect the number of keyword occurrences, not the number of posts containing them

