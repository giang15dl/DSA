#include <iostream>

using namespace std;

int t, tc, ans;
int a[4][4];
char s[4][4];

int check() {
    int i, j, tmp = a[0][0];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a[i][j] != tmp)
                return 0;
        }
    }
    return 1;
}

void doiMau(int x) {
    int i = x / 4;
    int j = x % 4;
    a[i][j] *= -1;
    if (i + 1 < 4)
        a[i + 1][j] *= -1;
    if (i - 1 >= 0)
        a[i - 1][j] *= -1;
    if (j + 1 < 4)
        a[i][j + 1] *= -1;
    if (j - 1 >= 0)
        a[i][j - 1] *= -1;
}

void backtrack(int pos, int d) {
    int dem = d;
    if (check()) {
        if (dem < ans)
            ans = dem;
        return;
    }
    for (int x = pos; x < 16; x++) {
        doiMau(x);
        backtrack(x + 1, dem + 1);
        doiMau(x);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int i, j;
        for (i = 0; i < 4; i++) {
            cin >> s[i];
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (s[i][j] == 'b')
                    a[i][j] = 1;
                else
                    a[i][j] = -1;
            }
        }
        ans = 100000001;
        backtrack(0, 0);
        cout << "Case #" << tc << endl;
        if (ans == 100000001)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}