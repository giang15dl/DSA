# Hugo Đếm Vùng
>
> Level 4

Cho ma trận `NxN` (`5 <= N <= 100`) chứa các phần tử có giá trị 0 – 5 mô tả lãnh thổ 6 vương quốc.
Yêu cầu sáp nhập các vùng số 0 về các lãnh thổ khác sao cho vùng đồng nhất có diện tích lớn nhất
(các vùng được chuyển đổi trước không được tính vào diện tích để quyết định các vùng chuyển đổi sau),
sau đó trả về số lượng vùng còn lại sau khi sáp nhập.

![Picture1](./Picture1.png)

Thông thường, chúng ta có thể thấy rõ rằng có hai ô 5, hai ô 4, một ô 3  và hai ô 2 gian hàng xung quanh ba ô 0 này.
Tuy nhiên, vì ô 5 cũng kết nối với ô khác cùng loại (ô 5, tại vị trí [1,1] và [4,1] với màu xanh lam), diện tích sẽ trở lên tốt hơn, vì vậy chúng tôi coi tần suất của ô 5 là 4.
Trong trường hợp có nhiều hơn một loại ô có cùng tần suất cao nhất, chúng tôi sẽ chọn ô có giá trị cao hơn.

![Picture2](./Picture2.png)

Tiếp tục với ô 0 tiếp theo ta có ma trận bên dưới

![Picture3](./Picture3.png)

Tất cả các Ô cùng loại và cạnh nhau (trên / dưới/ trái / phải) kết nối thành một khu vực.

![Picture4](./Picture4.png)

Ở ví dụ này chúng ta có 11 vùng

## Input

- Số lượng test case `T` (`T <= 50`)
- Kích thước ma trận `N` (`5 <= N <= 100`)
- Chi tiết ma trận được cho trong N hàng tiếp theo, Giá trị của mỗi ô có giá trị `C` (`0 <= C <= 5`)

```
5
5
5 5 1 4 4  
4 0 2 4 2  
5 0 0 2 0
5 4 3 0 1
1 3 3 2 1
7 
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
5 0 5 0 5 0 5
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
10
1 3 5 1 4 0 0 4 2 1
1 1 2 1 1 0 5 0 2 1
5 0 2 0 4 4 4 0 1 1
0 2 2 4 0 5 4 2 1 3
1 1 2 2 2 3 3 2 1 1
5 1 1 2 0 3 3 2 2 1
3 1 1 1 0 0 1 2 2 5
3 1 4 1 2 0 4 0 0 5
4 0 3 3 1 3 3 0 0 1
5 0 3 1 4 3 3 1 2 3
...
```

## Output

Xuất ra số lượng vùng sau khi đổi các vùng số 0

```
Case #1
11
Case #2
1
Case #3
31
...
```
 

## Constraint

- Tất cả các ô số 0 cạnh nhau (trên/dưới/trái/phải) được tính là 1 khu vực.
- Chỉ có 6 loại ô từ : 0 - 5, ô sô 0 cần được thay đổi thành các số khác từ (1-5)
- Chúng tôi đảm bảo sẽ không có trường hợp nào trong đó tất cả các ô bằng không
- Tất cả các loại ô giống nhau nằm xung quanh nhau được coi là một khu vực.
- Time limit : 3s for 50 TC ( C, C++ 3000 msec, Java 6000 msec)