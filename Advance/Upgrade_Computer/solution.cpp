#include <iostream>

using namespace std;

int t, tc, n, m, cm, ans;
int gg[50], gm[50], lk[50][30], tbc[50], dm[50];

void backtrack(int x, int tien) {
    if (x == cm + 1) {
        if (ans > tien)
            ans = tien;
        return;
    }
    int tb = tbc[x];
    if (dm[tb] == 0) {
        for (int j = 0; j <= 1; j++) {
            if (j == 0) {
                dm[tb]++;
                backtrack(x + 1, tien + gg[tb]);
                dm[tb]--;
            } else {
                for (int k = 1; k <= m; k++) {
                    if (lk[k][tb]) {
                        for (int i = 0; i <= n; i++) {
                            if (lk[k][i])
                                dm[i]++;
                        }
                        backtrack(x + 1, tien + gm[k]);
                        for (int i = 1; i <= n; i++) {
                            if (lk[k][i])
                                dm[i]--;
                        }
                    }
                }
            }
        }
    } else {
        backtrack(x + 1, tien);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        int i, j, x, l;
        for (i = 1; i <= n; i++) {
            cin >> gg[i];
            dm[i] = 0;
        }
        cin >> m;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                lk[i][j] = 0;
            }
        }
        for (i = 1; i <= m; i++) {
            cin >> gm[i];
            cin >> x;
            for (j = 1; j <= x; j++) {
                cin >> l;
                lk[i][l] = 1;
            }
        }
        cin >> cm;
        for (i = 1; i <= cm; i++)
            cin >> tbc[i];
        ans = 1000000002;
        backtrack(1, 0);

        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}