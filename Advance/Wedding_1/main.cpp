#include <iostream>

const int N = 20;

int solve(int(&)[N][N], int, int, int);

void DFS(int(&)[N][N], int, int, int, int (&)[N], int (&)[N], int &);

using namespace std;
int main(int argc, char **argv) {
    const char *inf = (argc > 1) ? argv[1] : "input.txt"; 
    freopen(inf, "r", stdin);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n, m;
        cin >> n >> m;

        int s, d; // start, destination
        cin >> s >> d;
        s--;
        d--;

        int adj[N][N] = {};

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
        }

        cout << solve(adj, n, s, d) << endl << endl;
    }
    return 0;
}

int solve(int(&adj)[N][N], int n, int s, int d){
    int visited[N] = {};
    int cntTime[N] = {};
    int cntRoad = 0;

    visited[s] = 1;
    DFS(adj, n, s, d, visited, cntTime, cntRoad);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i != s && i != d && cntTime[i] == cntRoad)
            ans++;

    return ans;
}

void DFS(int(&adj)[N][N], int n, int s, int d, int (&visited)[N],int (&cntTime)[N], int &cntRoad){
    if (s == d) {
        cntRoad++;
        for (int i = 0; i < n; i++)
            if (visited[i])
                cntTime[i]++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[s][i] && !visited[i]) {
            visited[i] = 1;
            DFS(adj, n, i, d, visited, cntTime, cntRoad);
            visited[i] = 0;
        }
    }
}
