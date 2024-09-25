# Calculator 1
>
> Level 1

Create a program which converts a character string of calculation formula to a postfix expression and calculates it.

For example, a character string `"3+4+5+6+7"` can be converted to a postfix expression `34+5+6+7`.

The calculation should yield 25.

The operator used in the formula is `+` only, and the operands are the integers between `0 ~ 9`.

## Input

The first line of the input file provides the length of the test case.
The test cases are given in the next lines. Total of 10 test cases are given.

```
101
9+8+5+9+2+4+1+8+3+9+3+8+7+8+6+8+9+4+1+1+7+6+1+5+8+7+6+9+6+3+1+3+1+7+5+9+2+8+4+3+7+3+4+7+3+4+8+3+2+6+6
83
7+4+8+3+4+8+5+5+3+6+7+1+2+5+6+5+5+6+1+6+7+8+6+4+7+4+3+1+6+1+2+1+6+8+6+9+2+7+4+3+2+3
...
```

## Output

The output file outputs the test case number following the `#` symbol.
It is followed by a space, and then the answer.

```
#1 267
#2 197
...
```

