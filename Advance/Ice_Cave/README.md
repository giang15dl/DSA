# Ice Cave
>
> Level 3

You play a computer game.
Your character stands on some level of a multilevel ice cave.
In order to move on forward, you need to descend one level lower and the only way to do this is to fall through the ice.

The level of the cave where you are is a rectangular square grid of `n` rows and `m` columns.
Each cell consists either from intact or from cracked ice.
From each cell you can move to cells that are side-adjacent with yours (due to some limitations of the game engine you cannot make jumps on the same place, i.e. jump from a cell to itself).
If you move to the cell with cracked ice, then your character falls down through it and if you move to the cell with intact ice, then the ice on this cell becomes cracked.

Let's number the rows with integers from `0` to `n-1` from top to bottom and the columns with integers from `0` to `m-1` from left to right.
Let's denote a cell on the intersection of the `(r-1)-th` row and the `(c-1)-th` column.

You are staying in the cell `(r1, c1)` and this cell is cracked because you've just fallen here from a higher level.
You need to fall down through the cell `(r2, c2)` since the exit to the next level is there.
Can you do this?

## Input

The first line contains the total number of test cases.

Then 6 numbers are provide in the next line : `n m r1 c1 r2 c2`

The first line contains two integers, `n` and `m` (`1 <= n, m <= 500`) - the number of rows and columns in the cave description.
Then, `r1` and `c1` (`0 <= r1 < n, 0 <= c1 < m`) - your initial coordinates.
It is guaranteed that the description of the cave contains character `0` in cell `(r1, c1)`, that is, the ice on the starting cell is initially cracked.

The next two integers `r2` and `c2` (`0 <= r2 < n, 0 <= c2 < m`) - the coordinates of the cell through which you need to fall.
The final cell may coincide with the starting one.

Each of the next `n` lines describes the initial state of the level of the cave, each line consists of `m` characters `1` (that is, intact ice) and `X` (cracked ice).

```
5
4 6 0 5 1 1
0 1 1 1 0 0
1 1 1 0 0 1
1 0 1 1 0 1
1 1 1 1 1 1
5 4 4 2 0 0
1 0 1 1
1 1 1 0
0 1 0 1
1 1 1 1
1 0 0 1
4 7 1 1 0 5
1 1 0 1 0 0 1
1 0 0 1 1 0 1
0 1 1 1 0 1 1
0 1 1 1 1 1 1
10 10 3 6 3 5
1 0 1 0 1 0 1 0 1 0 
0 1 1 0 1 0 0 0 0 1 
0 0 0 0 1 0 1 0 0 0 
0 0 0 0 0 1 0 0 1 1 
0 1 1 0 1 0 0 0 1 1 
1 1 0 1 1 0 0 0 1 0 
1 0 1 1 0 1 1 1 0 1 
0 0 0 0 1 1 1 1 0 1 
1 0 0 1 1 0 1 0 0 0 
1 1 1 0 0 1 1 0 1 0 
10 10 6 8 1 5
0 1 0 1 0 0 1 0 0 1 
1 0 1 1 1 0 1 0 0 1 
0 0 0 1 1 1 0 1 1 0 
0 0 1 1 1 1 0 0 0 0 
1 1 0 1 0 1 0 0 0 0 
1 1 0 1 0 1 1 1 0 1 
1 0 1 0 0 1 1 1 1 0 
0 1 1 0 0 1 0 0 0 1 
1 1 1 0 0 1 0 0 0 1 
1 0 0 0 0 0 1 1 0 1 
20 20 15 17 0 9
```

## Output

If you can reach the destination, print `YES`, otherwise print `NO`.

```
YES
NO
YES
NO
YES
```

## Note

In the first sample test one possible path is:

```
(1, 6)
(2, 6)
(3, 6)
(4, 6)
(4, 5)
(4, 4)
(4, 3)
(4, 2)
(4, 1)
(3, 1)
(2, 1)
(2, 2)
(2, 3)
(1, 3)
(1, 2)
(2, 2)
```

After the first visit of cell `(2, 2)` the ice on it cracks and when you step there for the second time, your character falls through the ice as intended.

