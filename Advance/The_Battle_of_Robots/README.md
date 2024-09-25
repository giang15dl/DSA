# Đề bài: The Battle of robots
>
> TEST 10/08/2023

Có những con robot màu đỏ và robot màu xanh ngẫu nhiên trong ma trận 100x100
Những robot màu xanh di chuyển về phía bên phải, những con robot màu đỏ di chuyển về bên trái.
Va chạm giữa 1 robot màu xanh và 1 robot màu đỏ gây hủy diệt lẫn nhau không để lại dấu vết và không gây ảnh hương đến những robot khác

Những robots sẽ dừng lại khi chúng gặp tường hoặc không thể tiếp tục tiến lên phía trước được nữa.

yêu cầu: In ra số lượng robot còn lại trên ma trận

Ví dụ: 
ma trận 8x8 như sau: 0: empty - 1 : Blue robot - 2: red robot

Before

1	0	0	0	0	0	0	2
0	0	1	1	0	2	0	0
0	2	0	0	1	2	0	0
0	2	2	2	0	1	0	0
0	1	2	1	2	2	0	2
1	0	1	0	0	1	2	0
0	0	1	1	2	2	2	0
0	0	0	0	0	0	0	1

After

0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	1
2	0	0	0	0	0	0	0
2	2	2	0	0	0	0	1
2	2	0	0	0	0	0	0
0	0	0	0	0	0	1	1
2	0	0	0	0	0	0	0
0	0	0	0	0	0	0	1

Tham khảo Picture 1

Ở dòng thứ nhất, robot màu xanh và robot màu đỏ sẽ biến mất sau khi va chạm nhau.
Ở dòng thứ 2, robot màu xanh bên trái sẽ sống sót
Ở dòng thứ 4, Robot màu đỏ và robot màu xanh đi theo hai hướng khác nhau, nên cả hai sẽ đều sống sót 
Ở dòng thứ 5. hai robots màu đỏ bên phải sẽ sống sót sau 2 lần va chạm của các robots
Kết quả là số robots cần "returns" sẽ là 12 robots vì có 7 robots màu đỏ và 5 robots màu xanh còn lại.

[Rules]
- Tất cả robot di chuyển vs cùng 1 tốc độ
- kích thước ma trận 100x100
- input:
N -> số testcase
1 -> tên testcase
100x100 ->> data
2
100x100
...
- 0: là khoảng trống
- 1: là robot màu xanh
- 2: là robot màu dỏ


Yêu cầu: In ra số lượng robot còn lại trên ma trận
#1 12


Output 3 testcases đầu:

#1 598
#2 622
#3 597