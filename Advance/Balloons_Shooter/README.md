# Balloons Shooter
>
> Level 4

Given $N$ Balloons with each one has a number $K$ on it.

The player need to shoot the ballons to get the maximum score.

The player's score is the total score of each shot, with the following rules : 

- The score of each shot is equal to the product of the two ballons next to the one being shoot.
- If there's only one balloon next to it, then the score is equal to this balloon.
- If there's no balloon next to it, then the score is equal to the balloon being shoot it self.

Find the maximum score possible in print it out.

## Constraints

$N \leq 10$, $K <  1000$

## Input

```
5
6
24 41 22 97 39 41
5
84 39 33 59 81
6
99 84 56 68 76 99
8
89 32 42 44 83 38 24 67
8
27 92 81 90 74 88 53 90
```

## Ouput

Print out the maximum score with the following format.

```
Case #1
11348
Case #2
14700
Case #3
30759
Case #4
29289
Case #5
43110
```