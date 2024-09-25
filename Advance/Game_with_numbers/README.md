# Game with numbers
>
> Level 5

We have a game for you to play with a computer (Com).
Your goal is picking numbers from a given array of even length to get maximum scores with the following rules:

- The first turn is you, then the turn of computer and so on.
- Each turn, you (com) can only pick a number either in the left most or the right most on existing array.
- When an element is selected, it will be removed from the array.

The game has two levels, the first is very easy - the computer is very stupid, and the second is very hard - the computer is very smart, then the maximum scores you can get in two case may be different.

What are the values?

For example, if the game have 4 numbers as below

```
5           8           4           2
```

In case very easy level, the maximum scores you can get is 13:

```
1st turn: You pick 5,
2nd turn: Com  pick 2,
3rd turn: You pick 8,
Last turn: Com pick 4.
```

In case very hard level, the maximum scores you can get is only 10:

```
1st turn: You pick 2,
2nd turn: Com  pick 5,
3rd turn: You pick 8,
Last turn: Com pick 4.
```

Note that: if you pick 5 first, then the smart computer will pick 8, so you can get only 9.

Therefore  the answer for this case is 13 10.

Time limit: `10 sec` (C/C++), `20 sec` (Java).

## Input

The first line is `T` (`T <= 50`), the number of test cases.
Each test case given on two  lines, the first line is the number `N` (`N <= 30`), `N` is even number, the next line is the elements of array, each element is greater than 0 and less than or equals 1000.

```
5
4
5 8 4 2
4
8 5 4 2 
10
35 4 50 19 39 1 39 28 18 29 
20
51 41 95 96 25 20 26 77 95 59 3 72 67 79 94 52 85 19 65 20 
30
260 9 120 472 4 446 282 5 393 186 314 199 90 223 439 38 411 462 235 9 462 460 494 16 270 438 370 59 201 472 
```

## Output

Print the answer for each test case on 2 lines, the first line is `Case# x`, where `x` is the test case number.

The next line is two numbers, the first is the maximum scores you can get in very easy level, and the next numbers is the maximum scores you can get in very hard level.

```
Case #1
13 10
Case #2
13 12
Case #3
192 181
Case #4
809 606
Case #5
6175 4557
```
