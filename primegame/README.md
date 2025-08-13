# Prime Game

A game theory problem where Maria and Ben take turns removing primes and their multiples from consecutive integers.

## Rules
- Players alternate removing a prime number and all its multiples
- Maria goes first
- Player unable to move loses
- Winner determined by who wins most rounds

## Solution
Uses Sieve of Eratosthenes to precompute primes. Winner depends on parity of available primes:
- Odd number of primes → Maria wins
- Even number of primes → Ben wins

## Usage
```python
isWinner(3, [4, 5, 1])  # Returns "Ben"
```
