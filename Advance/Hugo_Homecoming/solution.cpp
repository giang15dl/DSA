#include <iostream>

using namespace std;

int t, tc, n, ans;
int bl[25], cp[25], quan[25], ld[25];

void backTrack(int i, int coin, int q) {
    if (i >= n) {
        if (coin < ans)
            ans = coin;
        return;
    }
    if (coin > ans)
        return;
    for (int x = 0; x < 3; x++) {
        if (x == 0) {
            backTrack(i + 1, coin + cp[i], q);
        } else if (x == 1) {
            quan[i] = bl[i];
            ld[i] = 3;
            backTrack(i + 1, coin + cp[i] * 2, q + bl[i]);
            quan[i] = 0;
            ld[i] = 0;
        } else if (x == 2 && q >= bl[i]) {
            int qt = bl[i], qq = 0;
            int tmp1[25], tmp2[25];
            for (int j = 0; j < i; j++) {
                tmp1[j] = quan[j];
                tmp2[j] = ld[j];
            }
            for (int j = 0; j < i; j++) {
                if (ld[j] > 0 && quan[j] > 0) {
                    if (qt > quan[j]) {
                        qt -= quan[j];
                        quan[j] = 0;
                    } else {
                        quan[j] -= qt;
                        qt = 0;
                    }
                    ld[j]--;
                    if (ld[j] <= 0) {
                        quan[j] = 0;
                    }
                }
            }
            for (int j = 0; j < i; j++) {
                qq += quan[j];
            }
            backTrack(i + 1, coin, qq);
            for (int j = 0; j < i; j++) {
                quan[j] = tmp1[j];
                ld[j] = tmp2[j];
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        int i;
        for (i = 0; i < n; i++) {
            cin >> bl[i]; // binh linh
            cin >> cp[i]; // chi phi
            quan[i] = 0;
            ld[i] = 0;
        }
        ans = 100000000;
        backTrack(0, 0, 0);
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}
