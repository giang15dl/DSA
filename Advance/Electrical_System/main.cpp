#include <iostream>

const int N = 1000;

template<typename T, int MAX = 100000>
class Queue {
public:
    Queue() : front(-1), rear(-1) {}

    void push(T a) {
        data[++rear] = a;
    }

    T pop() {
        return data[++front];
    }

    bool empty() const {
        return front == rear;
    }

private:
    int front, rear;
    T data[MAX];
};

int solve(int (&)[N][N], int (&)[N], int, int);

int maxIndex(int (&)[N], int);

int adj[N][N] = {};

using namespace std;
int main(int argc, char **argv) {
    const char *in = (argc > 1) ? argv[1] : "input.txt"; 
    freopen(in, "r", stdin);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n, m, h; 
        cin >> n >> m >> h;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;

        int lst[N] = {}; // list of island that has electrical generator;

        for (int i = 0; i < m; i++)
            cin >> lst[i];

        for (int i = 0; i < h; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << solve(adj, lst, n, m) << endl;
    }
    return 0;
}

int solve(int (&adj)[N][N], int (&lst)[N], int n, int m) {
    int visited[N] = {};

    for (int i = 0; i < n; i++)
        visited[i] = INT_MAX;

    for (int i = 0; i < m; i++)
        visited[lst[i]] = 0;



    for (int i = 0; i < m; i++) {
        int start = lst[i];
        Queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int u = q.pop();
            for (int v = 0; v < n; v++) {
                if (!adj[u][v])
                    continue;
                if (visited[v] == INT_MAX || visited[v] > visited[u] + 1) {
                    visited[v] = visited[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    return maxIndex(visited, n);
}

int maxIndex(int (&arr)[N], int n) {
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i], index = i;

    return index;
}