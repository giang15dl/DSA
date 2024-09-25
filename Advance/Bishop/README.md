# Quân tượng
>
> Level 4

Xét bàn cờ vuông kích thước n×n.
Các dòng được đánh số từ 1 đến n, từ dưới lên trên.
Các cột được đánh số từ 1 đến n từ trái qua phải.

Ô nằm trên giao của dòng i và cột j được gọi là ô (i,j).
Trên bàn cờ có m (0 ≤ m ≤ n) quân cờ. Với m > 0, quân cờ thứ i ở ô (ri, ci), i = 1,2,..., m.
Không có hai quân cờ nào ở trên cùng một ô.
Trong số các ô còn lại của bàn cờ, tại ô (p, q) có một quân tượng.
Mỗi một nước đi, từ vị trí đang đứng quân tượng chỉ có thể di chuyển đến được những ô trên cùng đường chéo với nó mà trên đường đi không phải qua các ô đã có quân

Cần phải đưa quân tượng từ ô xuất phát (p, q) về ô đích (s,t).

Cho kích thước bàn cờ n, số quân cờ hiện có trên bàn cờ m và vị trí của chúng, ô xuất phát và ô đích của quân tượng.
Hãy xác định **số nước đi ít nhất** cần thực hiện để đưa quân tượng về ô đích hoặc đưa ra số `-1` nếu điều này không thể thực hiện được.

## Constraints

N = 1~200

## Input

Dòng đầu tiên chứa số testcase.
Mỗi testcase có cấu trúc như sau:
- Dòng thứ nhất chứa 6 số nguyên n, m, p, q, s, t.
- Nếu m > 0 thì mỗi dòng thứ i trong m dòng tiếp theo chứa một cặp số nguyên ri, ci xác định vị trí quân thứ i.
  Hai số liên tiếp trên cùng một dòng được ghi cách nhau ít nhất một dấu cách.

```
2
5 5 5 5 5 3
1 2
1 5
2 2
4 2
4 3
8 3 7 2 1 4
5 4
3 4
4 7
```

## Output

Với mỗi test case in ra 1 dòng duy nhất là số nước đi tìm được.

```
2
3
```

## Maybe Helpful

![Minimize the number of turns needed to reach from top left cell to bottom right cell of the matrix](https://www.geeksforgeeks.org/minimize-the-number-of-turns-needed-to-reach-from-top-left-cell-to-bottom-right-cell-of-the-matrix/)