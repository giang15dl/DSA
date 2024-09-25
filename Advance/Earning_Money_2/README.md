# Earning Biggest Prize Money 2
>
> Level 4

The winner in a quiz contest will be given an opportunity to earn bonus prize money.
Among the given number cards, the winner can choose two number cards and exchange their positions as many times as the set number.

For example, let's assume five number cards `3, 2, 8, 8, 8` are given as follows and the number of exchange is set to `2`.

Before exchange

```
3 2 8 8 8
```

For a first time, positions of 3 in the first card and 8 in the fourth card were switched and the order of the cards became `8, 2, 8, 3, 8`

```
3 2 8 8 8
^     ^
```

Next, positions of 2 in the second card and 8 in the last card were switched and the order of the cards became `8, 8, 8, 3, 2`.

```
8 8 8 3 2
  ^     ^
```

After switch is made as many as the set number, prize money is calculated by the weight given to the positions of the cards.
The prize money is 1 won at right end and it increases by ten times as it moves by one digit.
When the order of the cards becomes `8,8,8,3,2` as shown in the example above, the winner will get the bonus prize money of `88832` won.

Note that switch must be made as many times as the set number, and the switch of the same positions switched can take place.
In the following case, the number of exchange is set to 1, so switch must occur once to get 49 as the result.

```
9 4 ---Switch once---> 4 9
```

In case of 94, when switch is made twice, the order goes back to the original number which is 94.

Now, compute the biggest amount of prize money the winner can get when number cards are switched as many times as the set number.

## Input

A maximum of `50` test cases are given through standard input.
The first line of the input has number of test cases `T` (`1 <= T <= 50`).
For each test case, the information on number cards and the number of exchange are given.
The information on the number cards will be given in integer-type numbers, and the maximum number of digits is `6`.
Number of exchange is less than or equal to `10`.

```
4
321 1
123 1
2737 1
32888 2
```

## Output

Print `Case #C` in the first line for each test case with `C` being the case number.
The next line print the biggest amount of prize money the winner can receive after exchange in the same line.

```
Case #1
312
Case #2
321
Case #3
7732
Case #4
88832
```
