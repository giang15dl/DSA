#include <iostream>

using namespace std;

int T, n, res;
int door[20];
int people[20];
int visited[20];
int hoanvi[6][3] = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}};

void backtrack(int row, int col, int sum) {
    if (sum > res)
        return;
    if (col == 4) {
        if (sum < res)
            res = sum;
        return;
    }

    int id = hoanvi[row][col - 1];
    int posD = door[id];
    int p = people[id];

    if (visited[posD] == 0) {
        visited[posD] = col;
        p--;
        sum += 1;
    }

    int k = 1;
    int l, r;
    while (p != 0) {
        l = posD - k;
        r = posD + k;

        if (p == 1 && visited[l] == 0 && l >= 1 && visited[r] == 0 && r <= n) {
            visited[l] = col;
            p--;
            sum += 1 + k;
            backtrack(row, col + 1, sum);
            sum -= 1 + k;
            p++;
            visited[l] = 0;
            for (int i = 1; i <= n; i++) {
                if (visited[i] > col)
                    visited[i] = 0;
            }

            visited[r] = col;
            p--;
            sum += 1 + k;
            backtrack(row, col + 1, sum);
            sum -= 1 + k;
            p++;
            visited[r] = 0;
            for (int i = 1; i <= n; i++) {
                if (visited[i] > col)
                    visited[i] = 0;
            }
            return;
        }
        if (p > 0 && visited[l] == 0 && l >= 1) {
            visited[l] = col;
            sum += 1 + k;
            p--;
        }
        if (p > 0 && visited[r] == 0 && r <= n) {
            visited[r] = col;
            sum += 1 + k;
            p--;
        }
        k++;
    }
    backtrack(row, col + 1, sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
        for (int i = 1; i <= 3; i++) {
            cin >> door[i] >> people[i];
        }
        res = 123456789;
        for (int i = 0; i < 6; i++) {
            backtrack(i, 1, 0);
            for (int j = 0; j <= n; j++)
                visited[j] = 0;
        }
        cout << "Case #" << tc << endl
             << res << endl;
    }
    return 0;
}