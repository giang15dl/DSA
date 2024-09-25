# Partition 1
>
> Level 3

This time, Samsung Electronics, in a new building was built on the Umyeon Dong.
Wireless division also was assigned to the spacious.
The total space for Wireless division is fixed and the space for each group is fixed.
Now we should assign partitions for each group.

The time for assigning partition is proportional to size of space.
For example, if the size of space is 1000, it spends time of 1000 to partition it
(It spends same time if we partition it as $300+700$ or $500+500$.)

The total time depends on the order of partitioning.
For example, in case the size of total space is 800, and each size for groups is 100, 200, and 500.
If partitioning $100 + 700$ first, partitioning $200 + 500$ later, then the total time is $800 + 700 = 1500$
But, if partitioning $500 + 300$ first, partitioning $100 + 200$ later, then the total time is $800 + 300 = 1100$

Write program to print the minimum time to partition for all groups.

## Input

There can be more than one test case in the input.

The first line has `T`, the number of test cases.

Then the totally `T` test cases are provided in the following lines.

In each test case, the first line has an integer `N` (`1 <= N <= 1000`); the number of group.

The next line enumerates `N` integers each separated by a blank; each integer means the size of space `S` for each group. (`10 <= S <= 5000`)

```
2
3
500 100 200
4
30 40 10 20
```

# Output

For each test case, you should print your answer in two line.

```
Case #1
1100
Case #2
190
```
