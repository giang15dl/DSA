#include <iostream>
using namespace std;

const int M_MAX = 100;

int solve(int (&adj)[M_MAX][M_MAX], const int &M);

void DFS(int (&adj)[M_MAX][M_MAX], int (&parent)[M_MAX], bool (&vst)[M_MAX], const int &M, int v, bool &hasCycle, int &ret);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int M;
        cin >> M;

        int adj[M_MAX][M_MAX] = {};

        for (int m = 0; m < M; m++) {
            int i, ui, ci; // The index, the machine count, and the neighbor count
            cin >> i >> ui >> ci;
            for (int c = 0; c < ci; c++) {
                int j;
                cin >> j;
                adj[i][j] += ui;
                adj[j][i] = adj[i][j];
            }
        }
        cout << solve(adj, M) << endl;
    }

    return 0;
}

int solve(int (&adj)[M_MAX][M_MAX], const int &M) {
    bool hasCycle = false;
    bool vst[M_MAX] = {};
    int parent[M_MAX] = {};
    int ret = 0;

    do {
        hasCycle = false;

        for (int i = 0; i < M; i++) {
            vst[i] = false;
            parent[i] = -1;
        }

        for (int i = 0; i < M; i++) {
            if (!vst[i]) {
                vst[i] = true;
                DFS(adj, parent, vst, M, i, hasCycle, ret);
            }
            if (hasCycle)
                break;
        }

    } while (hasCycle);

    return ret;
}

void DFS(int (&adj)[M_MAX][M_MAX], int (&parent)[M_MAX], bool (&vst)[M_MAX], const int &M, int v, bool &hasCycle, int &ret) {
    if (hasCycle)
        return;

    for (int i = 0; i < M; i++) {
        if (adj[v][i]) {
            if (vst[i]) {
                if (parent[v] == i)
                    continue;

                hasCycle = true;
                parent[i] = v;

                int minVal = adj[v][i];
                int current = v;
                int k = i;
                while (current != i) {
                    if (adj[current][parent[current]] < minVal) {
                        k = current;
                        minVal = adj[current][parent[current]];
                    }
                    current = parent[current];
                }
                ret += adj[k][parent[k]];
                adj[k][parent[k]] = adj[parent[k]][k] = 0;
                return;
            } else {
                vst[i] = true;
                parent[i] = v;
                DFS(adj, parent, vst, M, i, hasCycle, ret);
            }
            if (hasCycle)
                break;
        }
    }
}
