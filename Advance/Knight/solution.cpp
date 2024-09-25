#include <iostream>
using namespace std;
int N, M;
int ans;
int map[105][105];
int road[105][2];
int kc[105][105];
int idx;
int sX, sY;

int const max_queue = 1000000;
int qx[max_queue];
int qy[max_queue];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}
void push(int x, int y) {
    if (front == -1)
        front = 0;
    rear++;
    qx[rear] = x;
    qy[rear] = y;
}
void pop() {
    if (front >= rear)
        front = rear = -1;
    else
        front++;
}

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int visit[105][105];

void resetVisit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = 0;
        }
    }
}

void BFS(int x, int y, int u) {
    resetVisit();
    int cnt = 0;
    front = rear = -1;
    push(x, y);
    visit[x][y] = 0;
    while (!isEmpty()) {
        int x1 = qx[front];
        int y1 = qy[front];
        pop();
        for (int i = 0; i < 8; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && visit[x2][y2] == 0) {
                visit[x2][y2] = visit[x1][y1] + 1;
                push(x2, y2);
                if (map[x2][y2] == 1 || map[x2][y2] == 3)
                    for (int v = 0; v < idx; v++)
                        if (x2 == road[v][0] && y2 == road[v][1])
                            kc[u][v] = visit[x2][y2];
            }
        }
    }
}

int visitUV[105] = {0};
void backtrack(int u, int step, int ith) {
    if (ith == idx) {
        if (step < ans)
            ans = step;
        return;
    }
    if (step > ans)
        return;
    for (int v = 0; v < idx; v++) {
        if (visitUV[v] == 0 && kc[u][v] > 0) {
            visitUV[v] = 1;
            backtrack(v, step + kc[u][v], ith + 1);
            visitUV[v] = 0;
        }
    }
}

void reset() {
    idx = 1;
    ans = 1000000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = -1;
        }
    }
    for (int i = 0; i < 105; i++) {
        road[i][0] = road[i][1] = 0;
        visitUV[i] = 0;
        for (int j = 0; j < 105; j++) {
            kc[i][j] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N >> M;
        reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
                if (map[i][j] == 3) {
                    sX = i;
                    sY = j;
                    road[0][0] = i;
                    road[0][1] = j;
                } else if (map[i][j] == 1) {
                    road[idx][0] = i;
                    road[idx][1] = j;
                    idx++;
                }
            }
        }

        for (int i = 0; i < idx; i++) {
            BFS(road[i][0], road[i][1], i);
        }

        visitUV[0] = 1;
        backtrack(0, 0, 1);

        cout << "Case #" << tc << endl
             << ans << endl;
    }
    return 0;
}
