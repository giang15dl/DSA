# Hugo Thi Chạy
	
Sắp tới công ty nên Hugo làm việc tổ chức sự kiện Olympic dành cho toàn bộ nhân viên.
Có rất nhiều bộ môn thi đấu như Bóng bàn, cầu long, cờ vua, cờ tướng, bơi lội, và có cả thể thao điện tử nữa.
Là một người quan tâm tới sức khỏe của bản thân vì vậy Hugo thường xuyên chạy bộ để rèn luyện sức khỏe.
Thật may trong các môn thi đấu Olympic có hạng mục này.
Trong quá trình tập luyện Hugo đã luyện cho mình được 5 kiểu chạy khác nhau, mỗi kiểu chạy sẽ tiêu tốn số lượng năng lượng nhất định và thời gian chạy hết 1km là khác nhau.
Mỗi kiểu chạy sẽ sử dụng cho 1km.

Năng lượng của Hugo là có hạn, nếu sử dụng vượt Hugo sẽ bị bệnh.

Sau khi tham khảo thông tin Hugo biết được quãng đường cần chạy bộ `D` của cuộc thi.
Nhân viên y tế có thể giúp Hugo tính toán được số năng lượng tối đa của Hugo.
Cho thông tin của 5 kiểu chạy của Hugo bao gồm số phút, số giây (`số phút <= 6` và `số giây <= 60`) và số năng lượng tiêu tốn.
Hãy tính thời gian ngắn nhất để Hugo về đích mà không bị bệnh.

## Input

Dòng đầu số test `T` (`T <= 50`)

Mỗi test bao gồm 2 dòng

- Dòng 1 chứa số năng lượng tối đa `M <= 60` và chiều dài quãng đường `D <= 40km`
- Dòng thứ 2 chứa thông tin của 5 kiểu chạy lần lượt là số phút, số giây, số năng lượng tiêu tốn

```
4
297 10
5 38 23 5 22 12 4 16 6 5 38 20 0 20 17
192 10
2 6 12 6 5 24 2 22 22 4 13 12 4 30 16
503 10
1 42 20 1 8 14 0 33 15 2 6 6 5 3 16
122 10
2 37 21 3 59 22 6 0 22 4 56 5 0 9 10
```

## Output

In ra thời gian ngắn nhất để Hugo về đích mà không bị bệnh theo dạng số phút, số giây.
Nếu không thể hãy in ra `-1`
 

```
Case #1
3 20
Case #2
21 0
Case #3
5 30
Case #4
1 30
```