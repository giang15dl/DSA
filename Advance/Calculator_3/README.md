# Calculator 3
>
> Level 3

Create a program which converts a character string of calculation formula to a postfix expression and calculates it.

For example, a character string `"3+(4+5)*6+7"` can be converted to a postfix expression `"345+6*+7+"`.

The calculation should yield 64.

The operators used in the formula are `+` and `*`.
Parentheses can be used in the formula.
The operands are the integers between `0 ~ 9`.
The parentheses are always paired properly.

## Input

The first line of the input file provides the length of the test case.
The test cases are given in the next lines.
Total of 10 test cases are given.

```
113
(9+(5*2+1)+(3*3*7*6*9*1*7+1+8*6+6*1*1*5*2)*4*7+4*3*8*2*6+(7*8*4*5)+3+7+(2+6+5+1+7+6+7*3*(6+2)+6+6)*2+4+2*2+4*9*3)
85
(4+8+4*(8*5*(7*(6*8)+3+(6+(3+7+1*7*5*4)*3)*2*3+5)+6+7*7)*4+2+9*4+7+2*3*(7*6*1*8)+9+9)
...
```

## Output

The output file outputs the test case number following the `#` symbol.
It is followed by a space, and then the answer.

```
#1 672676
#2 1974171
...
```
