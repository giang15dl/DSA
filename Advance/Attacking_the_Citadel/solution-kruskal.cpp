#include <stdio.h>

#define MAX_N 101

int adjMap[MAX_N][MAX_N];
int st[MAX_N * MAX_N];
int en[MAX_N * MAX_N];
int dist[MAX_N * MAX_N];
int edgeCnt;
int N;

int parent[MAX_N];

void swap(int i, int j);

void qSort(int left, int right);

int findSet(int x);

void join(int x, int y);

int main() {
    int T;
    int res;
    int u, v, machine, neighbor, ret;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        edgeCnt = 0;
        ret = 0;
        for (int i = 0; i < N; i++) {
            parent[i] = i;
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

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (adjMap[u][v]) {
                    dist[edgeCnt] = adjMap[u][v];
                    st[edgeCnt] = v;
                    en[edgeCnt++] = u;
                }
            }
        }

        qSort(0, edgeCnt - 1);

        for (int i = 0; i < edgeCnt; i++) {
            u = findSet(st[i]);
            v = findSet(en[i]);
            if (u == v)
                ret += dist[i];
            else
                join(u, v);
        }
        printf("%d\n", ret);
    }

    return 0;
}

void swap(int i, int j) {
    int tmp = st[i];
    st[i] = st[j];
    st[j] = tmp;
    tmp = en[i];
    en[i] = en[j];
    en[j] = tmp;
    tmp = dist[i];
    dist[i] = dist[j];
    dist[j] = tmp;
}

void qSort(int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swap(left, (left + right) >> 1);
    last = left;
    for (int i = left + 1; i <= right; i++)
        if (dist[i] > dist[left])
            swap(++last, i);
    swap(left, last);
    qSort(left, last - 1);
    qSort(last + 1, right);
}

int findSet(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = findSet(parent[x]);
}

void join(int x, int y) {
    parent[findSet(y)] = findSet(x);
}