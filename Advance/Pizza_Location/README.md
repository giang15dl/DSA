# Pizza Location
>
> Level 4

Our friend Picko is very reach and he wants to open lots of restaurants with delivery.
The main food will be, of course, pizza.
He has certain number of potential locations for the restaurants, and he knows the locations of the solitaires with lots of people which will often be his customers.
Delivery of each restaurant will cover all the solitaires in given radius.

Picko can open only limited number of restaurants, and he wants that restaurants on the locations which will cover maximal number of people in solitaires.

Write a program that will calculate maximal number of people which we can cover with delivery.

## Input

In the first line of the input file there are two integers `K` and `R`, separated with space, number of restaurants and radius of delivery, `1 <= K <= 10, 1 <= R <= 500`.

In the second line there is integer `M`, number of locations, `K <= M <= 20`.

In each of the next `M` lines there are two integer `X` and `Y`, separated with space, coordinates of each location, `-1000 <= X, Y <= 1000`.

In the next line there is integer `N`, number of solitaires, `1 <= N <= 100`.

In each of the next `N` lines there are three integers `X`, `Y` and `S`, separated with space, `X` and `Y` are coordinates of each solitaire, and `S` is number of people in that solitaire, `-1000 <= X,Y <= 1000`, `1 <= S <= 100`.

We consider that solitaire is in radius of some restaurant if distance between them is less or equal to R.
There are no two locations of restaurants on the same place.

```
3
2 2
3
1 0
4 0
7 0
4
0 0 1
3 0 7
5 0 9
8 0 1
2 2
3
-2 0
0 1
3 0
8
-3 1 1
-3 0 1
-3 -1 1
-2 -1 1
0 0 3
0 2 1
2 1 3
4 0 2
3 3
5
0 0
1 6
2 3
6 6
7 2
8
0 1 2
0 5 3
0 6 1
1 0 1
3 2 3
3 6 2
6 2 4
8 6 3
```

## Output

In only line of the output file we have to write maximal number from the text above.

```
#1 18
#2 12
#3 17
```