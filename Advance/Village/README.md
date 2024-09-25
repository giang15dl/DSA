# Village
>
> Level: 3

Given a map of the transportation network between villages.
A region is defined as a set of villages from which any village in the region can reach another village in the region.

Calculate the number of regions in the map, the number of isolated villages
(villages with no road to any other village)
and the number of roads that act as "Bridges" between the two regions
(if this road is removed, the number of regions increases up 1).

## Input

The first line has a number `T` which is the number of tests in the input file.

Each test is arranged as follows: the first line is a positive integer `N`, the number of villages (`N <= 300`), followed by a matrix `A[i, j]` in which `A[i][j]` has the value of 1 means there is a road from village `i` to village `j` and 0 if there is none.

The data ensures that if there is a road from village `i` to village `j`, there will also be a reverse route.

```
2
5
0 1 0 1 0
1 0 0 1 0
0 0 0 0 1
1 1 0 0 0
0 0 1 0 0
7
0 0 0 1 0 0 1
0 0 0 1 0 0 0
0 0 0 0 1 0 0
1 1 0 0 0 0 1
0 0 1 0 0 0 0
0 0 0 0 0 0 0
1 0 0 1 0 0 0
```

## Output

For each test, print out the number of regions on the map, the number of isolated villages, and the number of roads serving as bridges.

```
2 0 1
3 1 2
```
