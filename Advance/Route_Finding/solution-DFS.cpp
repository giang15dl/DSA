#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#define SIZE 109 // SIZE is large enough to never be full

int map[SIZE][SIZE];
int visit[SIZE];

int T, tc;
int N, Answer;

int i, j;

void reset() {
    Answer = 0;
    // reset input map
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            map[i][j] = 0;
        }
    }
    // reset visit
    for (i = 0; i < 100; i++) {
        visit[i] = 0;
    }
}

// Implement DFS with Recursive
void DFS_Recursive(int u) {
    // Stop codition
    if (u == 99) {
        Answer = 1;
    } else {
        // Mark visited
        visit[u] = 1;

        // Recursive
        for (int w = 0; w < 100; w++) { // check all vertexes that can go from vertex u
            if (map[u][w] == 1 && visit[w] == 0) {
                DFS_Recursive(w);
            }
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);

    for (tc = 1; tc <= 10; tc++) {

        reset();

        // Read data in
        cin >> T >> N;
        for (int n = 0; n < N; n++) {
            cin >> i >> j;
            map[i][j] = 1;
            // map[j][i] = 1; // use if matrix without direction
        }

        DFS_Recursive(0);

        // Print the answer to standard output(screen).
        cout << "#" << tc << " " << Answer << endl;
    }

    _getch();
    return 0; // Your program should return 0 on normal termination.
}