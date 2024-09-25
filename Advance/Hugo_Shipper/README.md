# Hugo Giao Hàng
>
> Level 4

Hugo đang làm việc cho công ty Samsung, tuy mức lương ở Samsung không hề nhỏ nhưng vì Hugo là lao động duy nhất trong nhà, vợ của Hugo mới sinh em bé.
Hugo muốn kiếm them thu nhập để có thể có thêm tiền sữa, bỉm cho con.
Hugo quyết định nhận giao bánh pizza ngoài giờ làm.
Mỗi ngày, sau khi tan ca Hugo sẽ nhận N chiếc bánh pizza để giao tới N địa điểm khác nhau sau đó trở về nhà.
Tuy nhiên do giá xăng dầu đang leo thang, Hugo cần phải giảm tối đang lượng xăng phải tiêu thụ, vì vậy Hugo muốn tính toán xem quãng đường đi giao bánh pizza từ công ty sau đó về nhà là ngắn nhất.
Hãy giúp Hugo với nhé.

## Input

`T` test case `T <= 50`

Dòng đầu tiên chưa 4 số `Sx, Sy, Dx, Dy` tương ứng là vị trí của công ty và nhà của Hugo trên hệ trục tọa độ Oxy

Dòng tiếp theo bao gồm số `N` và `N` cặp số liên tiếp tương ứng là tọa độ các điểm mà Hugo cần giao pizza. `N <= 10`

Cách tính khoảng cách giữa 2 điểm $(x_1, y_1)$, $(x_2, y_2)$

$$ D = |x_1-x_2| + |y_1-y_2| $$

```
1
0 0 5 5 
5 1 1 2 2 3 3 4 4 5 5
```

## Output

In ra quãng đường ngắn nhất Hugo di chuyển từ công ty để giao bánh sau đó trở về nhà.

```
Case #1 10
```