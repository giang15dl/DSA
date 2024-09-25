# Tuần trăng mật
>
> Level 4

Đám cưới anh Uranus diễn ra rất vui vẻ, chỉ có Tomoky là có chút hậm hực. Sau đám cưới, anh Uranus muốn đi tuần trăng mật ở thành phố Đà Lạt xinh đẹp.

Thành phố Đà Lạt gồm n điểm du lịch trọng điểm, được đánh số từ 1 tới n. Hệ thống giao thông trong vùng gồm m (m <= n*(n-1)) tuyến đường một chiều khác nhau, tuyến đường thứ j (j = 1,2,…m) cho phép đi từ địa điểm u_j tới địa điểm v_j với chi phí đi lại là số nguyên dương c(u_j, v_j).

Anh Uranus muốn xuất phát từ điểm du lịch 1 và đi thăm k địa điểm du lịch s_1, s_2, ..., s_k (khác địa điểm 1) và sau đó quay về địa điểm xuất phát 1 với tổng chi phí là nhỏ nhất.

Cho thông tin về hệ thống giao thông và k địa điểm du lịch s_1, s_2, ..., s_k. Hãy giúp anh Uranus xây dựng một hành trình du lịch xuất phát từ địa điểm du lịch 1 và đi thăm k địa điểm s_1, s_2, …, s_k sau đó quay về địa điểm du lịch 1 với tổng chi phí nhỏ nhất.

## Input

- Dòng đầu tiên chứa số nguyên dương T là số bộ test. Mỗi bộ test gồm:
- Dòng thứ nhất chứa 3 số nguyên n, m, k (n <= 1000 và k <= 15).
- Dòng thứ hai chứa k số nguyên dương s_1, s_2, …, s_k.
- Dòng thứ j trong m dòng tiếp theo chứa 3 số nguyên dương u_j, v_j, c(u_j, v_j) cho biết thông tiên về tuyến đường thứ j. Biết rằng u_j luôn khác v_j, và c(u_j, v_j) <= 10^9.

```
1
6 8 2
2 5
1 2 4
2 4 2
4 3 3
3 1 4
4 1 5
3 5 5
5 3 1
5 6 7
```

## Output

In ra một số nguyên là tổng chi phí nhỏ nhất tìm được.
Nếu không tìm được một hành trình du lịch nào, in ra số -1.

```
Case #1
19
Case #2
57
```