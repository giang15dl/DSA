# 8-Queen: Maximum Score
>
> Level 4

The King of Narnia has no children, so he has decided that the country will be split into up to `k` separate parts on his death and each part will be inherited by whoever performs best at some test.
It is possible for any individual to inherit more than one or indeed all of the portions.
To ensure that only highly intelligent people eventually become his successors, the King has devised an ingenious test.

In a large hall filled there are `k` chess boards placed.
Each chessboard has numbers in the range `1` to `99` written on each square and is supplied with `8` chess queens.
The task facing each potential successor is to place the `8` queens on the chess board in such a way that no queen threatens another one, and so that the numbers on the squares thus selected sum to a number at least as high as one already chosen by the King.

Note: As per the rules of chess, each row and column of the board contains exactly one queen, and each diagonal contains no more than one.

Write a program that will read in the number and details of the chessboards and determine the highest scores possible for each board under these conditions

## Input

First line contains the number representing total number of test cases.
Then input of each test case follows.

Test case Input will consist of `k` (the number of boards), on a line by itself, followed by `k` sets of `64` numbers, each set consisting of `8` lines of `8` numbers.
Each number will be a positive integer less than `100`.
There will never be more than `20` boards.

```
2
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
2
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
```

## Output

Output will consist of `k` numbers consisting of your `k` scores, each score on a separate line.
Note that first output line of each test case should be `Case #tn`, where `tn` is the test case number.

```
Case #1
260
Case #2
260
260
```

