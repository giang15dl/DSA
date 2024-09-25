#include <iostream>
using namespace std;

int a[301][301];
int visited[301][301];
int t, tc, n, m, startX, startY, endX, endY;
int q[50000][3];
int front, rear;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};

int BFS(int x, int y);

void reset();

int main() {
    // freopen("input.txt","r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n >> m >> startX >> startY >> endX >> endY;
        reset();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            a[x - 1][y - 1] = 1;
        }
        int res = BFS(startX - 1, startY - 1);
        cout << res << endl;
    }

    return 0;
}

int BFS(int x, int y) {
    front = rear = 0;
    q[rear][0] = x;
    q[rear][1] = y;
    q[rear++][2] = 0;
    visited[x][y] = 0;
    while (front != rear) {
        int curX = q[front][0];
        int curY = q[front][1];
        int vs = q[front++][2];
        for (int i = 0; i < 4; i++) {
            int tx = curX;
            int ty = curY;
            while (a[tx + dx[i]][ty + dy[i]] != 1 && tx + dx[i] < n && tx + dx[i] >= 0 && ty + dy[i] < n && ty + dy[i] >= 0 && visited[tx + dx[i]][ty + dy[i]] >= vs + 1) {
                tx = tx + dx[i];
                ty = ty + dy[i];
                visited[tx][ty] = vs + 1;
                q[rear][0] = tx;
                q[rear][1] = ty;
                q[rear++][2] = vs + 1;
                if (visited[endX - 1][endY - 1] != 654321) {
                    return vs + 1;
                }
            }
        }
    }
    return -1;
}

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
            visited[i][j] = 654321;
        }
    }
}