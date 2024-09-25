#include <iostream>

using namespace std;

int t, tc, k;
int a[25][10][10], map[8][8], ans;

int checkNgang(int i, int j) {
    for (int x = 0; x < 8; x++)
        if (map[i][x] || map[x][j])
            return 0;
            
    return 1;
}

int checkCheo(int i, int j) {
    int x = i, y = j;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return 0;
        x--;
        y--;
    }
    x = i + 1;
    y = j + 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return 0;
        x++;
        y++;
    }
    x = i - 1;
    y = j + 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return 0;
        x--;
        y++;
    }
    x = i + 1;
    y = j - 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return 0;
        x++;
        y--;
    }
    return 1;
}

void initMap() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            map[i][j] = 0;
}

void queen(int m, int i, int tong) {
    int diem = tong;
    if (i == 8) {
        if (diem > ans)
            ans = diem;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (checkNgang(i, x) && checkCheo(i, x)) {
            map[i][x] = 1;
            diem += a[m][i][x];
            queen(m, i + 1, diem);
            map[i][x] = 0;
            diem -= a[m][i][x];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> k;
        int x, i, j;
        for (x = 0; x < k; x++)
            for (i = 0; i < 8; i++)
                for (j = 0; j < 8; j++)
                    cin >> a[x][i][j];

        cout << "Case #" << tc << endl;
        for (x = 0; x < k; x++) {
            ans = 0;
            initMap();
            queen(x, 0, 0);
            cout << ans << endl;
        }
    }
    return 0;
}