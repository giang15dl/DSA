#include "queue.hpp"
#include <iostream>

const int N_MAX = 3000; // should be 3000
const int M_MAX = 3000; // should be 3000
const int Q_MAX = 3000000;

struct Pair {
    int i, j;

    Pair() : i(0), j(0) {}
    Pair(int i, int j) : i(i), j(j) {}
};

Pair solve(const int (&grid)[N_MAX][M_MAX], int N, int M, Pair start);

using namespace std;
int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Total number of test cases
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M; // number of rows(N) and cols(M) of the grid
        cin >> N >> M;

        int r, c; // the locacation where the acid is poured (row and col)
        cin >> r >> c;
        Pair start(r - 1, c - 1); // convert to 0-based indexing

        static int grid[N_MAX][M_MAX] = {}; // The grid contains info about tile type
        Pair C;                             // The special cell type C, value 2.

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 2)
                    C = Pair(i, j);
            }
        }

        Pair count = solve(grid, N, M, start);

        cout << "Case #" << t + 1 << endl;
        cout << count.i << " " << count.j << endl;
    }

    return 0;
}

Pair solve(const int (&grid)[N_MAX][M_MAX], int N, int M, Pair start) {
    static int visited[N_MAX][M_MAX] = {};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    Pair count(-1, -1); // first and second count

    static Queue<Pair, Q_MAX> q;
    q.clear();
    q.push(start);
    visited[start.i][start.j] = 1;

    while (!q.empty()) {
        Pair t = q.pop();
        for (int d = 0; d < 4; d++) {
            static const int di[4] = {1, 0, -1, 0};
            static const int dj[4] = {0, 1, 0, -1};
            Pair n(t.i + di[d], t.j + dj[d]);
            if (n.i >= 0 && n.j >= 0 && n.i < N && n.j < M && !visited[n.i][n.j]) {
                if (grid[n.i][n.j] == 1) {
                    q.push(n);
                    visited[n.i][n.j] = visited[t.i][t.j] + 1;
                    count.j = visited[n.i][n.j];
                } else if (grid[n.i][n.j] == 2) {
                    int adj_count = 0;
                    for (int d_adj = 0; d_adj < 4; d_adj++) {
                        Pair adj(n.i + di[d_adj], n.j + dj[d_adj]);
                        if (adj.i >= 0 && adj.j >= 0 && adj.i < N && adj.j < M && visited[adj.i][adj.j])
                            adj_count++;
                    }
                    if (adj_count == 4) {
                        visited[n.i][n.j] = visited[t.i][t.j];
                        count.i = visited[n.i][n.j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && grid[i][j] != 0) {
                count.j = -1;
                return count;
            }
        }
    }

    return count;
}
