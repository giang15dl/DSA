# Well Project

![](example.png)

Our company planned to help dig a well in a place in Africa which suffers from lack of water.
After lots of research, we could dig the well full of water.
After this success, we decided not only to dig the well but also to connect pipelines to towns scattered far from the well.

Now your task is to connect all towns together with the well with the minimum length of pipelines.
Find out the minimum pipeline length.

Time limit : `1 sec` for C/C++ and `2 sec` for Java

## Input

There can be more than one test case in the input file.
The first line has `T`, the number of test cases.
Then the totally `T` test cases are provided in the following lines (`T ≤ 10`)

In each test case, The size of the matrix `N` is given at the first row (`3 ≤ N ≤ 100`).
The distance information of each town is given from the second row to row of `N`.
The information is the format of `N×N` matrix.
`j-th` number of `i-th` row is the distance from `i-th` town to `j-th` town.
The number on a diagonal line is always 0.

```
2
3
0 1 4
1 0 2
4 2 0
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
```

## Output

For each test case, you should print `Case #T` in the first line where `T` means the case number.
For each test case, you should output the minimum pipeline length to connect each town in the first row.

```
Case #1
3
Case #2
28
```

