#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int N = 20;
const int G = 4;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int solve(int (&)[N][N], Point (&)[G], int, int);

int BFS(int (&)[N][N], Point (&)[G], int, int, Point);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, g;
        int mat[N][N] = {};
        Point gold[G];
        cin >> n >> g;
        for (int i = 0; i < g; i++) {
            cin >> gold[i].i >> gold[i].j;
            gold[i].i--;
            gold[i].j--;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        cout << "Case #" << t + 1 << endl;
        cout << solve(mat, gold, n, g) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][N], Point (&gold)[G], int n, int g) {
    int ans = INT_MAX;

    for (int i = 0; i < g; i++)
        mat[gold[i].i][gold[i].j] = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                int step = BFS(mat, gold, n, g, Point(i, j));
                if (step == -1)
                    continue;

                if (step < ans)
                    ans = step;
            }
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int BFS(int (&mat)[N][N], Point (&gold)[G], int n, int g, Point x) {
    int visited[N][N] = {};
    Queue<Point> q;
    q.push(x);
    visited[x.i][x.j] = 1;

    while (!q.empty()) {
        Point prev = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next(prev.i + di[d], prev.j + dj[d]);
            if (next.valid(n, n) && mat[next.i][next.j] && !visited[next.i][next.j]) {
                visited[next.i][next.j] = visited[prev.i][prev.j] + 1;
                q.push(next);
            }
        }
    }

    int max = 0;
    for (int gi = 0; gi < g; gi++) {
        if (visited[gold[gi].i][gold[gi].j] == 0)
            return -1;

        if (visited[gold[gi].i][gold[gi].j] > max)
            max = visited[gold[gi].i][gold[gi].j];
    }

    return max;
}