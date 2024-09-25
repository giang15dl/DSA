#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N_MAX = 16;
const int M_MAX = 3000;
const int SIZE = 100000;

// Find maximum value of an array, but do not exceed the limit.
int find_max(int (&arr)[SIZE], int n, int limit);

int find_max_capacity(int (&arr)[N_MAX], int n, int limit);

int solve(int (&arr)[N_MAX], int n, int limit);

int backtracking(int (&arr)[N_MAX], int n, int limit, int i = 0, int sum = 0);

void backtracking_inplaced(int (&arr)[N_MAX], int n, int limit, int &ans, int i = 0, int sum = 0);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int ti = 1; ti <= T; ++ti) {
        int capacity, cows;
        cin >> capacity >> cows;

        int weights[N_MAX] = {};
        for (int i = 0; i < cows; i++)
            cin >> weights[i];

        cout << "#" << ti << " " << solve(weights, cows, capacity) << endl;
    }
    return 0;
}

int solve(int (&arr)[N_MAX], int n, int limit) {
    int ans = 0;
    // ans = backtracking(arr, n, limit);
    // ans = find_max_capacity(arr, n, limit);
    backtracking_inplaced(arr, n, limit, ans);
    return ans;
}

int backtracking(int (&arr)[N_MAX], int n, int limit, int i, int sum) {
    if (sum > limit)
        return 0;
    if (i == n)
        return sum;

    int s1 = backtracking(arr, n, limit, i + 1, sum + arr[i]);

    int s2 = backtracking(arr, n, limit, i + 1, sum);

    return (s1 > s2) ? s1 : s2;
}

void backtracking_inplaced(int (&arr)[N_MAX], int n, int limit, int &ans, int i, int sum) {
    if (sum > limit)
        return;

    if (i == n) {
        if (sum > ans)
            ans = sum;
        return;
    }

    sum += arr[i];
    backtracking_inplaced(arr, n, limit, ans, i + 1, sum);
    sum -= arr[i];
    backtracking_inplaced(arr, n, limit, ans, i + 1, sum);
}

int find_max_capacity(int (&arr)[N_MAX], int n, int limit) {
    int cummcumulative_sum[SIZE] = {};

    int index = 0;
    for (int i = 0; i < n; i++) {
        cummcumulative_sum[index] = arr[i];
        index++;
        for (int j = index - 2; j >= 0; j--) {
            cummcumulative_sum[index] = arr[i] + cummcumulative_sum[j];
            index++;
        }
    }

    return find_max(cummcumulative_sum, index, limit);
}

int find_max(int (&arr)[SIZE], int n, int limit) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max && arr[i] <= limit)
            max = arr[i];

    return max;
}