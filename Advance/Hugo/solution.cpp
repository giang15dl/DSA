#include "stack.hpp"
#include <iostream>

using namespace std;

int t, tc, n, m, sx, sy, p, thoat, ans, front, rear;
int lakes[20][20], diamonds[20][20], qx[600], qy[600], fires[20][20], visited[20][20], gates[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct State {
    int i, j, time, score;
    State() : i(0), j(0), time(0), score(0) {}
    State(int i, int j, int time, int score) : i(i), j(j), time(time), score(score) {}
};

void initQ();

int isEmpty();

void enQueue(int x, int y);

int deQueueX();

int deQueueY();

int dk(int x, int y);

void chayLan();

void DFS(int i, int j, int time, int score);

int DFS_Stack(int i, int j);

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n >> m >> sx >> sy;
        sx;
        sy;
        int i, j, x, h, c;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                lakes[i][j] = 0;
                fires[i][j] = 5000;
                visited[i][j] = 0;
                gates[i][j] = 0;
            }
        }
        cin >> p;
        for (x = 0; x < p; x++) {
            cin >> h >> c;
            fires[h][c] = 0;
        }
        cin >> p;
        for (x = 0; x < p; x++) {
            cin >> h >> c;
            lakes[h][c] = 1;
        }
        cin >> thoat;
        for (x = 0; x < thoat; x++) {
            cin >> h >> c;
            gates[h][c] = 3;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> diamonds[i][j];
            }
        }

        chayLan();
        ans = -1;
        visited[sx][sy] = 1;
        DFS(sx, sy, 0, diamonds[sx][sy]);
        cout << "Case #" << tc << endl;
        cout << ans << endl;

        // Attemp to using Stack instead of recursion, not really work.
        // cout << "Case #" << tc << endl;
        // cout << DFS_Stack(sx, sy) << endl;
    }
    return 0;
}

void initQ() {
    rear = front = -1;
}

int isEmpty() {
    if (front == rear)
        return 1;
    return 0;
}

void enQueue(int x, int y) {
    rear++;
    qx[rear] = x;
    qy[rear] = y;
}

int deQueueX() {
    if (!isEmpty())
        return qx[front + 1];
    return -1;
}

int deQueueY() {
    if (!isEmpty()) {
        front++;
        return qy[front];
    }
    return -1;
}

int dk(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void chayLan() {
    initQ();
    int i, j, x, y, tx, ty, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (fires[i][j] == 0) {
                enQueue(i, j);
                // dchay[i][j] = 1;
            }
        }
    }
    while (!isEmpty()) {
        x = deQueueX();
        y = deQueueY();
        for (k = 0; k < 4; k++) {
            tx = x + dx[k];
            ty = y + dy[k];
            if (dk(tx, ty) && (fires[tx][ty] == 5000 || fires[tx][ty] > fires[x][y] + 1) && lakes[tx][ty] != 1) {
                enQueue(tx, ty);
                fires[tx][ty] = fires[x][y] + 1;
            }
        }
    }
}

void DFS(int i, int j, int time, int score) {
    int h = time;
    int c = score;

    if (gates[i][j] == 3) {
        if (c > ans)
            ans = c;
    }

    if (lakes[i][j] == 1)
        h += 2;
    else
        h += 1;

    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (dk(nx, ny) && visited[nx][ny] == 0 && (lakes[nx][ny] == 1 || h < fires[nx][ny])) {
            visited[nx][ny] = 1;
            DFS(nx, ny, h, c + diamonds[nx][ny]);
            visited[nx][ny] = 0;
        }
    }
}

int DFS_Stack(int i, int j) {
    int time = 0;
    int score = diamonds[i][j];
    int res = -1;
    int visited[20][20] = {};

    Stack<State, 50000> stk;
    stk.push(State(i, j, time, score));
    visited[i][j] = 1;
    while (!stk.isEmpty()) {
        // Pop the top element
        State t = stk.pop();

        int h = t.time;
        int c = t.score;

        if (gates[t.i][t.j] == 3) {
            if (c > res)
                res = c;
        }

        if (lakes[t.i][t.j] == 1)
            h += 2;
        else
            h += 1;

        bool backtrack = true;
        for (int k = 0; k < 4; k++) {
            int nx = t.i + dx[k];
            int ny = t.j + dy[k];
            if (dk(nx, ny) && visited[nx][ny] == 0 && (lakes[nx][ny] == 1 || h < fires[nx][ny])) {
                visited[nx][ny] = 1;
                stk.push(State(nx, ny, h, c + diamonds[nx][ny]));
                backtrack = false;
            }
        }

        if (backtrack)
            visited[t.i][t.j] = 0; // Set visited to 0 after all possible paths from this node are explored
    }
    return res;
}