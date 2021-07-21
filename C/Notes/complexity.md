# Complexity
Given two correct functions with the same functionality and both are correct
* prefer the one that is faster and more readable

Big-O notation
* a representation of the growth rate of a function

`f(n) = O(g(n))`
* means there are positive constants `c` and `k` such that `0 <= f(n) <= cg(n)` for all `n >= k`

### Recursion
Recursive definition of a string:
```
Definition:
  string := '\0'
         := char, string

Examples:
  "\0"            -- '\0'
  "r"             -- 'r', '\0'
  "roses are red" -- 'r', 'oses are red\0'
```
