#include "graph.hpp"
#include <iostream>
using namespace std;

const int SIZE = 100;

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    const char *log = "log.txt";
    freopen(input, "r", stdin);
    freopen(log, "w", stderr);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int nodes, edges;
        cin >> nodes >> edges;

        Graph<int, SIZE> g(nodes);

        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            g.add_edge(u - 1, v - 1);
        }

        bool hasCycles = g.hasCycle();
        cout << "Case #" << tc + 1 << "\n"
             << hasCycles << endl;
    }

    return 0;
}