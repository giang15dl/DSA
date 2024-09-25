# Tree Set 2
>
> Level 5

Xây dựng tập `ts` có các hàm sau:

- `add x`: thêm `x` vào trong tập (nếu trong tập `ts` chưa có `x`)
- `remove x`: xóa `x` trong tập `ts` (nếu `x` có trong tập `ts`)
- `contains x`: đưa ra true nếu `x` có  trong tập `ts`, ngược lại đưa ra false
- `lower x`: đưa ra số lớn nhất mà nhỏ hơn `x` trong tập `ts`, nếu không có số nào nhỏ hơn `x` đưa ra null
- `higher x`: đưa ra số nhỏ nhất mà lớn hơn `x` trong tập `ts`, nếu không có số nào lớn hơn `x` đưa ra null
- `size`: đưa ra số lượng phần tử trong tập `ts`

## Input

Dòng đầu tiên chứa số lượng test case

Mỗi test case, dòng đầu tiên là số lượng lệnh cần thực hiện không vượt quá `105`.

Dữ liệu cho là các số nguyên không vượt quá `32 bit`

```
1
11
add 1
add 3
add 5
size
add 5
size
lower 4
lower 1
contains 5
remove 3
lower 4
```

## Output

Với mỗi test case đưa ra các kết quả của các lệnh `contains`, `lower`, `higher`, `size`.
In các kết quả trên cùng một dòng

```
#1 3 3 3 null true 1
```

