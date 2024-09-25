# Settlers of Catan
>
> Level 4

Settlers of Catan, một trò chơi của người Đức ở năm 1995, người chơi tham gia vào cuộc cai trị một hòn đảo bằng việc xây dựng các con đường, các khu định cư, và các thành phố qua các vùng hoang dã chưa được thám hiểm.

Bạn được một công ty phần mềm thuê để phát triển một phiên bản máy tính cho trò chơi này, và bạn được chọn để xây dựng một trong các luật đặc biệt của trò chơi.

Khi trò chơi kết thúc, người chơi mà xây dựng được con đường dài nhất sẽ được thêm 2 điểm thắng cuộc.

Vấn đề gặp phải ở đây là người chơi thường xây dựng các mạng lưới con đường rất phức tạp và không chỉ theo một đường tuyến tính. Vì lý do đó, việc xác định con đường dài nhất không phải đơn giản (mặc dù những người chơi thường có thể thấy ngay lập tức).

Đối chiếu tới trò chơi gốc, chúng ta sẽ giải quyết một vấn đề đơn giản ở đây: Bạn được cho trước một tập các nodes (thành phố) và một tập các cạnh (các đoạn đường) có chiều dài là 1 kết nối các nodes.

Con đường dài nhất được định nghĩa như là đường đi dài nhất trong mạng lưới đường mà không có cạnh nào được dử dụng hai lần. Dù vậy, các nodes có thể được thăm hơn một lần.

Ví dụ: Mạng lưới sau đây chứa một con đường dài nhất là 12.

## Input

Input sẽ chứa một hoặc nhiều test cases.

Dòng đầu là số lượng test case T.

Dòng đầu tiên của mỗi test cases chứa 2 số nguyên: số nodes N (2<=N<=25) và số cạnh M (1<=M<=25). M dòng tiếp theo miêu tả M cạnh. Mỗi cạnh được cho bởi các số node kết nối với nhau. Các node được đánh số từ 0 -> N-1. Các cạnh không có hướng. Các node có bậc là 3 hoặc nhỏ hơn. Mạng lưới không cần thiết phải được kết nối thông suốt với nhau.

```
3
15 16
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
7 9
8 10
9 11
10 12
11 12
10 13
12 14
3 2
0 1
1 2
15 16
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
7 9
8 10
9 11
10 12
11 12
10 13
12 14
```

## Output

Với mỗi test case, in ra chiều dài của con đường dài nhất trên một dòng.

````
12
2
12
```
