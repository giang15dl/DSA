# Tiết kiệm điện
>
> Level 4

Văn phòng APS hiện tại đang có N bóng đèn và có K khóa. Các khóa được nối vào các bóng đèn theo quy luật như sau:

Khóa thứ K sẽ được nối vào các bóng đèn thứ K+n(K+1) (n>=0; 0<=K+n(K+1)< =N).

Ví dụ:

Khóa thứ 1 sẽ nối vào các bóng đèn số 1, 3, 5, 7,9...

Khóa thứ 2 sẽ nối vào các bóng đèn số 2, 5, 8, 11,...

Khóa thứ 3 sẽ nối vào các bóng đèn số 3, 7, 11, 15,...

Nếu khóa thứ k được thay đổi trạng thái, tất cả các bóng đèn đang nối với khóa k sẽ chuyển trạng thái (Bật->Tắt, tắt->bật).

Có một quy định được ban hành trong APS P: Nhân viên rời văn phòng cuối cùng phải có trách nhiệm tắt đèn trong văn phòng sao cho số lượng bóng đèn được tắt là lớn nhất. Tuy nhiên để thử thách tư duy của các nhân viên, nhân viên rời văn phòng cuối đó chỉ được phép thay đổi trạng thái khóa tối đa 3 lần, mỗi lần được chọn tối đa 1 khóa.

Hãy tạo một chương trình giúp các nhân viên tìm ra phương án tối ưu để tắt đèn với tối đa 3 lần tác động vào khóa^.^

Input:

Dòng 1 chứa số T là số TC.

Mỗi testcase bao gồm các thông tin sau:

-        Dòng đầu tiên chứa số lượng bóng đèn N và số Khóa K (10<=N<=100, 3<=K<=10);

-        Dòng tiếp theo là N bóng đèn, mỗi bóng đèn nhận 1 trong 2 trạng thái: 1 là bật, 0 là tắt.

OutPut:

In ra số lượng bóng đèn tối đa có thể tắt tại mỗi case.

Đáp số của mỗi TC in ra trên 1 dòng theo định dạng:

# TC Answer

Ví dụ:

Input

1

10 3 (10 bóng đèn và 3 khóa)

0 0 1 1 1 1 0 0 1 0 (lần lượt là 10 trạng thái của 10 bóng đèn, 1 là đang bật, 0 là đang tắt)

Output:

#1 6

Giải thích: Chọn tác động vào công tắc thứ 1, các bóng đèn sau sẽ bị thay đổi trạng thái:1 3 5 7 9

|Stt bóng đèn               |1|2|3|4|5|6|7|8|9|10|
|---------------------------|-|-|-|-|-|-|-|-|-|--|
|Ban đầu                    |0|0|1|1|1|1|0|0|1|0 |
|Sau khi tác động vào khóa 1|1|0|0|1|0|1|1|0|0|0 |

