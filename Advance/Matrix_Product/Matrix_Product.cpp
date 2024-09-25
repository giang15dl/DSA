#include <iostream>

using namespace std;

#define MOD 100000007

int t, tc, n;
long m;
long long a[101][101], ans[101][101], b[101][101];

void nhanMT(long long a1[101][101], long long a2[101][101]) {
    int i, j, x;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int tmp = 0;
            for (x = 0; x < n; x++) {
                tmp = (tmp + (a1[i][x] * a2[x][j]) % MOD) % MOD;
            }
            b[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = b[i][j];
        }
    }
}

void matrixProduct(long k) {
    if (k == 1)
        return;
    if (k % 2) {
        matrixProduct((k - 1) / 2);
        nhanMT(ans, ans);
        nhanMT(ans, a);
    } else {
        matrixProduct(k / 2);
        nhanMT(ans, ans);
    }
}

int main() {
    freopen("MatrixProduct1_input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n >> m;
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
                ans[i][j] = a[i][j];
            }
        }
        matrixProduct(m);
        cout << "Case #" << tc << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
