# Nâng cấp máy tính
>
> Level 4
>
> Time limit: 1 giây với C/C++, 2 giây với Java.
>
> Submission limit: 5 lần.
>
> Memory limit: 256MB cho tổng cộng các vùng nhớ heap, global và static (chỉ 1MB cho vùng nhớ stack).

Anh Kim có 1 máy tính đã mua từ thời sinh viên nên hiện giờ cần phải nâng cấp và thay thế `L` linh kiện để đảm bảo máy tính hoạt động tốt.

Để tìm mua được các thiết bị đó với giá tốt nhất anh Kim đã qua chợ Trời và tham khảo được giá của tất cả `N` thiết bị của máy tính.

Không chỉ thế, anh đã tìm kiếm thêm trên mạng, và anh rất vui khi có `M` gói ưu đãi giá rẻ được rao bán trên mạng, mỗi gói có giá bán là `P` bao gồm `K` thiết bị của máy tính.

Anh Kim có thể mua một hoặc nhiều gói ưu đãi và có thể mua thừa linh kiện chưa cần thay thế.

Hãy giúp anh Kim mua được đủ `L` thiết bị cần thiết với tổng giá thành là nhỏ nhất.

## Input

Dòng đầu tiên là số lượng test case `T` (`T <= 50`).

Mỗi test case gồm các thông tin sau:

- Dòng đầu tiên là số nguyên dương `N` (`1 <= N <= 20`) là số lượng thiết bị chính của máy tính.
- Dòng thứ 2 bao gồm `N` số, số thứ `i` tương ứng là giá của thiết bị thứ `i` được bán ở chợ Trời.
- Dòng thứ 3 là số nguyên dương `M` (`0 <= M <= 30`) là số lượng gói ưu đãi có trên mạng.
- `M` dòng tiếp theo, mỗi dòng thứ `i` là thông tin về gói ưu đãi thứ `i`. Số đầu tiên là giá của gói ưu đãi `P` (`1 <= P <= 1000`), số tiếp theo là số lượng thiết bị `K` (`1 <= K< = N`) trong gói ưu đãi đó, `K` số tiếp theo là các thiết bị có trong gói ưu đãi đó.
- Dòng cuối cùng của mỗi test case là thông tin về các thiết bị mà anh Kim cần mua. Số đầu tiên là số lượng thiết bị `L`, `L` số tiếp theo là các thiết bị anh Kim cần mua
- Các thiết bị được đánh số trong đoạn từ `1` đến `N` và không có số nào trùng nhau

```
1               <-- T = 1,
5               <-- Số linh kiện chính của máy tính
20 15 17 18 25  <-- giá chợ Trời của 5 thiết bị từ 1 đến 5 tương ứng
4               <-- 4 gói ưu đãi trên mạng
30 3 1 2 5      <-- gói thứ nhất có giá 30, gồm 3 linh kiện 1, 2, 5
25 2 2 3        <-- gói thứ 2 có giá 25, gồm 2 linh kiện 2, 3
35 3 1 3 5      <-- gói thứ 3 có giá 35, gồm 3 linh kiện 1, 3, 5
20 2 3 4        <-- gói thứ 4 có giá 20, gồm 2 linh kiện 3, 4
3 2 4 5         <-- Số lượng anh Kim cần là 3, lần lượt là 2, 4, 5
```

## Output

Bắt đầu mỗi test case là `#x` với `x` là số thứ tự của test case (bắt đầu từ 1), tiếp theo là một dấu cách và giá thành nhỏ nhất mà anh Kim cần bỏ ra để mua đủ những thiết bị anh cần.

```
#1  48
```

Giải thích: Để mua được 3 thiết bị 2, 4, 5 với giá rẻ nhất, ta sẽ mua gói giá rẻ 1 gồm 1, 2, 5 với giá 30 và mua thiết bị 4 ở chợ Trời với giá 18, tổng là 30 + 18 = 48.

