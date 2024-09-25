#include <iostream>

const int N = 10;

int solve(int (&arr)[N], int n);
int backtracking(int (&arr)[N + 2], int n, int left, int right);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n;
        cin >> n;
        int balloons[N];
        for (int ni = 0; ni < n; ni++)
            cin >> balloons[ni];

        cout << "Case #" << ti + 1 << endl;
        cout << solve(balloons, n) << endl;
    }

    return 0;
}

int solve(int (&arr)[N], int n) {
    int new_arr[N + 2];
    new_arr[0] = 1;
    new_arr[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        new_arr[i] = arr[i - 1];

    return backtracking(new_arr, n + 1, 0, n + 1);
}

int backtracking(int (&arr)[N + 2], int n, int left, int right) {
    int max_score = 0;
    for (int i = left + 1; i < right; i++) {
        // to permute through all cases
        int score = backtracking(arr, n, left, i) + backtracking(arr, n, i, right);
        if (left == 0 && right == n)
            score = score + arr[i];
        else
            score = score + (arr[left] * arr[right]);

        if (score > max_score)
            max_score = score;
    }
    return max_score;
}
