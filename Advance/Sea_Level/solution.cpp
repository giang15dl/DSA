#include <stdio.h>
#define MAX_N 100

int map[MAX_N][MAX_N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;

int rowQ[MAX_N * MAX_N];
int colQ[MAX_N * MAX_N];
int front, rear;

bool under[MAX_N][MAX_N];

bool visited[MAX_N][MAX_N];

int coveredCnt;
// Cho nước tràn từ điểm {r,c}, đếm số điểm bị nước tràn qua
void spreadWater(int r, int c, int level) {
    front = -1;
    rear = 0;
    rowQ[0] = r;
    colQ[0] = c;
    under[r][c] = true;
    ++coveredCnt;

    int nextR, nextC;
    while (front < rear) {
        r = rowQ[++front];
        c = colQ[front];
        for (int d = 0; d < 4; d++) {
            nextR = r + dy[d];
            nextC = c + dx[d];
            if (nextR < 0 || nextR == N || nextC < 0 || nextC == M || under[nextR][nextC] || map[nextR][nextC] > level)
                continue;
            ++coveredCnt;
            under[nextR][nextC] = true;
            rowQ[++rear] = nextR;
            colQ[rear] = nextC;
        }
    }
}

// Dâng nước đến level, đếm số điểm bị ngập nước
void raiseWater(int level) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            under[i][j] = false;
    int coveredCnt = 0;
    // Kiểm tra từ 4 viền
    for (int i = 0; i < N; i++) {
        if (map[i][0] <= level && !under[i][0])
            spreadWater(i, 0, level);
        if (map[i][M - 1] <= level && !under[i][M - 1])
            spreadWater(i, M - 1, level);
    }
    for (int i = 1; i < M - 1; i++) {
        if (map[0][i] <= level && !under[0][i])
            spreadWater(0, i, level);
        if (map[N - 1][i] <= level && !under[N - 1][i])
            spreadWater(N - 1, i, level);
    }
}

int highestR, highestC;
bool isSplit() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;
    // BFS để đếm số ô là đất liền, bắt đầu từ ô cao nhất vì đây luôn là đất liền
    // Nếu số ô đất liền + số ô ngập nước = N * M => không bị chia cắt
    // Nếu không, còn ô đất liền ở đâu đó mà không BFS tới được => bị chia cắt
    front = -1;
    rear = 0;
    rowQ[0] = highestR;
    colQ[0] = highestC;
    visited[highestR][highestC] = true;
    int r, c, nextR, nextC;
    int landCnt = 1;
    while (front < rear) {
        r = rowQ[++front];
        c = colQ[front];
        for (int d = 0; d < 4; d++) {
            nextR = r + dy[d];
            nextC = c + dx[d];
            if (nextR < 0 || nextR == N || nextC < 0 || nextC == M || visited[nextR][nextC])
                continue;
            if (!under[nextR][nextC]) {
                ++landCnt;
                visited[nextR][nextC] = true;
                rowQ[++rear] = nextR;
                colQ[rear] = nextC;
            }
        }
    }
    if (landCnt + coveredCnt == M * N)
        return false;
    return true;
}

int main() {
    int tc = 0;
    freopen("nuocbien_input.txt", "r", stdin);
    int lowest, highest;
    while (true) {
        scanf("%d%d", &N, &M);
        if (N == 0 && M == 0)
            break;
        tc++;
        lowest = 1000000;
        highest = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] > highest) {
                    highestR = i;
                    highestC = j;
                    highest = map[i][j];
                }
                if (map[i][j] && map[i][j] < lowest)
                    lowest = map[i][j];
            }
        }
        int m;
        for (m = lowest; m < highest; m++) {
            coveredCnt = 0;
            raiseWater(m);
            if (isSplit())
                break;
        }
        if (m == highest)
            printf("Case %d: Island never splits.\n", tc);
        else
            printf("Case %d: Island splits when ocean rises %d feet.\n", tc, m);
    }
    return 0;
}