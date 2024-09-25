#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INT_MAX 2147483647
#define INF INT_MAX

const int N = 100;
const int M = 100;
const int K = 10 + 1; // Maximum number of target. Count the knight as target too.
const int Q = 10000;  // QUEUE size

const int di[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

class Solution {
public:
    Solution(int (&chessboard)[N][M], int n, int m);

    int Solve();

private:
    int ans;
    int n, m;
    int (&chessboard)[N][M];

    Point target[K];
    int k; // Total number of targets in the board (the knight is counted too)

    int distance[K][K] = {}; // TODO: initialize somewhere else
    int visited[K] = {};     // TODO: initialize somewhere else

    int BFS(int target_index);
    void BackTrack(int u = 0, int count = 0, int moves = 0);
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        int chessboard[N][M] = {};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> chessboard[i][j];

        Solution s(chessboard, n, m);

        cout << "Case #" << t + 1 << "\n"
             << s.Solve() << endl;
    }

    return 0;
}

Solution::Solution(int (&chessboard)[N][M], int n, int m) : chessboard(chessboard), n(n), m(m), ans(0) {
    for (size_t i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            distance[i][j] = 0;
        }
        visited[i] = 0;
    }
}

int Solution::Solve() {
    ans = INF;
    k = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chessboard[i][j] == 3)
                target[0] = Point(i, j);

            else if (chessboard[i][j] == 1) {
                target[k] = Point(i, j);
                k++;
            }
        }
    }

    for (int i = 0; i < k; i++)
        BFS(i);

    BackTrack();

    return ans;
}

int Solution::BFS(int index) {
    int visited[N][M] = {};
    Queue<Point, Q> q;
    q.push(target[index]);
    visited[target[index].i][target[index].j] = 1;

    while (!q.empty()) {
        Point t = q.pop();
        for (int d = 0; d < 8; d++) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (n.i >= 0 && n.j >= 0 && n.i < N && n.j < M && !visited[n.i][n.j]) {
                visited[n.i][n.j] = visited[t.i][t.j] + 1;
                q.push(n);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (visited[target[i].i][target[i].j]) {
            distance[index][i] = visited[target[i].i][target[i].j] - 1;
            distance[i][index] = visited[target[i].i][target[i].j] - 1;
        } else {
            distance[index][i] = -1;
            distance[i][index] = -1;
        }
    }

    return 0;
}

void Solution::BackTrack(int u, int count, int moves) {
    if (moves > ans)
        return;

    if (count == k - 1) {
        if (moves < ans)
            ans = moves;
        return;
    }

    for (int v = 1; v < k; v++) {
        if (!visited[v] && distance[u][v] > 0) {
            visited[v] = 1;
            BackTrack(v, count + 1, moves + distance[u][v]);
            visited[v] = 0;
        }
    }
}
