# Hugo Về Nhà

> Level 4

Hugo đang trền đường về nhà và cần đi qua 1 đoạn đường B.

Trên đoạn đường đi qua có `N` cổng.
Tại mỗi cổng có 1 số lượng binh sĩ và giá để đi qua cổng đó.
Muốn đi qua mỗi cổng Hugo có 3 cách lựa chọn.

1. Pass:
   Trả số tiền quy định ở cổng đó để được đi qua

2. Hire:
   Trả gấp đôi số tiền ở cổng đó để thuê số binh sĩ gộp vào đoàn quân của mình

3. Battle:
   Điều kiện để đánh nhau là số quân của Hugo >= số lượng lính tại cổng đó. Có các lưu ý:
   - Hugo không được tính vào số lượng của quân
   - Mỗi người lính chỉ tham gia được vào tối đa 3 trận đánh. Sau 3 trận đánh nếu đi nhóm binh sĩ đó còn sống thì cũng giải tán.
   - Mỗi trận đánh thì tất cả số binh sĩ đều tham gia.
   - Đánh nhau chết theo tỉ lệ 1: 1. Ai tham gia trước sẽ bị chết trước

## Input

Dòng đầu tiên là số lượng trường hợp thử nghiệm

Mỗi trường hợp thử nghiệm sẽ có

- Dòng đầu tiên chứa số lượng cổng `N` (`N <= 20`)
- N dòng tiếp theo chứa 2 số là số binh lính `K` và chi phí `P` tại mỗi cổng (`2 <= K, P <= 1000`)

## Output

In ra chi phí nhỏ nhất Hugo có thể đi qua đoạn đường B

```
2
7
10 100
70 5
80 15
20 60
50 90
30 80
10 10
9
600 800
300 400
300 400
1000 400
300 600
100 300
600 300
600 500
1000 300
```

## Output:

```
#1 150
#2 3000
```

## Giải thích

|            | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| ---------- | --- | --- | --- | --- | --- | --- | --- |
| Số binh sĩ | 10  | 70  | 80  | 20  | 50  | 30  | 10  |
| Chi phí    | 100 | 5   | 15  | 60  | 90  | 80  | 10  |

Có thể tính chi phí đi nhỏ nhất

|            | 1    | 2    | 3    | 4      | 5      | 6      | 7    |
| ---------- | ---- | ---- | ---- | ------ | ------ | ------ | ---- |
| Số binh sĩ | 10   | 70   | 80   | 20     | 50     | 30     | 10   |
| Chi phí    | 100  | 5    | 15   | 60     | 90     | 80     | 10   |
| Chọn       | Pass | Hire | Hire | Battle | Battle | Battle | Pass |
| Chi phí    | 100  | 110  | 140  |        |        |        | 150  |
