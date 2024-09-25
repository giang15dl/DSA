# Matrix Product
>
> Level 3

We need time proportional to $N^3$ to multiply two $N \times N$ matrices.
We are going to compute $A^M$ for a given matrix $A$.
If we simply conduct matrix multiplication $M-1$ times, we need time proportional to $(M-1)*N^3$.
We may need huge time in this way.
You should speed up this job.
Given an $N*N$ matrix $A$, you should provide a program that compute $A^M \mod 100000007$ as fast as possible, for an $M \geq 2$.
$A^M \mod q$ means the matrix in which each element has the remainder after divided by $q$, with the value $0$ through $q-1$.
For instance, $\mod 6$ is . (This is just for avoiding overflow by too big integers. You only have to conduct $x*y \mod q$ for any $x*y$)
In this problem, the most important thing is the running time.
If time limit passes, you got points for the cases that your program has completed.
The input will be provided in the increasing order of problem sizes; so an inefficient program may successfully run only some small cases.
If you try the most naive way, we guess you would have about 30% of the total scores.

Time limit: 2 seconds.

## Input

There can be more than one test case in the input file.
The first line has $C$, the # of test cases.
Then the totally $C$ test cases are provided in the following lines.
In each test case, the first line has $N$ and $M$, the dimension of the matrix and the exponent. $1 \leq N \leq 100$, $1 \leq M \leq 10000000$
The following $N$ lines enumerate the elements of the matrix.
Each line enumerates $N$ elements.
All neighbored numbers in a line are separated by a blank.

```
2
2 4
1 2
1 2
3 5
1 0 0
1 1 1
1 0 3
```

## Output

For each test case, you should print `Case #T` in the first line where `T` means the case number.
The next $N$ lines enumerate the elements of the solution matrix.
As the input file, each line has $N$ elements each separated by a blank.

```
Case #1
27 54
27 54
Case #2
1 0 0
63 1 121
121 0 243
```

