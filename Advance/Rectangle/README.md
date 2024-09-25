# Hình chữ nhật
>
> Level ?
>
> TEST 10/08/2023

- Cho ma trận 100x100, tìm kiếm có bao nhiêu hình chữ nhật thỏa mãn

- Kích thước nhỏ nhất của 1 HCN đúng là 3x3, 
tức luôn có 1 số 0 được bao quanh bởi số 1.
Ví dụ:
1 1 1  -> valid
1 0 1
1 1 1

1 1 1 -> invalid 
0 0 0

1 1 1 1 -> Invalid
1 0 0 1
1 0 0 0
1 0 0 1
1 1 1 1

Input: gồm 10 testcase
1 -> tên testcase
ma trận 100x100
[Rule]
- 10 test case
- ma trận 100x100
- Tìm các HCN được tạo thành bởi số 1
- Sẽ không có 2 HCN chồng lên nhau, hoặc 2 HCN lồng nhau

Output 2 testcases đầu

Output
#1 82
#2 76