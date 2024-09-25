#include "point.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

const int N_MAX = 50;
const int M_MAX = 50;
const int QUEUE_SIZE = 2500;

// Direction: Up-Down, Left-Right
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

// Pipe type
const int p[8][4] = {
    {0, 0, 0, 0}, // No pipe
    {1, 1, 1, 1}, // Up-Down, Left-Right
    {1, 1, 0, 0}, // Up-Down
    {0, 0, 1, 1}, // Left-Right
    {1, 0, 0, 1}, // Up-Right
    {0, 1, 0, 1}, // Down-Right
    {0, 1, 1, 0}, // Down-Left
    {1, 0, 1, 0}  // Up-Left
};

// Check if pipe p1 can go to pipe p2 in the direction d and pipe p2 can go to pipe p1 in the reverse direction.
int Check(int x, int y, int k);

int BFS(const int (&mat)[N_MAX][M_MAX], const int &N, const int &M, const Point &start, const int &steps);

/////////////////////////////////////MAIN//////////////////////////////////////
int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    const char *output = (argc > 2) ? argv[2] : "stdout.txt";
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M; // Matrix size NxM
        int r, c; // Hugo's location (row, col)
        int P;    // Hugo's mana
        cin >> N >> M >> r >> c >> P;
        int mat[N_MAX][M_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        Point hugo(r, c);

        cout << "Case #" << t + 1 << endl
             << BFS(mat, N, M, hugo, P) << endl;
    }
    return 0;
}
/////////////////////////////////////MAIN//////////////////////////////////////

int Check(int p1, int p2, int d) {
    // bitwise XOR operator: 0^1 = 1
    //                       1^1 = 0
    //                       2^1 = 3
    //                       3^1 = 2
    return p[p1][d] && p[p2][d ^ 1];

    // switch (d) {
    // case 0:
    //     return p[p1][d] && p[p2][1];
    //     break;
    // case 1:
    //     return p[p1][d] && p[p2][0];
    //     break;
    // case 2:
    //     return p[p1][d] && p[p2][3];
    //     break;
    // case 3:
    //     return p[p1][d] && p[p2][2];
    //     break;
    // default:
    //     return 0;
    //     break;
    // }
}

int BFS(const int (&mat)[N_MAX][M_MAX], const int &N, const int &M, const Point &start, const int &steps) {
    int count = 0; // Count the number of pipes
    int vst[N_MAX][M_MAX] = {};

    vst[start.i][start.j] = 1;
    count++;

    Queue<Point, QUEUE_SIZE> q;

    q.push(start);

    while (!q.empty()) {
        Point t = q.pop();

        if (vst[t.i][t.j] >= steps)
            return count;

        for (int d = 0; d < 4; d++) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (n.valid(N, M) && !vst[n.i][n.j] && Check(mat[t.i][t.j], mat[n.i][n.j], d)) {
                q.push(Point(n.i, n.j));
                vst[n.i][n.j] = vst[t.i][t.j] + 1;
                count++;
            }
        }
    }
    return count;
}