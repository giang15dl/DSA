#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int N = 50;
const int M = 50;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int solve(int (&)[N][M], int, int);
bool BFS(int (&)[N][M], int, int, Point, Point, int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        int mat[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << "Case #" << t + 1 << endl;
        cout << solve(mat, n, m) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][M], int n, int m) {
    Point S, D;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2)
                S = Point(i, j);
            else if (mat[i][j] == 3)
                D = Point(i, j);
        }
    }

    int step = 0;
    while (!BFS(mat, n, m, S, D, step))
        step++;

    return step;
}

bool BFS(int (&mat)[N][M], int n, int m, Point S, Point D, int step) {
    int visited[N][M] = {};
    Queue<Point> q;
    q.push(S);
    visited[S.i][S.j] = 1;

    while (!q.empty()) {
        Point curr = q.pop();
        for (int h = 0; h <= step; h++) {
            for (int i = 0; i < 4; i++) {
                Point next(curr.i + di[i] * h, curr.j + dj[i]);
                if (!next.valid(n, m) || visited[next.i][next.j] || !mat[next.i][next.j])
                    continue;

                if (next == D)
                    return true;

                q.push(next);
                visited[next.i][next.j] = 1;
            }
        }
    }

    return false;
}