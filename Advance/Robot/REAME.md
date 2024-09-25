# Robot
>
> TEST 09/08/2023

Trong một ngôi nhà có 1 robot và robot sẽ được lập trình để đi theo các lệnh

Robot có thể đi theo các hướng và lệnh như sau:

Hướng
0: lên
1: trái
2: xuống
3: phải

Lệnh:
0: đi tiếp 1 bước
1: quay trái 90 độ
2: quay 180 độ
3: quay phải 90 độ

Tại mỗi vị trí trong ngôi nhà sẽ có giá trị >=0 tương ứng với độ bận tại ô đó

Yêu cầu: Thực hiện K lệnh và in ra số ô có độ bẩn = 0

Input:
- Dòng đầu tiên: Số test case
- Dòng thứ 2: N x y z
	Trong đó:
	N: kích thước ngôi nhà tương ứng ma trận NxN
	x,y: vị trí ban đầu của robot
	z: hướng hiện tại
- N dòng tiếp theo: ma trận NxN miêu tả ngôi nhà
	Trong đó:
	-1: tường, không thể đi vào được
	>=0 là các ô có thể đi được - tương ứng độ bẩn tại mỗi ô
- Dòng tiếp theo: K - số lệnh
- Dòng tiếp theo: liệt kê K lệnh

Ví dụ:
Input:

1
5 2 2 2 --> ma trận 5x5 - vị trí bắt đầu (2,2) - Hướng đi xuống
-1 -1 -1 -1 -1 
-1 2 2 0 -1 
-1 1 1 3 -1 
-1 1 0 1 -1 
-1 -1 -1 -1 -1  
10
0 1 0 0 2 0 0 3 0 0

Output
#1 5

Giải thích:
Robot sẽ bắt đầu tại ô (2,2) - hàng 2 - cột 2 với hướng đi xuống
5 lệnh robot sẽ đi như sau:
- Lệnh 1: 0 -> robot sẽ đi tiếp 1 ô theo hướng hiện tại - đi xuống: Robot sẽ tiến xuống ô (3,2) - độ bận tại ô (3,2) sẽ giảm đi 1 nếu ô đó chưa sạch, tuy nhiên tại ô (3,2) có giá trị 0 -> độ bẩn sẽ không đổi
- Lệnh 2: 1 -> Robot sẽ quay trái 90 độ của hướng hiện tại - Tức robot sẽ hướng sang bên phải.
- Lệnh 3: 0 -> Robot sẽ đi tiêp 1 ô theo hướng hiện tại - đi sang phải: Robot sẽ tiến sang ô (3,3) - độ bẩn tại ô (3,3) sẽ giảm đi 1. (1 -> 0)
- Lệnh 4: 0 -> Robot sẽ đi tiếp 1 ô theo hướng hiện tại - đi sang phải: Tuy nhiên ô tiếp theo là tường nên robot sẽ đứng yên tại ô (3,3)
- Lệnh 5: 2 -> Robot sẽ quay 180 độ - hướng sang bên trái
- Lệnh 6: 0 -> Robot sẽ đi tiêp 1 ô theo hướng hiện tại - đi sang trái: giảm độ bận tại ô (3, 2) nếu độ bẩn tại (3,2) > 0
- Lệnh 7: 0 -> Robot sẽ đi tiêp 1 ô theo hướng hiện tại - đi sang trái: giảm độ bận tại ô (3, 1) nếu độ bẩn tại (3,1) > 0
- Lệnh 8: 3 -> Robot sẽ quay phải 90 độ của hướng hiện tại - Tức robot sẽ hướng lên trên.
- Lệnh 9: 0 -> Robot sẽ đi tiêp 1 ô theo hướng hiện tại - đi lên trên: giảm độ bận tại ô (2, 1) nếu độ bẩn tại (2,1) > 0
- Lệnh 10: 0 -> Robot sẽ đi tiêp 1 ô theo hướng hiện tại - đi len trên:giảm độ bận tại ô (1, 1) nếu độ bẩn tại (1,1) > 0

Kết quả sau khi robot đi 10 lệnh:

-1 -1 -1 -1 -1 
-1 1 2 0 -1 
-1 0 1 3 -1 
-1 0 0 0 -1 
-1 -1 -1 -1 -1  

Sẽ có 5 ô có độ bẩn = 0

Giới hạn: 
- N <= 500, K <= 1000, 0 <= x, y < N
- Ma trận có thể có tường bao quanh hoặc không
