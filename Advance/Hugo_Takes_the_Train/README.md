# Hugo Đi Tàu
>
> Level 4

Trên một con tàu có `N` vị trí ngồi, Có 3 cửa để lên tàu.
Hành khách đang đợi ở mỗi cửa là khác nhau.

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí| | | | | | | | | |  |
|Khoảng cách| | | | | | | | | |  |
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Để tránh xung đột và rối loạn, hành khách lên tàu cần thực hiện như sau:
1. Chỉ 1 cửa được mở tại một thời điểm, khi cửa mở tất cả hành khách sẽ được lên tàu.
2. Khi cửa mở, lần lượt hành khách sẽ được lên tàu, và hành khách sẽ đi tới vị trí trống gần nhất từ vị trí cửa
    - Khoảng cách từ cửa tới vị trí ngồi đối diện cửa là 1m. (Vị trí ngồi tại vị trí cửa)
    - Khi hành khách đi xa hơn một vị trí (sang trái hoặc sang phải), sẽ mất thêm 1m

Ví dụ: Vị trí cửa là 4, khoảng cách đến vị trí ngồi 4 là 1m, đến vị trí ngồi 3, 5 là 2m

3. Nếu có 2 vị trí ngồi trống gần nhất, hành khách có thể chọn bất kỳ chỗ nào (Bạn cần xem xét trường hợp này).
4. Sau khi 1 cửa được mở và hành khách đã lên tàu hết thì tiếp tục mở cửa tiếp theo cho hành khách lên tàu theo cách bên trên

**Bạn cần tìm cách để tổng khoảng cách tất cả hành khách di chuyển là nhỏ nhất và viết ra...**

## Example

Trong bảng bên dưới :

- Số lượng vị trí ngồi của tàu là : 10
- Cửa 1 : vị trí là 4, Số hành khác đang chờ lên tàu là 5
- Cửa 2 : vị trí là 6, Số hành khách đang chờ lên tàu là 2
- Cửa 3 : vị trí là 10, Số hành khách đang chờ lên tàu là 2

### Trường hợp 1: Chúng ta mở các cửa theo thứ tự : Cửa 1 > Cửa 2 > Cửa 3

Khi cửa  1 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí| |<span style="color:green">G1</span>|<span style="color:green">G2</span>|<span style="color:green">G3</span>|<span style="color:green">G4</span>|<span style="color:green">G5</span>| | | |  |
|Khoảng cách| |3|2|1|3|2| | | |  |
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  2 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí| |<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>| |  |
|Khoảng cách| |3|2|1|3|2|2|3| |  |
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  3 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí| |<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|<span style="color:red">G3</span>|<span style="color:red">G3</span>|
|Khoảng cách||3|2|1|3|2|2|3|2|1|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Trong trường hợp này tổng khoảng cách hành khách di chuyển là : `3+2+1+2+3+2+3+2+1=19`

### Trường hợp 2: Chúng ta mở cửa theo thứ tự : Cửa 2 > Cửa 1 > Cửa 3

Khi mở cửa 2, hành khách đầu tiên sẽ chọn vị trí số 6, hành khách thứ 2 có thể chọn vị trí số 5 hoặc 7

||`   5   `|`   6   `|`   7   `|
|:---:|:---:|:---:|:---:|
|Vị trí||<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|
|Khoảng cách||1|2|
| | |<span style="color:yellow">Cửa 2</span>| |

Hoặc

||`   5   `|`   6   `|`   7   `|
|:---:|:---:|:---:|:---:|
|Vị trí|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>||
|Khoảng cách|2|1||
| | |<span style="color:yellow">Cửa 2</span>| |

#### Trường hợp 2.1

Khi cửa  2 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu (hành khách thứ 2 chọn vị trí số 5)

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí|||||<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|
|Khoảng cách|||||2|1|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  1 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|<span style="color:green">G1</span>|
|Khoảng cách|4|3|2|1|2|1|4|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  3 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|<span style="color:green">G1</span>||<span style="color:red">G3</span>|<span style="color:red">G3</span>|
|Khoảng cách|4|3|2|1|2|1|4||2|1|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Trong trường hợp này, tổng là : `4+3+2+1+2+1+4+2+1=20`

#### Trường hợp 2.2

Khi cửa  2 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu (hành khách thứ 2 chọn vị trí số 7)

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí||||||<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|
|Khoảng cách||||||1|2|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  1 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>|
|Khoảng cách|4|3|2|1|2|1|2|
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Khi cửa  3 mở, bảng bên dưới cho thấy khoảng cách và vị trí các hành khách khi lên tàu

| |`   1   `|`   2   `|`   3   `|`   4   `|`   5   `|`   6   `|`   7   `|`   8   `|`   9   `|`   10   `|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Vị trí|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:green">G1</span>|<span style="color:yellow">G2</span>|<span style="color:yellow">G2</span>||<span style="color:red">G3</span>|<span style="color:red">G3</span>|
|Khoảng cách|4|3|2|1|2|1|2||2|1
| | | | |<span style="color:green">Cửa 1</span>| |<span style="color:yellow">Cửa 2</span>| | | |<span style="color:red">Cửa 3</span>|

Trong trường hợp này, tổng là : `4+3+2+1+2+1+2+2+1=18`

## Input

- Dòng đầu tiên chứa số trường hợp thử nghiệm `T` (`T <= 50`)
- Mỗi trường hợp thử nghiệm:
    - Dòng đầu tiên chưa số ghế trên tàu `N` (`10 <= N <= 60`)
    - 3 dòng tiếp theo chưa thông tin của 3 cửa lên tàu :
        - Vị trí cửa `P` (`1 <= P <= N`)
        - Số lượng hành khách đang chờ ở cửa `C` (`1 <= C <= 20`)

```
5
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16
```

## Output

In ra tổng di chuyển nhỏ nhất của tất cả các hành khách

```
Case #1
18
Case #2
25
Case #3
57
Case #4
86
Case #5
339
```