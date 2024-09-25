#include "point.hpp"
#include "stack.hpp"
#include <iostream>

const int N_MAX = 25;

const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};

void solveBFS(int (&mat)[N_MAX][N_MAX], int N);
void solveDFS(int (&mat)[N_MAX][N_MAX], int N);

int BFS(int (&)[N_MAX][N_MAX], int, Point, int (&)[N_MAX][N_MAX]);
void DFS(int (&)[N_MAX][N_MAX], int, Point, int (&)[N_MAX][N_MAX], int &);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N = 0;
        cin >> N;

        int matrix[N_MAX][N_MAX] = {};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> matrix[i][j];

        solveDFS(matrix, N);
    }

    return 0;
}

void solveBFS(int (&mat)[N_MAX][N_MAX], int N) {
    int visited[N_MAX][N_MAX] = {};
    int constellars = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] && !visited[i][j]) {
                constellars++;
                int stars = BFS(mat, N, Point(i, j), visited);
                if (stars > max)
                    max = stars;
            }
        }
    }
    cout << constellars << " " << max << endl;
}

void solveDFS(int (&mat)[N_MAX][N_MAX], int N) {
    int visited[N_MAX][N_MAX] = {};
    int constellars = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] && !visited[i][j]) {
                constellars++;
                int stars = 1;
                DFS(mat, N, Point(i, j), visited, stars);
                if (stars > max)
                    max = stars;
            }
        }
    }
    cout << constellars << " " << max << endl;
}

int BFS(int (&mat)[N_MAX][N_MAX], int N, Point curr, int (&visited)[N_MAX][N_MAX]) {
    Stack<Point, N_MAX * N_MAX> s; // either Stack or Queue works !
    int count = 1;
    s.push(curr);
    visited[curr.i][curr.j] = 1;

    while (!s.empty()) {
        Point curr = s.pop();
        for (int d = 0; d < 4; d++) {
            Point n(curr.i + di[d], curr.j + dj[d]);
            if (n.valid(N) && mat[n.i][n.j] && !visited[n.i][n.j]) {
                s.push(n);
                visited[n.i][n.j] = 1;
                count++;
            }
        }
    }

    return count;
}

void DFS(int (&mat)[N_MAX][N_MAX], int N, Point curr, int (&visited)[N_MAX][N_MAX], int &count) {
    visited[curr.i][curr.j] = 1;
    count++;
    for (int d = 0; d < 4; d++) {
        Point next(curr.i + di[d], curr.j + dj[d]);
        if (next.valid(N) && mat[next.i][next.j] && !visited[next.i][next.j])
            DFS(mat, N, next, visited, count);
    }
}
