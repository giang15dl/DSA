#define _CRT_SECURE_NO_WARNINGS
#include "graph.hpp"
#include <iostream>

using namespace std;

const int T = 10;
const int MAX_NODES = 100;

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    for (int t = 0; t < T; t++) {
        int ti;
        cin >> ti;
        int N;
        cin >> N;

        Graph<int, MAX_NODES> g(MAX_NODES);

        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g.add_edge(u, v);
        }

        cout << "#" << t + 1 << " " << g.DFS(0, 99) << endl;
    }

    return 0;
}
