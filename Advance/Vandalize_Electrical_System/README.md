# Phá Hủy Hệ Thống Điện
>
> Level 4

Sau khi biết tin Eagle xây dựng hệ thống điện và ăn bớt được rất nhiều kinh phí, VenG rất tức vì khi anh xây cầu anh đã không ăn bớt được đồng nào.
Do đó anh quyết phá hệ thống điện của Eagle.

Do sợ bị phát hiện nên anh sẽ chỉ phá hệ thống điện ở trên 1 hòn đào, và anh muốn tìm hòn đảo nào sau khi phá xong thì hệ thống điện của Eagle bị chia cắt thành nhiều phần nhất.

Hãy giúp anh VenG tìm hòn đảo này.

## Input

Dòng đầu tiên ghi số bộ test `T`, không lớn hơn `100`.

Mỗi bộ test được tổ chức theo khuôn dạng sau:

Dòng đầu tiên ghi lại số tự nhiên `N` không lớn hơn 100 là số hòn đảo.

Những dòng kế tiếp ghi lại ma trận biểu diễn hệ thong mạng lưới điện, trong đó 0 được hiểu là không có đường dây điện nối giữa điểm i và j, 1 được hiểu có đường dây điện trực tiếp giữa điểm i và điểm j (`1 <= i, j <= N`).

```
2
5
0 1 1 0 0
1 0 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 1 0 0
5
0 1 1 0 0
1 0 1 0 1
1 1 0 1 1
0 0 1 0 1
0 1 1 1 0
```

## Output

Với mỗi bộ test, in ra màn hình trên một dòng một số duy nhất là hòn đảo bị phá hủy hệ thống điện thỏa mãn yêu cầu bài toán (nếu có nhiều đảo cùng thỏa mãn yêu cầu thì in ra đảo có giá trị nhỏ nhất).
Nếu không thể chia cắt được hệ thống điện, hãy in ra số 0.

```
3
0
```
