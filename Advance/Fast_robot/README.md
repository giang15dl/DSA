# Fast robot
>
> Level 4

Mr. Noh is responsible for enhancing the movement of a robot faster.
Now, Mr. Noh is thinking like this: The speed of the robot decreases when it changes its direction.
Therefore, it requires a study of the acceleration in direction changes.
However, the better method than that is to use the route with the minimum number of direction changes when it moves from point A to point B.

Because of that, he studies a maze.
When the maze information is given, he tries to create a program to move it from the starting point to the arriving point based on the minimized direction changes.

Let’s find out the minimum direction changes possible from the starting point to the arriving point when the maze information is given.

Time limit : 1 sec (Java : 2 sec)

## Input

There can be more than one test case in the input file. The first line has `T`, the number of test cases.
Then the totally T test cases are provided in the following lines (`T <= 10`)
In each test case, The width and height of the maze are given as `N` & `M` separately at the first row. (`1 <= N, M <= 200`)
The vertical coordinate and horizontal coordinate of the starting point, and the vertical coordinate and horizontal coordinate of the arriving point are given separately in order at the second row.
Information of the maze is given from the third row the number (`N`). At this time, the path indicates 0; the wall indicates 1. There is no blank each other.

```
2
7 7
1 2 7 5
1111111
0000011
1011001
1011100
1011110
1000000
1111111
7 7
1 2 7 6
1111111
0000001
1011000
1011100
1011110
1000000
1111111
```

## Output

In case of being reachable from the starting point to the arriving point, generate the minimum direction change frequency between two points.
If not, generate `-1`

```
3
2
```
