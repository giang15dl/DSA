# Princess
>
> Level 3

The maze is a `NxN` matrix (`N <= 200`). Each cell contains either 1 of the 3 values:

- 0 : trap
- 1 : path
- 2 : princess

There can only be 1 princess, that is, only 1 cell contain the value 2 where the princess is held captive.

The Prince is always at cell `(1,1)`.
The exit is at cell `(N,N)`.
The Prince cannot move to the cell has trap and he can only be move to the two cell that have a shared edge.

Help the Prince find the shortest path to save the Princess and exit the Maze.

Example:

```
Entrance
    |
    v
    1 0 1 1 0
    1 0 0 0 0
    1 1 2 1 1
    1 1 1 0 1
    1 0 1 0 1
            ^
            |
           Exit
```

-> Requires at lease 8 steps to save the princess and exit the maze.
Print out `8`

```
Entrance
    |
    v
    1 0 1 1 0
    1 0 0 0 0
    1 1 2 0 0
    1 1 0 0 1
    1 0 1 1 1
            ^
            |
           Exit
```

-> Requires at lease 10 steps to save the princess and exit the maze:
4 steps to move from entrance to the princess and 6 steps to the exit.
Print out `10`

```
Entrance
    |
    v
    1 1 0 2 1 1
    0 1 0 1 0 1
    0 1 0 1 0 1
    0 0 0 1 0 1
    0 0 0 1 0 1
    1 1 1 1 0 1
              ^
              |
             Exit
```

-> There are no posible solution to this. Print out `-1`

## Input

The first line is the total number of test cases `T` (`T <= 10`)
The following lines is `T` test cases.
E
ach test cases consists of:

- The first line is `N` (`N <= 200`)
- Next `N` lines is a matrix `NxN` that describes the maze

```
3
5
1 0 1 1 0
1 0 0 0 0
1 1 2 1 1
1 1 1 0 1
1 0 1 0 1
5
1 0 1 1 0
1 0 0 0 0
1 1 2 0 0
1 1 0 0 1
1 0 1 1 1
6
1 1 0 2 1 1
0 1 0 1 0 1
0 1 0 1 0 1
0 0 0 1 0 1
0 0 0 1 0 1
1 1 1 1 0 1
```

## Output

Print out `T` lines, each line print out the minimum steps required for each test case, otherwise, print out `-1`.

```
8
10
-1
```
