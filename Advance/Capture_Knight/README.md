# Capture Knight
>
> Level 4

There is a mobile piece (a Knight) and a stationary piece on the N×M chessboard.
The available moves of the mobile piece are the same as set out in the figure below:

```
| |x| |x| |
|x| | | |x|
| | |k| | |
|x| | | |x|
| |x| |x| |
```

You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.　　

Write a program to find out the minimum number moves to catch a piece.

## Input

Several test cases can be included in the inputs.
`T`, the number of cases is given in the first row of the inputs.
After that, the test cases as many as `T` are given in a row.

`N`, the numbers of the rows and `M`, the number of columns of the chessboard are given in the first row of each test case.

`R` & `C` is the location information of the attacking piece and `S` & `K` is the location of the defending pieces and are given in the row at the second line.
However, the location of the uppermost end of the left end is `(1, 1)``

Maximum value of `N` or `M` is `1000`.

```
2
9 9
3 5 2 8
20 20
2 3 7 9
1000 1000
178 33 150 91
```

## Output

Output the minimum number of movements to catch a defending piece at the first line of each test case.

Print `Case #tn` before each answer where `tn` is test case number.

```
Case #1
2
Case #2
5
Case #3
30
```
