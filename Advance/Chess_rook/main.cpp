#include <iostream>

const int N = 5;

// left, up, right, down
const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};

int solve(int (&mat)[N][N], int n);
void backtracking(int (&mat)[N][N], int n, int &ans, int count = 0);
bool Check(int (&mat)[N][N], int n, int r, int c);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        char s[N][N] = {};
        int mat[N][N] = {};
        for (int i = 0; i < n; i++)
            cin >> s[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = (s[i][j] == 'X') ? 1 : 0;

        cout << "Case #" << t + 1 << endl;
        cout << solve(mat, n) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][N], int n) {
    int ans = 0;
    backtracking(mat, n, ans);
    return ans;
}

void backtracking(int (&mat)[N][N], int n, int &ans, int count) {
    if (ans < count)
        ans = count;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0 && Check(mat, n, i, j)) {
                mat[i][j] = 2; // Place a rook
                backtracking(mat, n, ans, count + 1);
                mat[i][j] = 0; // Remove that rook
            }
        }
    }
}

bool Check(int (&mat)[N][N], int n, int i, int j) {
    for (int d = 0; d < 4; d++) {
        int ni = i;
        int nj = j;
        while (true) {
            ni += di[d];
            nj += dj[d];
            if (ni < 0 || nj < 0 || ni >= n || nj >= n)
                break;
            if (mat[ni][nj] == 1)
                break;
            if (mat[ni][nj] == 2)
                return false;
        }
    }

    return true;
}
