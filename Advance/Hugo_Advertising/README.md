# Hugo Xếp Lịch Quảng Cáo
>
> Level 4

	
Hugo's shop need to display the advertisement 3 times a day.

However, they only has 1 electric board to display the advertisement, hence they should select the time to display advertisements so that visitors can watch them as much as possible.

When visitors watch advertisement, they can get points which calculated as below :
1. Three Ads have length `L1, L2, L3` and the points a person can get after watched them `P1, P2, P3`.
2. A visitor can get the point of a Ads  only when he/she watch the Ads  fully (from beginning to the end of that Ads)
3. When a visitor watch more than one Ads  and also get the point for them, only the Ads  with highest point will be given to that person.
4. Only one Ads  can be displayed on electric board at a time (But the next Ads  can be displayed right after the previous one ended)

**Given the length of each Ads L1, L2, L3 and the point gained for them P1, P2, P3, the arrival time of each visitor into the shop and the time duration that he/she stay in the shop, write a program to select advertisement display time so that as many points as possible can be given to visitors. Print out the total sum of points that the visitors can get.**

## Example

There are 7 visitors go to the shop with the arrival time and staying duration as below

|                   | Visitor 1 | Visitor 2 | Visitor 3 | Visitor 4 | Visitor 5 | Visitor 6 | Visitor 7  |
|:-----------------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:----------:|
| **Arrival Time**  | 2         | 6         | 3         | 7         | 1         | 2         | 1          |
| **Time Duration** | 2         | 4         | 3         | 2         | 1         | 1         | 10         |

|                     | Length | Point(s)  |
|:-------------------:|:------:|:---------:|
| **Advertisement 1** | 1      | 1         |
| **Advertisement 2** | 2      | 2         |
| **Advertisement 3** | 3      | 3         |

Assuming that Ads1 is displayed at time 2, Ads2 at time 7 and Ad3 at time 3, the visitors will watched the ads as below schedule:

|           | Visitor 1 | Visitor 2 | Visitor 3 | Visitor 4 | Visitor 5 | Visitor 6 | Visitor 7  |
|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:----------:|
| **Ads 1** | Watch     | -         | -         | -         | -         | Watch     | Watch      |
| **Ads 2** | -         | Watch     | -         | Watch     | -         | -         | Watch      |
| **Ads 3** | -         | -         | Watch     | -         | -         | -         | Watch      |

(Visitor 7 watched all Ads fully, however he can only get the highest of one Ads - which is 3 points of Ads 3)

![fig1](fig1.jpg)

There are many way to arrange the display time, and the method above give us the maximum sum of points which visitors can get, so the answer in this case is 12.

## Constraints

- The number of visitors `N` (`1 <= N <= 50`)
- The arrival time `Ai`, the time duration `Di` of each visitor and the length of each Ads `L1, L2, L3` are given as integers (`1 <= Ai, Di, L1, L2, L3 <= 50)
- `Ai + Di <= 50`
- `L1 + L2 + L3 <= 50`
- The starting time of an Ads : `1 <= starting time <= 50`
- `P1, P2, P4` are integers (`1 <= P1, P2, P3 <= 1000`)

## Input

- The first line given `T` - the total number of test cases (`T <= 50`)
- In each test case :
    - The first line contains `N, L1, L2, L3, P1, P2, P3` in this order
    - The next `N` lines : each line gives the arrival time `Ai` and time duration `Di` of each visitor

```
5                           // Number of test cases T=5
7 1 2 3 1 2 3               // Test case 1 N=7, L1=1, L2=2, L3=3, P1=1, P2=2, P3=3
2 2                         // A1 = 2, D1 = 2
6 4                         // ...
3 3
7 2
1 1
2 1
1 10
4 3 2 1 6 4 3
1 5
1 3
2 4
2 2
...
```

## Output

Out put the maximum sum of points that visitors can get from watching advertisements.

```
Case #1
12
Case #2
18
Case #3
17
Case #4
16
Case #5
17998
```