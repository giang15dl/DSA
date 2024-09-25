#include <iostream>
using namespace std;

const int N = 100;

int solve(int (&)[N][N], int);

int minKey(int (&)[N], int (&)[N], int);

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int n;
        cin >> n;

        int adj[N][N];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];

        cout << "Case #" << tc + 1 << "\n"
             << solve(adj, n) << endl;
    }

    return 0;
}

int solve(int (&adj)[N][N], int n) {
    int key[N] = {};
    int visted[N] = {};

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX;

    key[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minKey(key, visted, n);
        visted[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visted[v] && v != u && key[v] > adj[u][v])
                key[v] = adj[u][v];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += key[i];

    return sum;
}

int minKey(int (&arr)[N], int (&visited)[N], int n) {
    int min = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < n; i++)
        if (!visited[i] && arr[i] < min)
            min = arr[i], min_idx = i;

    return min_idx;
}