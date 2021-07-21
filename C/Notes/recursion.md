# Recursion
Recursive definition of a string:
```
Definition:
  string := '\0'
         := char, string

Examples:
  "\0"            -- '\0'
  "r"             -- 'r', '\0'
  "roses are red" -- 'r', 'oses are red\0'
