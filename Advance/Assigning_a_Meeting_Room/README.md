# Assigning a Meeting Room
>
> Level 3

In our company, there is a popular meeting room. Many meetings are reserved to use this room with starting time and finishing time, and the place can’t hold two meetings at the same time if the time is overlapped. Thus only one of the same time-framed meetings can be held in here and the others should give up. However, it is not overlapped for the same starting time of a meeting and the finishing time of another meeting.
When the number of meetings, starting time and finishing time of each meetings are given, you want to hold as many meetings as possible.
In a given number of meetings and each given starting/finishing time, you want to hold as many meetings as possible. Create a program that can assign meetings to the meeting room as many as it can.

Time limit: 1 second (java: 2 seconds)

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
N, the number of meetings is given in the first row of each test case (1 ≤ N ≤ 500).
Numbers of each meeting, starting time, and finishing time are given separately from the second row to the number of N. (Each number is natural numbers below 500)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number. For each test case, you should output the maximum number of meetings which can assign in the first row of each test case.

[I/O Example]

## Input

```
2
6
1 1 10
2 5 6
3 13 15
4 14 17
5 8 14
6 3 12
15
1 4 8
2 2 5
3 2 6
4 4 6
5 2 3
6 1 6
7 4 7
8 3 5
9 3 8
10 1 2
11 1 7
12 2 4
13 5 6
14 4 5
15 7 8
```

## Output

```
Case #1
3
Case #2
5
```