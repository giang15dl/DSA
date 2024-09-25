#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int INF = INT_MAX;

const int N = 200;
const int M = N;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};

struct State {
    Point p;
    int d;
    State() : p(), d() {}
    State(Point p, int d) : p(p), d(d) {}
};

int solve(int (&)[N][M], int, int, Point, Point);
int BFS(int (&)[N][M], int, int, Point, Point);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> m >> n;
        Point s, d;
        cin >> s.j >> s.i >> d.j >> d.i;
        s--;
        d--;
        int mat[N][M] = {};
        for (int i = 0; i < n; i++) {
            char c[M + 1] = {};
            cin >> c;
            for (int j = 0; j < m; j++)
                if (c[j] == '1')
                    mat[i][j] = 1;
        }

        cout << solve(mat, n, m, s, d) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][M], int n, int m, Point src, Point dst) {
    return BFS(mat, n, m, src, dst);
}

int BFS(int (&mat)[N][M], int n, int m, Point src, Point dst) {
    int visited[N][M] = {};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = INF;

    static Queue<State, 500000> q;
    q.clear();
    q.push(State(src, 0));
    visited[src.i][src.j] = 0;

    while (!q.empty()) {
        State s = q.pop();
        Point curr = s.p;
        int turns = s.d;
        for (int d = 0; d < 4; d++) {
            Point next(curr.i, curr.j);
            while (true) {
                next.i += di[d];
                next.j += dj[d];
                if (!next.valid(n, m) || mat[next.i][next.j] || visited[next.i][next.j] <= turns)
                    break;

                visited[next.i][next.j] = turns + 1;
                q.push(State(next, turns + 1));
                if (visited[dst.i][dst.j] != INF)
                    return turns;
            }
        }
    }
    return -1;
}