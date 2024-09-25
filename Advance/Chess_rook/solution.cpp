#include <iostream>

using namespace std;

int t, tc, n, ans;
int a[5][5];
char s[5][5];

int checkDoc(int i, int j) {
    int x = i;
    while (x < n) {
        if (a[x][j] == 1)
            break;
        if (a[x][j] == 2)
            return 0;
        x++;
    }
    x = i - 1;
    while (x >= 0) {
        if (a[x][j] == 1)
            break;
        if (a[x][j] == 2)
            return 0;
        x--;
    }
    return 1;
}
int checkNgang(int i, int j) {
    int x = j;
    while (x < n) {
        if (a[i][x] == 1)
            break;
        if (a[i][x] == 2)
            return 0;
        x++;
    }
    x = j - 1;
    while (x >= 0) {
        if (a[i][x] == 1)
            break;
        if (a[i][x] == 2)
            return 0;
        x--;
    }
    return 1;
}

void backTrack(int d) {
    int dem = d;
    if (ans < dem)
        ans = dem;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (a[x][y] != 1) {
                if (checkNgang(x, y) && checkDoc(x, y)) {
                    a[x][y] = 2;
                    dem++;
                    backTrack(dem);
                    dem--;
                    a[x][y] = 0;
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        int i, j;
        for (i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (s[i][j] == '.')
                    a[i][j] = 0;
                else if (s[i][j] == 'X')
                    a[i][j] = 1;
            }
        }
        ans = 0;
        backTrack(0);
        cout << "Case #" << tc << endl;
        cout << ans << endl;
    }
    return 0;
}