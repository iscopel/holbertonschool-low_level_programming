# comparison_algorithms Metrics

Compiled with: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long comparison_algorithms.c -o comparison_algorithms

## Raw output

### Run 1

    Naive algorithm result: 625025000
    Naive algorithm time: 1.213582 seconds
    Single-pass algorithm result: 25000
    Single-pass algorithm time: 0.000044 seconds

### Run 2

    Naive algorithm result: 625025000
    Naive algorithm time: 1.239002 seconds
    Single-pass algorithm result: 25000
    Single-pass algorithm time: 0.000058 seconds

### Run 3

    Naive algorithm result: 625025000
    Naive algorithm time: 1.211163 seconds
    Single-pass algorithm result: 25000
    Single-pass algorithm time: 0.000043 seconds

## Execution times (seconds)

| Run | Naive (A) | Single-pass (B) |
|-----|-----------|-----------------|
| 1 | 1.213582 | 0.000044 |
| 2 | 1.239002 | 0.000058 |
| 3 | 1.211163 | 0.000043 |
| **Average** | **1.221249** | **0.000048** |

## Relative difference

Average naive time / average single-pass time = 1.221249 / 0.000048.

Result: the naive implementation is ~25443 times slower than the single-pass implementation.

Both algorithms scan the same array for even values (the naive version re-counts every prefix, so it prints 625025000, while the single-pass version prints 25000). The time difference comes from the amount of work: the naive version is O(n^2) (about 1.25 billion inner iterations for n = 50000), while the single-pass version is O(n) (50000 iterations).
