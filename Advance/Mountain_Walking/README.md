# Mountain Waling
>
> Level 4

Cho một bản đồ kích thước NxN (2 <= N <= 100), mỗi ô mang giá trị là độ cao của ô đó (0 <= độ cao <= 110).
Bác John và bò Bessie đang ở ô trên trái (dòng 1, cột 1) và muốn đi đến cabin (dòng N, cột N).
Họ có thể đi sang phải, trái, lên trên và xuống dưới nhưng không thể đi theo đường chéo.
Hãy giúp bác John và bò Bessie tìm đường đi sao cho chênh lệch giữa điểm cao nhất và thấp nhất trên đường đi là nhỏ nhất.
 
## Input

- Dòng 1: Số test case
- Dòng 2: N
- N dòng tiếp theo chứa N số nguyên, mỗi số cho biết cao độ của một ô.

```
5
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
5
99 85 38 22 55
89 28 33 3 65
99 20 14 67 90
36 27 28 77 31
50 45 12 9 14
2
92 83
19 91
5
61 49 32 34 28
100 65 0 10 89
34 99 40 86 4
10 97 49 21 30
95 33 79 51 65
2
17 60
94 27
```

## Output

In ra #test case và một số nguyên là chênh lệch độ cao nhỏ nhất.
 
```
#1 2
#2 85
#3 9
#4 50
#5 43
```