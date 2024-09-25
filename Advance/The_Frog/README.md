# The Frog
>
> Level 4

A Swamp has `n` leaves placed closely on the surface.
A frog is sitting on the first leaf and it needs to move to the `n-th` leaf.
These leaves are circular and the frog can move between the two leaves in the following rules:

- If the distance between the two nearest point of the two leaves is no greater than 40cm: the frog can makes a short jump.
- If the distance between the two nearest point of the two leaves is greater than 40cm and less than 90 cm: the frog can makes a long jump.
- If the distance between the two nearest point of the two leaves is greater than 90 cm: the frog can't makes the jump.

A short jump barely costs the frog any energy, as constract to a long jump, which costs a lot of energy.
Therefore, the path from one leaf to another is better if the number of long jumps is minimum.
In case where the number of long jumps is equal, the path with less short jumps is better.

Find the best path for the frog.
Print out the number of long jumps and short jumps required for that path.

## Input

The first line is total number of test cases `T` (`T <= 10`)
Each test case consist of:

- The first line is a Natural number `n` (`n <= 200`)
- The next `n` lines is 3 numbers : `x_i y_i r_i` where `(x_i, y_i)` is the coordinates of the `i-th` leaf, and `r_i` is the radius of that leaf. (the unit is cm and `0 <= x_i, y_i, r_i <= 10000`)

```
2
2
1 10 10
100 100 15
4
0 10 10
20 60 12
30 10 10
70 10 8
```

## Output

Each test case print out the number of long jumps and short jumps required for the best path.
If there no posible path, print out `-1`.

```
-1
0 2
```

