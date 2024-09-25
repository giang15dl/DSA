# Interstellar
>
> Level 4
>
> Thời gian thực thi : 5 giây cho C/C++/JAVA, 15 giây cho Python với tối đa 50 phép thử
>
> Bộ nhớ : tối đa 256MB cho tổng cộng các vùng nhớ heap, global, và static (Lưu ý rằng chỉ có tối đa 1MB cho vùng stack)
>
> Số lần nộp bài : 10 lần
> Tiêu chuẩn đánh giá : Số lượng phép thử trả lời đúng
 
---
 
Kỷ nguyên của việc di chuyển trên vũ trụ rộng lớn bằng cách sử dụng hố đen đã đến. Samsung Electronics đang xây dựng một hệ thống di chuyển tự động sẽ được nạp vào tàu vũ trụ.
 
Tất cả vị trí trong vũ trụ được cho bởi tọa độ 2 chiều `(X, Y)`.
Tàu vũ trụ chỉ có thể di chuyển theo hướng song song với trục `X` hoặc trục `Y` và mất 1 giây để di chuyển khoảng cách 1 đơn vị.

Do đó, thời gian mà tàu vũ trụ cần để di chuyển từ tọa độ $(x_1, y_1)$ tới $(x_2, y_2)$ được tính như sau:

$$ time = |x_2 - x_1| + |y_2 - y_1|$$
 

Có tất cả `N` hố đen trong không gian.
`Ki` là thời gian để di chuyển qua mỗi hố đen, mỗi hố đen có `Ki` khác nhau.
Và hố đen cho phép di chuyển theo 2 chiều.
Để thuận tiện, 2 lối vào của hố đen được gọi là Cổng A và Cổng B.
 
- Không bắt buộc phải sử dụng tất cả hố đen để di chuyển tới điểm đích. Cũng có thể không cần dùng đến bất kì hố đen nào trong quá trình di chuyển.
- Cũng không bắt buộc phải di chuyển qua hố đen mặc dù tàu vũ trụ gặp một cổng của hố đen đó.

Cho thông tin về điểm bắt đầu và điểm đích (tọa độ) của tàu vũ trụ và thông tin về mỗi hố đen, hãy tìm thời gian ngắn nhất để di chuyển từ điểm bắt đầu tới điểm đích.

## Giới hạn

1. Số lượng hố đen `N` lớn hơn hoặc bằng 0 và nhỏ hơn hoặc bằng 5 (`0 <= N <= 5`).
2. Thời gian để di chuyển qua một hố đen `Ki` lớn hơn hoặc bằng 0 và nhỏ hơn hoặc bằng 3,000. (`0 <= Ki <= 3,000`)
3. `X`, `Y`, tọa độ trong vũ trụ lớn hơn hoặc bằng 0 và nhỏ hơn hoặc bằng 1,000. (`0 <= X, Y <= 1,000`)
4. Không có trường hợp nào mà tọa độ của điểm bắt đầu, điểm đích của tàu vũ trụ và tọa độ của những hố đen giống nhau.
 

## Input

Dòng đầu tiên của là số lượng phép thử T.

Từ dòng tiếp theo là thông tin về mỗi phép thử.

Dòng đầu tiên của mỗi phép thử là số lượng hố đen N.

Dòng thứ 2 là điểm bắt đầu [x1, y1] và điểm đích [x2, y2] của tàu vũ trụ.

Từ dòng thứ 3 tới dòng thứ `N+1`` là thông tin về mỗi hố đen.

Tọa độ [x, y] của Cổng A và [x, y] của Cổng B của mỗi hố đen, và thời gian để di chuyển qua hố đen.

```
5
0
0 0 60 60
1
0 0 2 0
1 0 1 2 0
1
0 0 60 60
40 40 20 20 10
2
100 50 10 5
80 40 10 6 10
80 10 70 40 5
3
500 500 1000 1000
501 501 999 999 1000
1 1 499 499 100
1000 999 0 0 200
1
252 854  366 380
242 449  680 162 1259
```

## Output

In `#T` cho phép thử thứ `T`, tiếp theo là một khoảng cách và in câu trả lời (`T` là số thứ tự của phép thử bắt đầu từ 1).

```
#1 120
#2 2
#3 90
#4 41
#5 305
```

