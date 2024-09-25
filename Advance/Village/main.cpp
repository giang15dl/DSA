#include "queue.hpp"
#include <iostream>

const int LIM = 300;
const int MAX_EDGE = 90000;

int regions, isolates, bridges;

// Start and Endpoint of an edge.
int edge[MAX_EDGE][2];

int BFS(const int (&adj)[LIM][LIM], int (&visited)[LIM], const int N, int v);
void CountRegionAndIsolate(const int (&adj)[LIM][LIM], const int N);
void CountBridge(int (&adj)[LIM][LIM], const int N, int (&edge)[MAX_EDGE][2], int edges);
bool IsConnected(const int (&adj)[LIM][LIM], const int N, int s, int e);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N; // Number of villages.
        cin >> N;
        int adj[LIM][LIM] = {};
        int edges = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> adj[i][j];
                if (adj[i][j] && i < j) {
                    edge[edges][0] = i;
                    edge[edges][1] = j;
                    edges++;
                }
            }
        }
        regions = isolates = bridges = 0;
        CountRegionAndIsolate(adj, N);
        CountBridge(adj, N, edge, edges);

        cout << regions << " " << isolates << " " << bridges << endl;
    }
    return 0;
}

int BFS(const int (&adj)[LIM][LIM], int (&visited)[LIM], const int N, int v) {
    int count = 1;
    Queue<int, LIM> q;
    q.push(v);
    visited[v] = 1;
    while (!q.empty()) {
        int t = q.pop();
        for (int i = 0; i < N; i++) {
            if (adj[t][i] && !visited[i]) {
                count++;
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return count;
}

void CountRegionAndIsolate(const int (&adj)[LIM][LIM], const int N) {
    int visited[LIM] = {};

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            regions++;
            if (BFS(adj, visited, N, i) == 1)
                isolates++;
        }
    }
}

bool IsConnected(const int (&adj)[LIM][LIM], const int N, int s, int e) {
    int visited[LIM] = {};
    Queue<int, LIM> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int t = q.pop();
        for (int i = 0; i < N; i++) {
            if (adj[t][i] && !visited[i]) {
                if (i == e)
                    return true;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return false;
}

void CountBridge(int (&adj)[LIM][LIM], const int N, int (&edge)[MAX_EDGE][2], int edges) {
    for (int i = 0; i < edges; i++) {
        adj[edge[i][0]][edge[i][1]] = adj[edge[i][1]][edge[i][0]] = 0; // Destroy the bridge
        if (!IsConnected(adj, N, edge[i][0], edge[i][1]))
            bridges++;
        adj[edge[i][0]][edge[i][1]] = adj[edge[i][1]][edge[i][0]] = 1; // Rebuild the bridge
    }
}
