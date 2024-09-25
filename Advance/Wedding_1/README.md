# Mời đám cưới

> Level 4

Anh Uranus sắp tổ chức đám cưới, hôm nay anh muốn đi phát thiệp mời đến những người bạn trong team.
Thấy Uranus đi mời cưới nên Tomoky giả vờ đi ra ngoài có việc để trốn.
Uranus rất tức và quyết tâm tìm được Tomoky để mời.

Giả sử đường đi trong công ty tạo thành 1 đồ thị và, giữa hai điểm bất kỳ đều tồn tại đường đi trực tiếp hoặc gián tiếp thông qua một số điểm trung gian.

Do hỏi anh VenG nên anh Uranus biết trước điểm bắt đầu và điểm kết thúc trên đường đi của Tomoky, nhưng anh lại không biết Tomoky sẽ đi đường nào, do đó anh muốn tìm những điểm mà anh Tomoky bắt buộc phải đi qua trong hành trình của mình (trừ điểm đầu và điểm cuối)

Hãy giúp anh Uranus tìm số điểm bắt buộc phải đi qua trên đường đi của anh Tomoky.

## Input

Dòng đầu tiên chứa số nguyên dương không lớn hơn 100 là số lượng các bộ dữ liệu.
Các dòng tiếp theo chứa các bộ dữ liệu.Mỗi bộ dữ liệu gồm một nhóm dòng theo khuôn dạng:

- Dòng 1 chứa 4 số nguyên `N, M, u, v` (`u, v, N <= 100; M <= 1000`).
  Trong đó `N` là số lượng đỉnh trên đồ thị.
  `M` là số đường đi... `u`, `v` lần lượt là đỉnh bắt đầu và đỉnh kết thúc hành trình của anh Tomoky.
- `M` dòng sau, mỗi dòng ghi hai số i, j cách nhau một khoảng trống cho biết có đường nối trực tiếp giữa i với j (1 <= i, j <= N).

```
2
5 7 1 3
1 2
2 4
2 5
3 1
3 2
4 3
5 4
4 5 1 4
1 2
1 3
2 3
2 4
3 4
```

## Output

Với mỗi bộ dữ liệu, đưa ra màn hình một số nguyên là số lượng đỉnh bắt buộc phải đi qua khi đi từ u,v.

```
2
0
```
