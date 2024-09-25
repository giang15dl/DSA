#include <iostream>

using namespace std;

#define oo 123456789

int T, n, m, xr, yr, totalDirty, x, y, tx, ty, res;
int matrix[101][101];
int visited[101][101];
int used[20];
int distancE[20][20];
int dirX[20];
int dirY[20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Queue {
public:
    int front, rear;
    int a[10000];
    void initQueue() {
        front = rear = -1;
    }
    int isEmpty() {
        if (front == rear)
            return 1;
        return 0;
    }
    void enQueue(int value) {
        rear++;
        a[rear] = value;
    }
    int deQueue() {
        if (!isEmpty()) {
            front++;
            return a[front];
        }
        return -1;
    }

private:
};

Queue q1;
Queue q2;

void resetVisited();

int checkEdge(int xx, int yy);

void bfs(int i, int j, int pos);

void backtrack(int currDir, int cnt, int sum);

int main() {
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> m;
        totalDirty = 0;
        for (int i = 0; i <= 10; i++) {
            dirX[i] = 0;
            dirY[i] = 0;
            used[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 3) {
                    xr = i;
                    yr = j;
                }
                if (matrix[i][j] == 1) {
                    totalDirty++;
                    dirX[totalDirty] = i;
                    dirY[totalDirty] = j;
                }
            }
        }
        resetVisited();
        res = oo;
        bfs(xr, yr, 0);
        for (int i = 1; i <= totalDirty; i++) {
            resetVisited();
            used[i] = 0;
            bfs(dirX[i], dirY[i], i);
        }
        backtrack(0, 0, 0);
        if (res != oo) {
            cout << "Case #" << tc << endl
                 << res << endl;
        } else {
            cout << "Case #" << tc << endl
                 << -1 << endl;
        }
    }
    return 0;
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

int checkEdge(int xx, int yy) {
    if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        return 1;
    return 0;
}

void bfs(int i, int j, int pos) {
    q1.initQueue();
    q2.initQueue();
    q1.enQueue(i);
    q2.enQueue(j);
    visited[i][j] = 1;
    while (!q1.isEmpty()) {
        x = q1.deQueue();
        y = q2.deQueue();
        for (int k = 0; k < 4; k++) {
            tx = x + dx[k];
            ty = y + dy[k];
            if (checkEdge(tx, ty) && visited[tx][ty] == 0 && matrix[tx][ty] != 2) {
                visited[tx][ty] = visited[x][y] + 1;
                q1.enQueue(tx);
                q2.enQueue(ty);
            }
        }
    }
    for (int i = pos + 1; i <= totalDirty; i++) {
        if (visited[dirX[i]][dirY[i]] != 0) {
            distancE[pos][i] = visited[dirX[i]][dirY[i]] - 1;
            distancE[i][pos] = distancE[pos][i];
        } else {
            distancE[pos][i] = -1;
            distancE[i][pos] = distancE[pos][i];
        }
    }
}

void backtrack(int currDir, int cnt, int sum) {
    if (sum > res)
        return;
    if (cnt == totalDirty) {
        if (sum < res)
            res = sum;
        return;
    }
    for (int i = 1; i <= totalDirty; i++) {
        if (used[i] == 0 && distancE[currDir][i] > 0) {
            used[i] = 1;
            backtrack(i, cnt + 1, sum + distancE[currDir][i]);
            used[i] = 0;
        }
    }
}