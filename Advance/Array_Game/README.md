# Array Game
>
> Level 4

Có 1 trò chơi với dãy gồm `N` số như sau

Mỗi bước đi bạn phải chia mảng thành 2 phần không rỗng sao cho tổng các phần tử bên trái bằng tổng phần tử bên phải.
Nếu chia được bạn sẽ được 1 điểm, nếu không chia được trò chơi kết thúc.

Sau mỗi lần chia thành công, bạn phải bỏ 1 trong 2 phần đã chia và tiếp tục trò chơi với phần còn lại.

Cho 1 dãy, hỏi số điểm nhiều nhất mà bạn có thể thu được là bao nhiêu

## Input

Dòng đầu tiên là số lượng test case `T` (`T = 20`).

Dòng đầu tiên của mỗi test case là `N` (`N = 20,000`) là số lượng phần tử của dãy.
Dòng tiếp theo là `N` phần tử của dãy đó.

```
3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1
```

## Output

Mỗi test case in ra số điểm nhiều nhất mà có thể thu được


```
0
2
3
```