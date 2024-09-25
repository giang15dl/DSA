#include <stdio.h>

#define MAX_N 101
int adjMap[MAX_N][MAX_N];
int N;

int parent[MAX_N];
bool visited[MAX_N];
int ret;

bool hasCycle;
int cnt;
int st[MAX_N];

void DFS(int v);

int main() {
    int T;
    int u, v, machine, neighbor;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                adjMap[i][j] = 0;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &u, &machine, &neighbor);
            for (int j = 0; j < neighbor; j++) {
                scanf("%d", &v);
                adjMap[u][v] += machine;
                adjMap[v][u] = adjMap[u][v];
            }
        }

        do {
            hasCycle = false;
            for (int i = 0; i < N; ++i) {
                visited[i] = false;
                parent[i] = -1;
            }
            for (int i = 0; i < N; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    DFS(i);
                }
                if (hasCycle)
                    break;
            }
        } while (hasCycle);
        printf("%d\n", ret);
    }

    return 0;
}

void DFS(int v) {
    if (hasCycle)
        return;
    for (int i = 0; i < N; ++i) {
        if (adjMap[v][i]) {
            if (visited[i]) {
                if (i == parent[v])
                    continue;

                hasCycle = true;
                parent[i] = v;

                int k = i, minVal = adjMap[v][i];
                int curr = v;
                while (curr != i) {
                    if (adjMap[curr][parent[curr]] < minVal) {
                        k = curr;
                        minVal = adjMap[curr][parent[curr]];
                    }
                    curr = parent[curr];
                }
                ret += adjMap[k][parent[k]];
                adjMap[k][parent[k]] = adjMap[parent[k]][k] = 0;
                return;
            } else {
                visited[i] = true;
                parent[i] = v;
                DFS(i);
            }
            if (hasCycle)
                break;
        }
    }
}