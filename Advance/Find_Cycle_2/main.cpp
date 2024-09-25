// #include "stack.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 5;

int solve(int (&)[N][N], int);
void DFS(int (&G)[N][N], int n, int (&visited)[N], int start, int v, vector<int> &path);

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int nodes, edges;
        cin >> nodes >> edges;

        int adj[N][N] = {};
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
        }

        solve(adj, nodes);
    }

    return 0;
}

int solve(int (&adj)[N][N], int n) {
    int vst[N] = {};

    vector<int> path;
    for (int i = 0; i < n; i++) {
        if (!vst[i]) {
            DFS(adj, n, vst, i, i, path);
        }
    }

    return 0;
}

void DFS(int (&G)[N][N], int n, int (&visited)[N], int start, int v, vector<int> &path) {
    if (visited[v]) {
        if (v == start) {
            for (auto c : path)
                cout << c << " ";
            cout << endl;
            return;
        } else
            return;
    }
    visited[v] = 1;
    path.push_back(v);
    for (int u = 0; u < n; u++)
        if (G[v][u])
            DFS(G, n, visited, start, u, path);

    visited[v] = 0;
    path.pop_back();
}