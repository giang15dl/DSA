#include <iostream>

const int N_MAX = 100; // Should be 100

int solve(const int (&adj)[N_MAX][N_MAX], const int N);

int countIsolated(const int (&adj)[N_MAX][N_MAX], const int N);

void unConnect(int (&adj)[N_MAX][N_MAX], const int N, int v);

void DFS(const int (&adj)[N_MAX][N_MAX], int (&visited)[N_MAX], int N, int v);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int mat[N_MAX][N_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];

        cout << solve(mat, N) << endl;
    }

    return 0;
}

int solve(const int (&adj)[N_MAX][N_MAX], const int N) {
    int adj_copy[N_MAX][N_MAX] = {};

    int max = 0;
    int index = 0;

    for (int v = 0; v < N; v++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj_copy[i][j] = adj[i][j];

        unConnect(adj_copy, N, v);
        int count = countIsolated(adj_copy, N);
        if (count > max) {
            index = v;
            max = count;
        }
    }

    return (max == 1) ? 0 : index + 1;
}

void unConnect(int (&adj)[N_MAX][N_MAX], const int N, int v) {
    for (int i = 0; i < N; i++) {
        adj[v][i] = 0;
        adj[i][v] = 0;
    }
}

int countIsolated(const int (&adj)[N_MAX][N_MAX], const int N) {
    int visited[N_MAX] = {};
    int count = 0;

    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            DFS(adj, visited, N, v);
            count++;
        }
    }

    return count - 1;
}

void DFS(const int (&adj)[N_MAX][N_MAX], int (&visited)[N_MAX], int N, int v) {
    visited[v] = 1;

    for (int i = 0; i < N; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(adj, visited, N, i);
        }
    }
}
