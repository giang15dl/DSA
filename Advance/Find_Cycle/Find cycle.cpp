#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define SIZE 100
int Answer, N;
int stack[SIZE], visited[SIZE], top;
int matranlk[SIZE][SIZE];
int start;

bool push(int x) {
    if (top == SIZE - 1)
        return false;
    stack[top++] = x;
    return true;
}

int pop() {
    if (top > 0)
        return stack[--top];
    return -1;
}

void DFS_Stack() {
    push(start);
    while (top && !Answer) {
        int v = pop();
        visited[v] = 1;
        for (int i = 1; i <= N; i++) {
            if (matranlk[v][i]) {
                if (!visited[i])
                    push(i);
                else if (i == start) {
                    Answer = 1;
                    break;
                }
            }
        }
    }
}

void DFS_Recursive(int u) {
    if (Answer) {
        return;
    } else {
        visited[u] = 1;
        for (int w = 1; w <= N; w++) {
            if (matranlk[u][w]) {
                if (!visited[w])
                    DFS_Recursive(w);
                else if (w == start) {
                    Answer = 1;
                    break;
                }
            }
        }
    }
}

void resetVisit() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

int main(int argc, char **argv) {
    int test_case;
    int T, M;

    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;
        Answer = 0;
        top = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                matranlk[i][j] = 0;
        }

        int _start, _end;
        for (int i = 1; i <= M; i++) {
            cin >> _start >> _end;
            matranlk[_start][_end] = 1;
        }

        for (int i = 1; i <= N; i++) {
            resetVisit();
            start = i;
            // DFS_Stack();
            DFS_Recursive(i);
            if (Answer)
                break;
        }

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case << endl
             << Answer << endl;
    }
    return 0; // Your program should return 0 on normal termination.
}
