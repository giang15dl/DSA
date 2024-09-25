# Battle City
>
> Level 4

Many of us had played the game "Battle city" in our childhood, and some people (like me) even often play it on computer now.

![1](1.jpg)

What we are discussing is a simple edition of this game. Given a map that consists of empty spaces, rivers, steel walls and brick walls only.
Your task is to get a bonus as soon as possible suppose that no enemies will disturb you (See the following picture).

![2](2.jpg)

Your tank can't move through rivers or walls, but it can destroy brick walls by shooting.
A brick wall will be turned into empty spaces when you hit it, however, if your shot hit a steel wall, there will be no damage to the wall.
In each of your turns, you can choose to move to a neighboring (4 directions, not 8) empty space, or shoot in one of the four directions without a move.
The shot will go ahead in that direction, until it go out of the map or hit a wall.
If the shot hits a brick wall, the wall will disappear (i.e., in this turn).
Well, given the description of a map, the positions of your tank and the target, how many turns will you take at least to arrive there?  

## Input

There can be more than one test case in the input.
The first line has `T`, the number of test cases.
Then the totally `T` test cases are provided in the following lines (`T<=10`).
The first line of each test case contains two integers `N` and `M` (`2 <= N, M <= 300`).
Each of the following `N` lines contains `M` uppercase letters, each of which is one of

- `Y` : you
- `T` : target
- `S` : steel wall 
- `B` : brick wall
- `R` : river 
- `E` : empty space

Both `Y` and `T` appear only once.

```
5
3 4
YBEB
EERE
SSTE
3 4
YBEB
EERE
SSTS
3 4
YESS
EEEE
ESET
3 4
YESS
EEEE
ESBT
8 8
EESEEEEE
YBSEESEE
EEEESESE
ESEEEEES
ESBESEEE
ESSEEBBE
EEEEBBSE
EEBSEETS
```

## Output

For each test case, please output the turns you take at least in a separate line.
If you can't arrive at the target, output "-1" instead.

```
Case #1
8
Case #2
-1
Case #3
5
Case #4
5
Case #5
13
```
