#include <iostream>

const int N = 20;

const int s = 0;
const int d = 1;

int solve(int(&)[N][N], int);

int countNode(int(&)[N], int(&)[N], int);

void DFS2(int(&)[N][N], int, int(&)[N], int(&)[N], int , int &);
void DFS1(int(&)[N][N], int, int(&)[N], int(&)[N], int , int &);

using namespace std;
int main(int argc, char **argv) {
    const char *inf = (argc > 1) ? argv[1] : "input.txt"; 
     //freopen(inf, "r", stdin);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n, m;
        cin >> n >> m;

        int adj[N][N] = {};

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
        }

        cout << solve(adj, n) << endl;
    }
    return 0;
}

int solve(int(&adj)[N][N], int n){
    int visited1[N] = {};
    int visited2[N] = {};

    int ans = N;
    visited2[0] = 1;
    DFS2(adj, n, visited1, visited2, s, ans);
    visited2[0] = 0;

    return ans;
}

void DFS2(int(&adj)[N][N], int n, int(&visited1)[N], int(&visited2)[N], int curr, int &ans) {
    if (countNode(visited1 , visited2, n) >  ans)
        return;

    if (curr == d) {
        visited1[curr] = 1;
        DFS1(adj, n, visited1, visited2, curr, ans);
        visited1[curr] = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[curr][i] && !visited2[i]) {
            visited2[i] = 1;
            DFS2(adj, n, visited1, visited2, i, ans);
            visited2[i] = 0;
        }
    }
}

void DFS1(int(&adj)[N][N], int n, int(&visited1)[N], int(&visited2)[N], int curr, int &ans) {
    if (countNode(visited1 , visited2, n) >  ans)
        return;

    if (curr == s) {
        int nodes = countNode(visited1, visited2, n);
        if (nodes < ans)
            ans = nodes;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[curr][i] && !visited1[i]){
            visited1[i] = 1;
            DFS1(adj, n, visited1, visited2, i, ans);
            visited1[i] = 0;
        }
    }
}

int countNode(int(&visited1)[N], int(&visited2)[N], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (visited1[i] + visited2[i] > 0)
            cnt++;

    return cnt;
}