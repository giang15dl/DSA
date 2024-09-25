#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INF INT_MAX

const int N = 300;
const int M = 300;
const int Q = 100000;

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

char mat[N][M] = {};
int visited[N][M] = {};
Queue<Point, Q> q;

int solve(char (&mat)[N][M], int n, int m);
int BFS(char (&mat)[N][M], int n, int m, Point Y, Point T);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    int T; // Number of test cases
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << "Case #" << tc + 1 << endl;
        cout << solve(mat, n, m) << endl;
    }
    return 0;
}

int solve(char (&mat)[N][M], int n, int m) {
    Point Y, T;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'Y')
                Y = Point(i, j);
            if (mat[i][j] == 'T')
                T = Point(i, j);
        }
    }
    int ans = BFS(mat, n, m, Y, T);
    return (ans == INF) ? -1 : ans - 1;
}

int BFS(char (&mat)[N][M], int n, int m, Point Y, Point T) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = INF;

    q.clear();

    q.push(Y);
    visited[Y.i][Y.j] = 1;

    while (!q.empty()) {
        Point curr = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next = curr + Point(di[d], dj[d]);
            if (next.valid(n, m) && mat[next.i][next.j] == 'B' && visited[next.i][next.j] > visited[curr.i][curr.j] + 2) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + 2;
                q.push(next);
            }
            if (next.valid(n, m) && (mat[next.i][next.j] == 'T' || mat[next.i][next.j] == 'E') && visited[next.i][next.j] > visited[curr.i][curr.j] + 1) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + 1;
                q.push(next);
            }
        }
    }

    return visited[T.i][T.j];
}
