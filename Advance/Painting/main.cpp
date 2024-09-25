#include <iostream>

const int N = 30;

int solve(const int (&)[N][N], int);

void backtrack(const int (&)[N][N], int, int (&)[N], int, int &);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int ti = 0; ti < T; ti++) {
        int n;
        cin >> n;

        int adj[N][N] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];
            
        cout << "Case #" << ti + 1 << endl;
        cout << solve(adj, n) << endl;
    }
    return 0;
}

int solve(const int (&adj)[N][N], int n) {
    int color[N] = {};
    int cnt = 0;

    backtrack(adj, n, color, 0, cnt); // try to coloring from the first region

    return cnt;
}

void backtrack(const int (&adj)[N][N], int n, int (&color)[N], int i, int &cnt) {
    if (i == n) {
        cnt++;
        return;
    }

    bool used[4] = {};

    for (int j = 0; j < i; j++)
        if (adj[i][j])
            used[color[j]] = true;

    for (int j = 0; j < 4; j++) {
        if (!used[j]) {
            color[i] = j;
            backtrack(adj, n, color, i+1, cnt);
        }
    }
}