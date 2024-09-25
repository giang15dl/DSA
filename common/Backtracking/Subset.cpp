#include <iostream>

#define MAX_N 1000

// Dãy N phần tử
int N = 3;
int arr[] = {11, 22, 33};
int K;

void printArray(int a[], int S);

// danh sách các phần tử của tập con
int output[MAX_N];

// Hàm backtrack để sinh tất cả các tập con
// i: index của phần tử đang check
// cnt: số lượng phần tử của tập con
void subset(int i, int cnt);

// Hàm backtrack để sinh tất cả các tập con có chính xác K phần tử (K <= N)
// i: index của phần tử đang check
// cnt: số lượng phần tử của tập con
void subsetWithK(int i, int cnt);

using namespace std;
int main() {
    // in tất cả tập con
    subset(0, 0);
    // in tất cả tập con có chính xác K phần tử
    K = 2;
    subsetWithK(0, 0);
    return 0;
}

void printArray(int a[], int S) {
    cout << S << endl;
    if (S > 0) {
        for (int i = 0; i < S; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
}

void subset(int i, int cnt) {
    // Một số trường hợp cắt nhánh sớm, ví dụ tổng hiện tại đã vượt qua minAnswer
    //  if (condition) {
    //  ...
    //  }

    // đã tạo xong 1 tập con, xử lý tập con
    // trong ví dụ này, in ra số phần tử và danh sách các phần tử của tập con
    if (i == N) {
        printArray(output, cnt);
        return;
    }
    // Không cho arr[i] vào tập con
    subset(i + 1, cnt);

    // Cho arr[i] vào tập con
    output[cnt] = arr[i];
    subset(i + 1, cnt + 1);
}

void subsetWithK(int i, int cnt) {
    // Một số trường hợp cắt nhánh sớm, ví dụ tổng hiện tại đã vượt qua minAnswer
    //  if (condition) {
    //  ...
    //  }

    // Đã có đủ K phần tử trong tập con
    if (cnt == K) {
        printArray(output, K);
        return;
    }

    // Trường hợp phải cho hết số phần tử còn lại trong dãy vào tập con
    if (K - cnt == N - i) {
        for (int j = i; j < N; ++j)
            output[cnt++] = arr[j];
        printArray(output, K);
        return;
    }

    // Không cần check i == N vì chắc chắn sẽ vào trường hợp trên trước

    // Không cho arr[i] vào tập con
    subsetWithK(i + 1, cnt);

    // Cho arr[i] vào tập con
    output[cnt] = arr[i];
    subsetWithK(i + 1, cnt + 1);
}