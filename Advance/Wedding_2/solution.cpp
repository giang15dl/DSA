#include <iostream>
using namespace std;
#define maxx 55
#define maxQ 505
int n, m, a[maxx][maxx], visited[maxx];
int res[maxx];
int res2[maxx];
int minD, minV;
int front, rear;
int q[maxQ];

void reset() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}

void dfsVe(int x, int cnt) {
    if (cnt > minV)
        return;
    if (x == 1) {
        if (cnt < minV) {
            minV = cnt;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (a[x][i] == 1 && visited[i] == 0) {
            visited[i]++;
            dfsVe(i, cnt + 1);
            visited[i]--;
        } else if (a[x][i] == 1 && visited[i] == 1) {
            visited[i]++;
            dfsVe(i, cnt);
            visited[i]--;
        }
    }
}

void dfs(int x, int cnt) {
    if (cnt > minD)
        return;
    if (x == 2) {
        if (cnt < minD) {
            dfsVe(2, cnt);
            minD = cnt;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (a[x][i] == 1 && visited[i] == 0) {
            visited[i]++;
            dfs(i, cnt + 1);
            visited[i]--;
        } else if (a[x][i] == 1 && visited[i] == 1) {
            visited[i]++;
            dfs(i, cnt);
            visited[i]--;
        }
    }
}

void reset1() {

    for (int i = 1; i <= n; i++) {
        res[i] = res2[i] = 0;
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << endl;
        cin >> n >> m;
        reset1();

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        reset();
        visited[1] = 1;
        minD = 1e9;
        minV = 1e9;
        dfs(1, 1);
        cout << minV << endl;
    }
    return 0;
}