#include <iostream>

const int N = 7;
const int M = 8;
const int NUM = 28; // Number of types of domino

int solve(int (&)[N][M]);

void backtrack(int (&)[N][M], int (&)[N][M], int (&)[N][N], int &, int = 0);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int mat[N][M] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        cout << "#" << t + 1 << " " << solve(mat) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][M]) {
    int vst[N][M] = {};
    int dom[N][N] = {};
    int ans = 0;
    backtrack(mat, vst, dom, ans);
    return ans;
}

void backtrack(int (&mat)[N][M], int (&vst)[N][M], int (&dom)[N][N], int &ans, int num) {
    if (num == NUM) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vst[i][j])
                continue; // Skip this loop if already visited.

            // Place Domino Horizontally
            if (j < M - 1 && !vst[i][j + 1] && !dom[mat[i][j]][mat[i][j + 1]]) {
                vst[i][j] = vst[i][j + 1] = 1;
                dom[mat[i][j]][mat[i][j + 1]] = dom[mat[i][j + 1]][mat[i][j]] = 1;
                backtrack(mat, vst, dom, ans, num + 1);
                dom[mat[i][j]][mat[i][j + 1]] = dom[mat[i][j + 1]][mat[i][j]] = 0;
                vst[i][j] = vst[i][j + 1] = 0;
            }

            // Place Domino Vertically
            if (i < N - 1 && !vst[i + 1][j] && !dom[mat[i][j]][mat[i + 1][j]]) {
                // could be assign to one, not neccessary be two.
                // Just needed to see which one is placed vertically or horizontally
                vst[i][j] = vst[i + 1][j] = 2;
                dom[mat[i][j]][mat[i + 1][j]] = dom[mat[i + 1][j]][mat[i][j]] = 1;
                backtrack(mat, vst, dom, ans, num + 1);
                dom[mat[i][j]][mat[i + 1][j]] = dom[mat[i + 1][j]][mat[i][j]] = 0;
                vst[i][j] = vst[i + 1][j] = 0;
            }

            return;
        }
    }
}