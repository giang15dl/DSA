# Cutting a Piece of Colored Paper
>
> Level 3

You want to cut a piece of paper by a certain fixed rule to make some pieces of white or blue colored square paper with various sizes.

If the size of the entire paper is $N \times N$ ($N = 2^K; 1 \leq K \leq 7$; $K$ is natural number), the cutting rules are as below.

If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically to divide it into the same sized four pieces of paper, $(N/2) \times (N/2)$, as with I, II, III, IV in Fig.2.

|Fig.1|Fig.2|Fig.3|Fig.4|
|-|-|-|-|
|![](./Fig1.jpg)|![](./Fig2.jpg)|![](./Fig3.jpg)|![](./Fig4.jpg)|

For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper is not colored the same, and make them into the same sized four pieces of paper.
Continue until each and every piece of paper has only one color of white or blue.

When you finish, Fig.1 shows the first division of Fig.1 and Fig.4 shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.

If the length of an edge of the first given piece of paper, $N$, and the color information (white or blue) inside each square are given, create a calculation program that assesses how many white/blue pieces of paper are.

Time limit: 1 second (java: 2 seconds)

## Input

Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T ≤ 30)
The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.

```
2
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
16
1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0
```

## Output

For each test case, you should print `Case #T` in the first line where `T` means the case number.

For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.

```
Case #1
9 7
Case #2
88 99
```
