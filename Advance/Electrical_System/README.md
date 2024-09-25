# Hệ Thống Điện
>
> Level 4

Sau khi anh VenG đã xây dựng đường đi giữa những hòn đảo,
anh Eagle được cử sang để xây dựng hệ thống điện giữa các hòn đảo cho người dân,
do muốn ăn bớt kinh phí nên anh Eagle không xây dựng trạm phát điện trên tất cả các đảo mà chỉ xây trên 1 số đảo nhất định.
Các đảo kết nối với nhau thành 1 mạng lưới điện. Rõ ràng những đảo nào ở càng xa nguồn phát thì điện sẽ càng yếu.

Để đảm bảo người dân không than phiền điện yếu, nên anh Eagle muốn tính toán xem điện ở đảo nào sẽ yếu nhất.

Độ yếu của điện tại đảo X được tính bằng 0 nếu đảo đó có trạm phát điện.
Nếu đảo X có kết nối điện với đảo Y mà đảo Y ở gần trạm phát hơn, độ yếu tại đảo X = độ yếu tại đảo Y + 1.
Nếu đảo X không có điện thì có độ yếu bằng vô cùng (infinity).

## Input

Dòng đầu tiên chứa số testcase T.

Mỗi test case gồm:

Dòng đầu tiên gồm 3 số nguyên N, M, H lần lượt là số đảo, M là số đảo có trạm phát điện, H là số kết nối 2 chiều. (N, M <= 1 000, H <= 10 000).

Dòng tiếp theo gồm M số là ID các đảo có máy phát điện (ID đánh số từ 0 tới N-1).

H dòng tiếp theo, mỗi dòng gồm 2 số u, v, cho biết đảo u có kết nối với đảo v.

```
2
6 3 5
0 5 2
0 1
1 2
4 5
3 5
0 2
6 2 3
5 2
0 5
0 1
3 4
```

## Output

In ra đảo độ yếu của điện là cao nhất. Nếu có nhiều đáp án, in ra đảo có ID nhỏ nhất.

 
```
1
3
```