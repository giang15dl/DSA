# Năng Lượng Vũ Trụ
>
> Level 4

Vào năm 2900, khoa học kỹ thuật phát triển, con người có thể sinh sống trên nhiều hành tinh khác nhau.

Do nhu cầu sử dụng năng lượng tăng cao, 
năng lượng trên mỗi hành tinh không còn đủ để đáp ứng,
vì vậy, một bước đột phá khoa học năng lượng,
con người có thể khai thác nguồn năng lượng lớn từ một ngôi sao trung tâm.

Năng lượng khai thác được từ ngôi sao trung tâm này sẽ được truyền tải đến tất cả các hành tinh,
và các hành tinh cũng có thể truyền tải qua các hành tinh khác.

Khoảng cách giữa chúng là $K$, khoảng cách càng xa, lượng hao phí năng lượng càng lớn.

Ví dụ: hành tinh số 1 cách hành tinh số 2 là $K = 1000$, thì số năng lượng hao hụt cũng sẽ là $1000$.

Vì thế, cần tối ưu hoá khoảng cách nhất có thể tới tất cả các hành tinh. (như hình dưới)

![](example.png)

Để tiếp tục giảm mức hao phí này, người ta tạo ra một máy truyền tải năng lượng,
tại mỗi hành tinh, người ta đặt một máy truyền tải năng lượng này,
có thể làm giảm đi phần lớn số hao phí, và nó tuân theo công thức của máy truyền tải:

$$K = A \cdot H^3 + B \cdot H^2 + C$$

Trong đó:

- $K$ là khoảng cách giữa 2 hành tinh
- $A$, $B$, $C$ là hằng số của máy truyền tải
- $H$ là hao phí. (Luôn dương)

Ví dụ: $K = 100$, $A = 3$, $B = 2$, $C = 1$

$$100  = 3 \cdot H^3 + 2 \cdot H^2 + 1$$

$$\Rightarrow H = 3$$

Như vậy, hao phí $H$ giữa 2 hành tinh là: 3

## Bài toán

Hãy tính tổng hao phí nhỏ nhất khi truyền tải năng lượng tới toàn bộ hành tinh.

Tất cả quá trình tính toán sẽ được làm tròn tới $10^{-6}$  sau dấu thập phân.

Kết quả in ra sẽ lấy $10^{-3}$ sau dấu thập phân.

## Giới Hạn

- Số lượng hành tinh $N \leq 50$
- Khoảng cách $K$ là số nguyên và đảm bảo rằng tổng của $K < 2^{64}$
- $A,B,C \leq 1000$ và là số nguyên

## Input

- Dòng đầu tiên $T$ biểu thị số trường hợp thử nghiệm
- Với mỗi trường hợp thử nghiệm:
  - Dòng đầu tiên gồm giá trị $N$ là số lượng hành tinh ($N_0$ là ngôi sao chủ)
  - Dòng tiếp theo là 3 số $A$ $B$ $C$
  - $N$ dòng tiếp theo là ma trận kề biểu bị khoảng cách của các hành tinh 

**Lưu ý, hành tinh không kết nối với chính nó**

```
50
3
3 2 1
0 100 100
100 0 100
100 100 0
4
10 1 4
0 452 995 613
452 0 302 173
995 302 0 309
613 173 309 0
4
9 6 2
0 351 912 720
351 0 251 107
912 251 0 941
720 107 941 0
7
1 9 9
0 604 571 668 261 511 546
604 0 435 979 223 356 602
571 435 0 842 482 759 109
668 979 842 0 972 306 438
261 223 482 972 0 988 468
511 356 759 306 988 0 601
546 602 109 438 468 601 0
7
6 6 4
0 766 956 661 962 422 999
766 0 203 784 105 890 887
956 203 0 157 409 329 460
661 784 157 0 928 733 707
962 105 409 928 0 315 817
422 890 329 733 315 0 467
999 887 460 707 817 467 0
...
```

## Output

- In `#T` cho phép thử thứ `T`, tiếp theo là một khoảng cách và in câu trả lời (T là số thứ tự của phép thử bắt đầu từ 1).

```
# 1 6.000
# 2 9.119
# 3 8.060
# 4 26.371
# 5 18.983
```