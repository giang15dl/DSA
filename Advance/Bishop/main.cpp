#include "deque.hpp"
#include "point.hpp"
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

    int BFS(Point src, Point dst, int direction);
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
    int res1 = BFS(src, dst, 0);
    int res2 = BFS(src, dst, 1);
    int res3 = BFS(src, dst, 2);
    int res4 = BFS(src, dst, 3);

    int res = min(min(res1, res2), min(res3, res4));

    return res == INF ? -1 : res;
}

int Solution::BFS(Point src, Point dst, int direction) {
    int visited[N][N] = {};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = INF;

    Deque<State, MAX_QUEUE> dq;
    dq.push_back(State(src, direction));
    visited[src.i][src.j] = 0;

    while (!dq.empty()) {
        State t = dq.pop_front();
        Point curr = t.p;
        int d = t.d;
        for (int i = 0; i < 4; i++) {
            Point next(curr.i + di[i], curr.j + dj[i]);
            if (next.valid(n) && !obstacle[next.i][next.j]) {
                int cost = (i == d) ? 0 : 1;
                if (visited[next.i][next.j] > visited[curr.i][curr.j] + cost) {
                    visited[next.i][next.j] = visited[curr.i][curr.j] + cost;
                    if (cost == 0)
                        dq.push_front(State(next, i));
                    else
                        dq.push_front(State(next, i));
                }
            }
        }
    }

    return visited[dst.i][dst.j] + 1;
}

int Solution::min(int a, int b) {
    return (a < b) ? a : b;
}
