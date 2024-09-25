#include "queue.hpp"
#include <iostream>

const int N = 1000;

bool isBipartiteUtil(bool (&G)[N][N], int V, int src, int (&colorArr)[N]);

void solve(bool (&G)[N][N], int V);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int nodes, edges;
        cin >> nodes >> edges;
        bool adj[N][N] = {};
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << "#" << t + 1 << " ";

        solve(adj, nodes);
    }

    return 0;
}

void solve(bool (&G)[N][N], int V) {
    // Create a color array to store colors assigned to all vertices.
    // Vertex/ number is used as index in this array.
    // The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'.
    // The value 1 is used to indicate first color is assigned;
    // and value 0 indicates second color is assigned.
    int colorArr[N] = {};
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    for (int i = 0; i < V; i++) {
        if (colorArr[i] == -1) {
            if (!isBipartiteUtil(G, V, i, colorArr)) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << colorArr[i];
    cout << endl;
}

bool isBipartiteUtil(bool (&G)[N][N], int V, int src, int (&colorArr)[N]) {
    colorArr[src] = 0;
    Queue<int> q;
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

            if (colorArr[v] == -1) {
                // Assign alternate color to this adjacent v of u if is not yet colored.
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
                continue;
            }

            // An edge from u to v exists and destination v is colored with same color as u
            else if (colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with alternate color
    return true;
}
