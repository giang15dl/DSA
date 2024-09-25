#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INT_MAX 2147483647
#define INF INT_MAX

const int N = 100;
const int M = 100;
const int K = 10 + 1; // count the robot as target too
const int MAX_QUEUE = 1000;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int solve(int (&mat)[N][M], int n, int m);
void BFS(int (&mat)[N][M], int n, int m, Point (&target)[K], int k, int index, int (&dis)[K][K]);

void backtracking(int &ans, int k, int (&visited)[K], int (&dis)[K][K], int index = 0, int count = 0, int moves = 0);

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
    int ans = INF;
    int k = 1;
    Point target[K];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 3)
                target[0].i = i, target[0].j = j;
            else if (mat[i][j] == 1) {
                target[k].i = i, target[k].j = j;
                k++;
            }
        }
    }

    int dis[K][K] = {};
    for (int i = 0; i < k; i++)
        BFS(mat, n, m, target, k, i, dis);

    int visited[K] = {};
    backtracking(ans, k, visited, dis);
    return (ans != INF) ? ans : -1;
}

void backtracking(int &ans, int k, int (&visited)[K], int (&dis)[K][K], int u, int count, int moves) {
    if (moves > ans)
        return;
    if (count == k - 1) {
        if (moves < ans)
            ans = moves;
        return;
    }
    for (int v = 1; v < k; v++) {
        if (!visited[v] && dis[u][v] > 0) {
            visited[v] = 1;
            backtracking(ans, k, visited, dis, v, count + 1, moves + dis[u][v]);
            visited[v] = 0;
        }
    }
}

void BFS(int (&mat)[N][M], int n, int m, Point (&target)[K], int k, int index, int (&dis)[K][K]) {
    int visited[N][M] = {};
    Queue<Point, MAX_QUEUE> q;
    q.push(target[index]);
    visited[target[index].i][target[index].j] = 1;

    while (!q.empty()) {
        Point curr = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            if (next.valid(n, m) && !visited[next.i][next.j] && mat[next.i][next.j] != 2) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (visited[target[i].i][target[i].j]) {
            dis[index][i] = visited[target[i].i][target[i].j] - 1;
            dis[i][index] = visited[target[i].i][target[i].j] - 1;
        } else {
            dis[index][i] = -1;
            dis[i][index] = -1;
        }
    }
}