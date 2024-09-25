#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int N = 200;
const int MAX_QUEUE = 50000;
const int INF = INT_MAX;

// Direction: up-left, up-right, down-right, down-left
const int di[4] = {-1, -1, 1, 1};
const int dj[4] = {-1, 1, 1, -1};

struct State {
    Point p;
    int d;

    State() : p(), d(0) {}

    State(Point p, int dis) : p(p), d(dis) {}
};

class Solution {
public:
    Solution(int n, int m, Point src, Point dst, int (&obstacle)[N][N]);
    int solve();

private:
    Point src, dst;
    int n, m;
    int (&obstacle)[N][N];

    int BFS(Point src, Point dst);
    int min(int a, int b);
};

using namespace std;
int main(int argc, char **argv) { ////////////////////////////////////////////
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int ti = 0; ti < T; ti++) {
        int n, m;
        Point src, dst;
        cin >> n >> m >> src.i >> src.j >> dst.i >> dst.j;
        src--;
        dst--;

        int obstacle[N][N] = {};
        for (int i = 0; i < m; i++) {
            int r, c;
            cin >> r >> c;
            obstacle[r - 1][c - 1] = 1;
        }

        Solution s(n, m, src, dst, obstacle);

        cout << s.solve() << endl;
    }

    return 0;
}; ////////////////////////////////////////////////////////////////////////////

Solution::Solution(int n, int m, Point src, Point dst, int (&obstacle)[N][N]) : n(n), m(m), src(src), dst(dst), obstacle(obstacle) {}

int Solution::solve() {
    return BFS(src, dst);
}

int Solution::BFS(Point src, Point dst) {
    int visited[N][N] = {};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = INF;

    Queue<State, MAX_QUEUE> q;
    q.push(State(src, 0));
    visited[src.i][src.j] = 0;

    while (!q.empty()) {
        State s = q.pop();
        Point curr = s.p;
        int dir = s.d;
        for (int d = 0; d < 4; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            while (next.valid(n, n) && !obstacle[next.i][next.j] && visited[next.i][next.j] > dir) {
                visited[next.i][next.j] = dir + 1;
                q.push(State(next, dir + 1));
                if (visited[dst.i][dst.j] != INF)
                    return dir + 1;
                next.i += di[d];
                next.j += dj[d];
            }
        }
    }
    return -1;
}

int Solution::min(int a, int b) {
    return (a < b) ? a : b;
}
