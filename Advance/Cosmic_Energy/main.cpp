#include <iostream>

#define EPSILON 1e-6
#define INF 1.0e9

const int N = 50;

double pow(double, double);
double f(int, int, int, double);
double solve(int, int, int, double);
int minKey(double (&)[N], bool (&)[N], int);
double primMST(double (&)[N][N], int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n;
        cin >> n;

        int a, b, c;
        cin >> a >> b >> c;

        int adj[N][N] = {};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];

        double adj_solved[N][N] = {};
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adj_solved[i][j] = solve(a, b, c, adj[i][j]);
                adj_solved[j][i] = adj_solved[i][j];
            }
        }

        cout << "#" << ti + 1 << " " << primMST(adj_solved, n) << endl;
    }

    return 0;
}

double primMST(double (&adj)[N][N], int n) {
    double key[N] = {};
    bool vst[N] = {};

    for (int i = 0; i < n; i++)
        key[i] = INF;

    key[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minKey(key, vst, n);
        vst[u] = 1;

        for (int v = 0; v < n; v++)
            if (!vst[v] && u != v && key[v] > adj[u][v])
                key[v] = adj[u][v];
    }

    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += key[i];

    return ans;
}

int minKey(double (&arr)[N], bool (&vst)[N], int n) {
    double min = INF;
    int min_idx = -1;

    for (int i = 0; i < n; i++)
        if (!vst[i] && arr[i] < min)
            min = arr[i], min_idx = i;

    return min_idx;
}

double pow(double base, double exp) {
    double res = 1;
    for (int i = 0; i < exp; i++)
        res *= base;

    return res;
}

double f(int a, int b, int c, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c;
}

double solve(int a, int b, int c, double rhs) {
    double left = 0, right = rhs;

    while (right - left > EPSILON) {
        double mid = left + (right - left) / 2;
        double y = f(a, b, c, mid);
        if (y == rhs)
            return mid;
        if (y > rhs)
            right = mid;
        else
            left = mid;
    }

    return left;
}
