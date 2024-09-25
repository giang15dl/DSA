#include <iostream>
using namespace std;

#define INF 654321

int t, tc, m, n;
char a[3001][3001];
int visited[3001][3001];
int frontX, rearX, frontY, rearY;
int qX[1000001], qY[1000001];
int startX, startY, endX, endY;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void initQueue();
bool isEmpty();
void enQueue(int x, int y);
int deQueueX();
int deQueueY();
bool isSafe(int tx, int ty);

void BFS(int x, int y);

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'Y') {
                    startX = i;
                    startY = j;
                }
                if (a[i][j] == 'T') {
                    endX = i;
                    endY = j;
                }
                visited[i][j] = INF;
            }
        }
        int ans = 0;
        BFS(startX, startY);
        ans = visited[endX][endY];
        cout << "Case #" << tc << endl;
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans - 1 << endl;
    }

    return 0;
}

void BFS(int x, int y) {
    initQueue();
    enQueue(x, y);
    visited[x][y] = 1;
    while (!isEmpty()) {
        int curX = deQueueX();
        int curY = deQueueY();
        for (int i = 0; i < 4; i++) {
            int tx = curX + dx[i];
            int ty = curY + dy[i];
            if (isSafe(tx, ty) && a[tx][ty] == 'B' && visited[tx][ty] > visited[curX][curY] + 2) {
                visited[tx][ty] = visited[curX][curY] + 2;
                enQueue(tx, ty);
            }
            if (isSafe(tx, ty) && (a[tx][ty] == 'T' || a[tx][ty] == 'E') && visited[tx][ty] > visited[curX][curY] + 1) {
                visited[tx][ty] = visited[curX][curY] + 1;
                enQueue(tx, ty);
            }
        }
    }
}

void initQueue() {
    frontX = rearX = frontY = rearY = -1;
}

bool isEmpty() {
    return frontX == rearX;
}

void enQueue(int x, int y) {
    rearX++;
    rearY++;
    qX[rearX] = x;
    qY[rearY] = y;
}

int deQueueX() {
    frontX++;
    return qX[frontX];
}

int deQueueY() {
    frontY++;
    return qY[frontY];
}

bool isSafe(int tx, int ty) {
    if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
        return true;
    }
    return false;
}
