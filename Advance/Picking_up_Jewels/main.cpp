#include <iostream>

const int MAX_N = 10; //10

const int di[4] = {-1,0,1,0};
const int dj[4] = {0,1,0,-1};

int solve(int (&maze)[MAX_N][MAX_N], const int N);

void backtrack(int (&maze)[MAX_N][MAX_N], int (&visited)[MAX_N][MAX_N], const int N, int &ans, int jews = 0, int r = 0, int c = 0);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        int maze[MAX_N][MAX_N] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> maze[i][j];
        cout << solve(maze, N) << endl;
    }

    return 0;
}

int solve(int (&maze)[MAX_N][MAX_N], const int N) {
    int visited[MAX_N][MAX_N] = {};
    int ans = 0;

    visited[0][0] = 1;
    backtrack(maze, visited, N, ans, maze[0][0]);
    return ans;
}

void backtrack(int (&maze)[MAX_N][MAX_N], int (&visited)[MAX_N][MAX_N], const int N, int &ans, int jews, int r, int c) {
    if (r == N-1 && c == N-1) {
        if (jews > ans)
            ans = jews;
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nr = r + di[d];
        int nc = c + dj[d];
        if (nr >= 0 && nc >=0 && nr < N && nc < N && !visited[nr][nc] && maze[nr][nc] != 1) {
            visited[nr][nc] = 1;
            if (maze[nr][nc] == 0)
                backtrack(maze, visited, N, ans, jews, nr, nc);
            else if(maze[nr][nc] = 2)
                backtrack(maze, visited, N, ans, jews + 1, nr, nc);
            visited[nr][nc] = 0;
        }
    }
}