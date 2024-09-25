# Find cycle
>
> Level 3

Given a directed graph, detect and print the cycle in ascending order.

If there are multiple cycles, print the cycle with nodes' sum smallest.

## Input

The first line contains the total number of test cases

Given number of nodes and edges, `N`, `M` 

Next line contains edges u and v (u->v edge) space separated, `2 * M` values

```
2
5 5
1 2 2 4 4 5 5 3 3 2
5 5
2 4 2 3 4 3 1 5 5 1
```

## Output

```
2 3 4 5
1 5
```
## Constraints

`1 < N < 10`

`1 < M < 50`