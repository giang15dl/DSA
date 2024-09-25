# Blackpink View (Góc nhìn đen hồng)
>
> Level 3
>
> TEST 09/08/2023

Có 1 khu biệt thự có kích thước 100x100 tòa nhà

Mỗi ô là 1 tòa nhà, có chiều cao x

Tại mỗi tầng, có thể mở cửa theo 4 hướng trái, phải, trên dưới.
1 tầng được gọi là Góc nhìn đen hồng (Blackpink View) nếu tất cả 4 hướng đều không bị chặn bởi 2 tòa nhà khác.
Nếu tòa nhà được đặt ở cạnh của khu biệt thự thì hướng không có tòa nhà sẽ được coi là đường đi và đường đi có số tầng là 0

Ví dụ: 

tòa nhà vị trí (2,2) được đánh số 21, có nghĩa là tòa nhà này có 21 tầng, 2 tòa bên phải lần lượt là 5, 11 tầng, 2 tòa bên trái là 8,9 tầng.
2 tòa bên trên là 16 và 8 tầng, và 2 tòa bên dưới là 19 và 8 tầng.

Vì vậy tòa nhà tại ví trí (2,2) có 2 tầng có Blackpink View

Tại góc trên bên trái, tòa nhà có 19 tầng - bên phải tòa nhà này có 2 tòa nhà 5 và 16 tầng, bên dưới là 12 và 8 tầng. Vì vậy tòa nhà này có 3 tầng là Blackpink View

19	5	16	20	9
12	7	8	21	8
8	9	21	5	11
5	6	19	17	10
15	15	8	7	13


Yêu cầu: In ra số lượng tầng có Blackpink View

Input: 50 TC
50 -> số testcase
1 -> tc số 1
100 dòng tiếp theo là dữ liệu của 1 test case
