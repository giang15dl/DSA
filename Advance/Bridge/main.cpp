#include "point.hpp"
#include <iostream>

const int N = 20; // Length of the bridge should be no more than 20
const int M = 5;  // Width of the bridge should always be 5

using namespace std;
void DFS(const int (&)[N][M], const int, const int, const Point, int &, int = 0, int = 1);

int solve(int (&)[N][M], int n, int m);

int main() {
    freopen("input.txt", "r", stdin);
    int T; // the total number of test case
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n; // Length of the bridge
        cin >> n;
        int m = M;

        int bridge[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> bridge[i][j];

        cout << "#" << tc + 1 << " " << solve(bridge, n, m) << endl;
    }
    return 0;
}

int solve(int (&mat)[N][M], int n, int m) {
    int ans = -1;
    Point start(n, m / 2);

    DFS(mat, n, m, start, ans);
    return ans;
}

void DFS(const int (&mat)[N][M], const int n, const int m, const Point curr, int &ans, int coin, int check) {
    static const Point d[3] = {Point(-1, 0), Point(-1, -1), Point(-1, 1)}; // Direction : up_straight, up_left, up_right.

    if (curr.i == 0 && ans < coin)
        ans = coin;

    for (int i = 0; i < 3; i++) {
        Point next = curr + d[i];
        if (!next.valid(n, m))
            continue;

        if (mat[next.i][next.j] != 2)
            DFS(mat, n, m, next, ans, coin + mat[next.i][next.j], check);

        else if (check) {
            check = 0;
            DFS(mat, n, m, next, ans, coin, check);
            check = 1;
        }
    }
}
