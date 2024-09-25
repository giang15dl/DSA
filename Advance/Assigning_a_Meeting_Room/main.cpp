#include <iostream>
using namespace std;

const int LIM = 500; // should be 500

int solve(int (&interval)[LIM][2], int N);

bool compare(const int a[2], const int b[2]);

void sort_by_second_inplaced(int (&arr)[LIM][2], int N);

void swap(int (&a)[2], int (&b)[2]);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int interval[LIM][2] = {};

        for (int i = 0; i < N; i++) {
            int index;
            cin >> index;
            cin >> interval[i][0] >> interval[i][1];
        }

        int ans = solve(interval, N);
        cout << "Case #" << t + 1 << endl;
        cout << ans << endl;
    }

    return 0;
}

int solve(int (&interval)[LIM][2], int N) {
    sort_by_second_inplaced(interval, N);

    int end = interval[0][1];
    int count = 1;

    for (int i = 1; i < N; i++) {
        if (interval[i][0] >= end) {
            end = interval[i][1];
            count++;
        }
    }

    return count;
}

void sort_by_second_inplaced(int (&arr)[LIM][2], int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (arr[j][1] > arr[j + 1][1])
                swap(arr[j], arr[j + 1]);
}

void swap(int (&a)[2], int (&b)[2]) {
    int temp[2] = {a[0], a[1]};
    a[0] = b[0];
    a[1] = b[1];
    b[0] = temp[0];
    b[1] = temp[1];
}