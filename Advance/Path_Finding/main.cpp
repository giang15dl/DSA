#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "stack.hpp"
#include <iostream>

using namespace std;

const int N_MAX = 20;
const int STACK_SIZE = 100000;

bool solve(const int (&mat)[N_MAX][N_MAX], const int &N);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int mat[N_MAX][N_MAX] = {};
        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++)
                cin >> mat[row][col];

        solve(mat, N) ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}

bool solve(const int (&mat)[N_MAX][N_MAX], const int &N) {
    // Direction: up, right, down, left
    const int di[] = {0, 1, 0, -1};
    const int dj[] = {-1, 0, 1, 0};

    Point src(0, 0);
    Point dst(N - 1, N - 1);

    Stack<Point, STACK_SIZE> s;
    s.push(src);
    bool vst[N_MAX][N_MAX] = {}; // visited

    while (!s.empty()) {
        Point t = s.pop(); // The current Point

        if (t == dst)
            return true;

        int distance = mat[t.i][t.j];
        vst[t.i][t.j] = 1;

        for (int d = 0; d < 4; d++) {
            int ni = t.i + distance * di[d];
            int nj = t.j + distance * dj[d];
            Point n(ni, nj); // Next Point
            if (n.valid(N, N) && !vst[n.i][n.j])
                s.push(n);
        }
    }
    return false;
}