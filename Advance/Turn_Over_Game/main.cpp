#include <iostream>

const int N = 4;
const int INF = ~(1 << 31);

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int solve(int (&)[N][N]);

void backtrack(int (&)[N][N], int (&)[2], int &, int = 0, int = 0);

void doChange(int (&)[N][N], int (&)[2], int, int);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int mat[N][N] = {};
        for (int i = 0; i < N; i++) {
            char c[N + 1] = {};
            cin >> c;
            for (int j = 0; j < N; j++) {
                if (c[j] == 'b')
                    mat[i][j] = 0;
                else
                    mat[i][j] = 1;
            }
        }

        int ans = solve(mat);
        cout << "Case #" << t + 1 << endl;
        ans == -1 ? cout << "impossible" << endl : cout << ans << endl;
    }

    return 0;
}

int solve(int (&mat)[N][N]) {
    int ans = INF;
    int cnt[2] = {}; // count number of black and white

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cnt[mat[i][j]]++;

    backtrack(mat, cnt, ans);

    return ans == INF ? -1 : ans;
}

void backtrack(int (&mat)[N][N], int (&cnt)[2], int &ans, int number, int curr) {
    if (cnt[0] == 0 || cnt[1] == 0) { // Same color
        ans = number < ans ? number : ans;
        return;
    }

    if (number > ans)
        return;

    if (curr == N * N)
        return;

    backtrack(mat, cnt, ans, number, curr + 1); // Do nothing

    int i = curr / N;
    int j = curr % N;

    doChange(mat, cnt, i, j);
    backtrack(mat, cnt, ans, number + 1, curr + 1);
    doChange(mat, cnt, i, j);
}

void doChange(int (&mat)[N][N], int (&cnt)[2], int i, int j) {
    cnt[mat[i][j]]--;
    mat[i][j] = mat[i][j] ^ 1;
    cnt[mat[i][j]]++;

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 0 || nj < 0 || ni >= N || nj >= N)
            continue;

        cnt[mat[ni][nj]]--;
        mat[ni][nj] = mat[ni][nj] ^ 1;
        cnt[mat[ni][nj]]++;
    }
}