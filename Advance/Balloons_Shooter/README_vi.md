# Ban Bong Bay
>
> Level 4

Cho $N$ quả bóng bay với mỗi quả bóng bay có 1 giá trị số $K$.

Người chơi được yêu cầu bắn vỡ các quả bóng bay để có được số điểm lớn nhất.

Điểm của người chơi sẽ được tính bằng tổng các lần bắn bóng bay.

- Điểm của mỗi lần bắn bóng bay sẽ bằng tích của 2 quả bóng bay bên cạnh.
- Nếu bên cạnh chỉ có 1 quả bóng bay thì điểm sẽ bằng điểm của quả bóng bay này.
- Nếu không còn quả bóng bay nào bên cạnh thì điểm sẽ bằng điểm của quả bóng bay vừa bị bắn.

Hãy tìm điểm số lớn nhất và in ra.

## Constraints

$N \leq 10$, $K <  1000$

## Input

```
5
6
24 41 22 97 39 41
5
84 39 33 59 81
6
99 84 56 68 76 99
8
89 32 42 44 83 38 24 67
8
27 92 81 90 74 88 53 90
```

## Ouput

Định dạng in ra như bên dưới.

```
Case #1
11348
Case #2
14700
Case #3
30759
Case #4
29289
Case #5
43110
```