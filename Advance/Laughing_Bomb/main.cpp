#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int MAX_N = 100; // should be 100
const int MAX_M = 100; // should be 100

// Direction : right down, left, up
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int solve(int (&)[MAX_N][MAX_M], int, int, Point);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, M;
        cin >> M >> N;

        int mat[MAX_M][MAX_N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        Point bomb;
        cin >> bomb.j >> bomb.i;
        bomb--;

        cout << solve(mat, N, M, bomb) << endl;
    }
    return 0;
}

int solve(int (&mat)[MAX_N][MAX_M], int N, int M, Point start) {
    int visited[MAX_N][MAX_M] = {};
    int ans = 0;
    Queue<Point, 50000> q;

    q.push(start);
    visited[start.i][start.j] = 1;
    while (!q.empty()) {
        Point curr = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            if (next.valid(N, M) && !visited[next.i][next.j] && mat[next.i][next.j]) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + 1;
                ans = visited[next.i][next.j];
                q.push(next);
            }
        }
    }
    return ans;
}
