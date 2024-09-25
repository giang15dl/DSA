# Vinaphone MobiphonevViettel
>
> TEST 10/08/2023

Yêu cầu: Tìm ra số ngôi nhà không bị phủ sóng bởi các cột sóng của các nhà mạng

Mạng Vinaphone: ký hiệu là A: chỉ phủ sóng được 1 ô mỗi hướng: trái phải trên dưới
Mạng Mobiphone: ký hiệu là B: chỉ phủ sóng được 2 ô mỗi hướng: trái phải trên dưới
Mạng Viettel: ký hiệu là C: chỉ phủ sóng được 3 ô mỗi hướng: trái phải trên dưới

 
	1	
1	A	1
	1	

		1		
		1		
1	1	B	1	1
		1		
		1		
			1			
			1			
			1			
1	1	1	C	1	1	1
			1			
			1			
			1			

Viết chương trình tìm số ngôi nhà không bị phủ sóng bởi các trạm phát sóng

[Rule]

Mảng 2 chiều NxN kích thước không quá 100.
Đảm bảo rằng nhà và trạm phát sóng không nằm trên cùng 1 ô


[Input]
T -> số test case
N -> kích thước ma trận NxN

Ví dụ:
1
9
X X X X X X X X X 
X X X H X X X X X 
X X H A H X X H X 
X X H H X X X X X 
X X X X X X X X X 
X X A H H X X X X 
X X H X X H A H X 
X X A H X X H X X 
X X H X H X X X X 

[Output]
#1 4


Output 3 testcases đầu:

Output
#1 4
#2 5
#3 8
#4 10
#5 150