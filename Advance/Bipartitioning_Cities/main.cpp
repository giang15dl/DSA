#include "queue.hpp"
#include <iostream>

const int T = 12;
const int N = 1000;

bool isBipartiteUtil(int (&G)[N][N], int V, int src, int (&colorArr)[N]);

void solve(int (&G)[N][N], int V);

int adj[N][N] = {};
int color[N] = {};
Queue<int, 100000> q;

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    for (int t = 0; t < T; t++) {
        int vertices, edges;
        cin >> vertices >> edges;

        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;

        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << "#" << t + 1 << " ";
        solve(adj, vertices);
    }

    return 0;
}

void solve(int (&G)[N][N], int V) {
    // Create a color array to store colors assigned to all vertices.
    // Vertex/ number is used as index in this array.
    // The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'.
    // The value 1 is used to indicate first color is assigned;
    // and value 0 indicates second color is assigned.
    for (int i = 0; i < V; ++i)
        color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartiteUtil(G, V, i, color)) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (color[i] == 0)
            cout << i + 1 << " ";

    // cout << color[i];
    cout << endl;
}

bool isBipartiteUtil(int (&G)[N][N], int V, int src, int (&color)[N]) {
    color[src] = 0;

    q.clear();
    q.push(src);

    while (!q.empty()) {
        int u = q.pop();

        // Return false if there is a self-loop
        if (G[u][u])
            return false;

        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!G[u][v])
                continue; // Skip if an edge from u to v is not exists

            if (color[v] == -1) {
                // Assign alternate color to this adjacent v of u if is not yet colored.
                color[v] = 1 - color[u];
                q.push(v);
                continue;
            }

            // An edge from u to v exists and destination v is colored with same color as u
            else if (color[v] == color[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with alternate color
    return true;
}
