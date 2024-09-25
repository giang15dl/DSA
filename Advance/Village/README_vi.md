# Làng mạc
>
> Level: 3

Cho bản đồ mạng lưới giao thông giữa các làng mạc.
Một vùng được định nghĩa là một tập hợp các làng mà từ bất kỳ một làng nào trong vùng đều có thể đi đến một làng khác trong vùng.

Hãy tính số vùng trong bản đồ, số làng cô lập
(làng không có đường đi đến bất kỳ làng khác)
và số con đường đóng vai trò là "Cầu" giữa hai vùng
(nếu bỏ con đường này đi thì số lượng vùng tăng lên 1).

## Input

Dòng đầu có một số `T` là số lượng test của file input.

Mỗi test được bố cục như sau: dòng đầu là một số nguyên dương `N` (`N <= 300`) là số làng, tiếp theo là một ma trân `A[i, j]` trong đó `A[i][j]` có giá trị bằng 1 là có đường đi từ làng `i` tới làng `j` và 0 nếu không có đường từ làng i tới làng j.

Dữ liệu đảm bảo nếu có đường từ làng i tới làng j thì cũng sẽ có đường ngược lại.

```
2
5
0 1 0 1 0
1 0 0 1 0
0 0 0 0 1
1 1 0 0 0
0 0 1 0 0
7
0 0 0 1 0 0 1
0 0 0 1 0 0 0
0 0 0 0 1 0 0
1 1 0 0 0 0 1
0 0 1 0 0 0 0
0 0 0 0 0 0 0
1 0 0 1 0 0 0
```

## Output

Với mỗi test, in ra số vùng có trên bản đồ, số làng cô lập và số đường đóng vai trò là cầu.

```
2 0 1
3 1 2
```
