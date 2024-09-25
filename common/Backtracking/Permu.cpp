#include <iostream>

#define MAX_N 1000

// Dãy N phần tử
int N = 4;
int arr[] = {11, 22, 33, 44};

// In mảng a với kích thước S
void printArray(int a[], int S);

// danh sách các phần tử của chỉnh hợp (partial permutation)
int output[MAX_N];

// visited[i] = true nghĩa là arr[i] đã được đưa vào chỉnh hợp và ngược lại
bool visited[MAX_N];

int K;
// Hàm backtrack để sinh tất cả chỉnh hợp chập K của N phần tử
//  Hoán vị là chỉnh hợp chập N của N, muốn in tất cả hoán vị của N phần tử thì cho K = N
// i: index của phần tử đang check
// cnt: số lượng phần tử đã được đưa vào chỉnh hợp
void permutation(int i, int cnt);

using namespace std;
int main() {
    for (int i = 0; i < N; ++i)
        visited[i] = false;
    // In tất cả chỉnh hợp chập 2 của dãy
    K = 2;
    permutation(0, 0);
    cout << endl;

    // In tất cả hoán vị của dãy
    K = N;
    permutation(0, 0);
    return 0;
}

void printArray(int a[], int S) {
    for (int i = 0; i < S; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void permutation(int i, int cnt) {
    // Một số trường hợp cắt nhánh sớm, ví dụ tổng hiện tại đã vượt qua minAnswer
    //  if (condition) {
    //  ...
    //  }

    // Đã có đủ K phần tử được đưa vào chỉnh hợp
    if (cnt == K) {
        printArray(output, K);
        return;
    }

    for (int j = 0; j < N; ++j) {
        // Nếu arr[j] chưa được đưa vào chỉnh hợp, thử đưa vào và đệ quy với phần tử tiếp theo
        if (!visited[j]) {
            visited[j] = true;
            output[cnt] = arr[j];
            permutation(i + 1, cnt + 1);
            visited[j] = false;
        }
    }
}