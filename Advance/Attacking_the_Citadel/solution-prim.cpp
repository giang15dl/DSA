#include <stdio.h>

#define MAX_N 101

int adjList[MAX_N][MAX_N];
int adjCnt[MAX_N];
int adjMap[MAX_N][MAX_N];
int N;

int parent[MAX_N], key[MAX_N];
bool visited[MAX_N];

int findMax();

int main() {
    int T;
    int u, v, machine, neighbor, total, remain;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        total = 0;
        for (int i = 0; i < N; i++) {
            visited[i] = false;
            key[i] = -1;
            parent[i] = -1;
            for (int j = 0; j < N; j++)
                adjMap[i][j] = 0;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &u, &machine, &neighbor);
            adjCnt[u] = neighbor;
            for (int j = 0; j < neighbor; j++) {
                scanf("%d", &v);
                total += machine;
                adjMap[u][v] += machine;
                adjMap[v][u] = adjMap[u][v];
                adjList[u][j] = v;
            }
        }

        key[0] = 0;
        for (int i = 0; i < N - 1; i++) {
            u = findMax();
            if (u != -1) {
                visited[u] = true;
                for (int j = 0; j < adjCnt[u]; j++) {
                    v = adjList[u][j];
                    if (!visited[v] && adjMap[u][v] > key[v]) {
                        key[v] = adjMap[u][v];
                        parent[v] = u;
                    }
                }
            } else {
                for (u = 0; u < N; u++) {
                    if (!visited[u])
                        break;
                }
                key[u] = 0;
                i--;
            }
        }
        remain = 0;
        for (int i = 1; i < N; i++) {
            if (parent[i] != -1)
                remain += adjMap[i][parent[i]];
        }
        printf("%d\n", total - remain);
    }

    return 0;
}

int findMax() {
    int ret = -1;
    int max = -1;
    for (int v = 0; v < N; v++) {
        if (!visited[v] && key[v] > max) {
            max = key[v];
            ret = v;
        }
    }
    return ret;
}