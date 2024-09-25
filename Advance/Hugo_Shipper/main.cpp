#include <climits>
#include <cmath>
#include <iostream>

const int N = 10;

int solve(int (&)[N][2], int, int (&)[2], int (&)[2]);

int dis(int (&)[2], int (&)[2]);

void backtrack(int (&)[N][2], int, int (&)[2], int (&)[N], int &, int, int, int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int ti = 0; ti < T; ti++) {
        int S[2], D[2]; // Sx, Sy, Dx, Dy
        cin >> S[0] >> S[1] >> D[0] >> D[1];
        int n;
        cin >> n;
        int coords[N][2]; // x, y coordinates
        for (int i = 0; i < n; i++)
            cin >> coords[i][0] >> coords[i][1];

        cout << "Case #" << ti + 1 << " " << solve(coords, n, S, D) << endl;
    }

    return 0;
}

int solve(int (&coords)[N][2], int n, int (&S)[2], int (&D)[2]) {
    int visited[N] = {};
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        visited[i] = 1;
        int currDis = dis(S, coords[i]);
        backtrack(coords, n, D, visited, ans, i, currDis, 1);
        visited[i] = 0;
    }

    return ans;
}

int dis(int (&A)[2], int (&B)[2]) {
    return abs(A[0] - B[0]) + abs(A[1] - B[1]);
}

void backtrack(int (&coords)[N][2], int n, int (&D)[2], int (&visited)[N], int &ans, int i, int currDis, int cnt) {
    if (currDis > ans)
        return;

    if (cnt == n) {
        int totalDis = currDis + dis(coords[i], D);
        if (totalDis < ans)
            ans = totalDis;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            int nextDis = currDis + dis(coords[j], coords[i]);
            backtrack(coords, n, D, visited, ans, j, nextDis, cnt + 1);
            visited[j] = 0;
        }
    }
}
