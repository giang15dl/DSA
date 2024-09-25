# Painting the wall
>
> Level ?
>
> TEST 09/08/2023

Mô tả: Chúng ta sẽ bắn sơn lên tường theo tọa độ cho trước và có 2 loại đạn 1 và 2

Đạn 1: bắn vào 1 ô và lan sang 4 ô xung quanh theo dấu +

```
  1
1 2 1
  1
```

Đạn 2: bắn vào 1 ô và lan sang 4 ô xung quanh theo dấu X

```
1   1
  2
1   1
```

Trong đó tại ô được bắn sẽ dính 2 lớp sơn, còn 4 ô xung quanh chỉ dính thêm 1 lớp sơn

Tại mỗi ô chỉ chứa được tối đa 2 lớp sơn, nếu tại ô đó tiếp tục dính sơn, SƠN SẼ CHẢY XUỐNG Ô PHÍA DƯỚI
Yêu cầu: In ra số ô bị dính sơn

Ví dụ mẫu:

N M K - ma trận kích thước N x M (N hàng, M cột), K lần bắn
5 5 2
K dòng tiếp theo là thông tin mỗi lần bắn: x y z - x, y là tọa độ (hàng x - cột y) - z là loại đạn
1 1 1 -> bắn sơn loại 1 tại ô (1, 1)
2 2 2 -> bắn sơn loại 2 tại ô  (2, 2)

Mô tả bằng hình ảnh: ô màu vàng là những ô có sự thay đổi

1 1 1 -> bắn sơn lên vị trí (1, 1) loại đạn 1
 tại ô (1, 1) sẽ dính 2 lớp sơn - và 4 ô xung quanh: (0, 1), (1, 0), (1, 2), (2, 1) sẽ dính thêm 1 lớp sơn

Picture 1 	 	 	 	 


2 2 2 -> bắn sơn lên vị trí (2, 2) loại đạn 2
 tại ô (2, 2) sẽ dính 2 lớp sơn - và 4 ô xung quanh: (1, 1), (3, 3), (1, 3), (3, 1) sẽ dính thêm 1 lớp sơn
Tại ô (1, 1) sẽ dính thêm 1 lớp sơn, tuy nhiên do chỉ có thể chứa tối đa 2 lớp sơn nên 1 lớp sơn bị chảy xuống ô phía dưới (2, 1)

Picture 2 	 	 	 	 


Input:
N M K - ma trận kích thước N x M, K lần bắn
K dòng tiếp theo là vị trí bắn, loại đạn

Output:
#1  9

Giới hạn: 4 <= N, M <= 100, K <= 5000
Các ô được đánh số từ index 0.
