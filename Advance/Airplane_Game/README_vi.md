# Airplane Game
>
> Level 3
> 
> Time limit 5s.

Một máy bay di chuyển trong một bản đồ game map có kích thước chiều ngang cố định là  `M = 5` và chiều dài `5 <= N <= 25`.
Màn hình hiển thị game display có kích thước cố định `5 x 5`.
Máy bay luôn xuất phát từ 1 điểm nằm ngoài game map và ở cột chính giữa theo bề ngang của game map, hướng di chuyển từ dưới lên trên.
Tại mỗi lần di chuyển, máy bay sẽ đi được 1 ô lên trên, tới 3 vị trí: ô chéo bên trái, ô trên, ô chéo bên phải.
Trong bản đồ game map có 3 loại ô:

- Ô bằng 0 là ô trống
- Ô bằng 1 là ô coin
- Ô bằng 2 là quân địch

Luật chơi:

- Máy bay sẽ đi nhặt coin trong game map theo luật di chuyển như mô tả bên trên, từ vị trí xuất phát đến hết game map
- Khi gặp ô địch thì số coin máy bay đang có sẽ bị giảm đi 1, nếu số coin bằng 0 mà gặp ô địch thì máy bay bị nổ và trò chơi kết thúc
- Tuy nhiên, trong mỗi lượt chơi, người chơi đc sử dụng một quả bom để cho nổ hết tất cả ô địch trong màn hình game display hiện tại

Yêu cầu: tìm số coin lớn nhất mà máy bay có thể thu đc khi đi từ vị trí xuất phát đến hết game map.

```
2
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1
```

## Output

For each test output single integer with format `#test_number output`

```
#1 6
#2 9
```
