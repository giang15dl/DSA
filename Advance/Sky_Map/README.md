# Sky map
>
> Level 3

You are making "sky map" to represent constellation (group of starts) in the sky.

In each element, 1 means star, 0 means empty. And in a constellation, each start should have at least one connection with others via left/right/up/bottom.

If two starts are located via diagonal, then

the two stars are not connected (belong to different constellation.)

How many constellations are in your sky map, and what is the number of starts in the greatest constellation?

## Input

There can be more than one test case in the input.

The first line has T, the number of test cases.

Then the totally T test cases are provided in the following lines (T<=10)

In each test case, the first line has an integer N(5 ≤ N ≤ 25), the size of map.

The map is a square, and is represented as N x N matrix.

For next N lines, each contains each raw of the matrix

```
2
7
0 1 1 0 0 0 0
0 1 1 0 1 0 0
1 1 1 0 1 0 1
0 0 0 0 1 1 1
1 0 0 0 0 0 0
0 1 1 1 1 1 0
0 1 0 1 1 0 0
5
0 1 0 0 0
0 1 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
```

## Output

For each test case, you should print the number of constellation and the number of starts in the greatest constellation separated by blank.

```
4 8
1 3
```
