#define _CRT_SECURE_NO_WARNINGS
#include "graph.hpp"
#include <iostream>
using namespace std;

const int SIZE = 100;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int N;
        cin >> N;

        Graph<int, SIZE> g(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> g(i, j);

        int mst = g.primMST();

        cout << "Case #" << tc + 1 << "\n"
             << mst << endl;
    }

    return 0;
}
