# Sudoku
>
> Level 3

Sudoku is a number-placement puzzle.
The objective is to fill a `9 x 9` grid with numbers in such a way that each column, each row, and each of the nine `3 x 3` sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Create a program that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above.
Note that the puzzle represented by grid does not have to be solvable.

## Example

```
grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
```

the output should be `1`;

```
grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
```

the output should be `0`;

The given grid is not correct because there are two 1s in the second column.
Each column, each row, and each `3 x 3` subgrid can only contain the numbers 1 through 9 one time.

## Input Example

```
2                       // Total test cases
. . . 1 4 . . 2 .       // Test case 1       
. . 6 . . . . . .
. . . . . . . . .
. . 1 . . . . . .
. 6 7 . . . . . 9
. . . . . . 8 1 .
. 3 . . . . . . 6
. . . . . 7 . . .
. . . 5 . . . 7 .
. . . . 2 . . 9 .       // Test case 2
. . . . 6 . . . .
7 1 . . 7 5 . . .
. 7 . . . . . . .
. . . . 8 3 . . .
. . 8 . . 7 . 6 .
. . . . . 2 . . .
. 1 . 2 . . . . .
. 2 . . 3 . . . .
```

## Output Example

```
#1 1
#2 0
```

