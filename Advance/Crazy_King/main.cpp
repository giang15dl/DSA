#include <iostream>

const int N = 100;
const int M = 100;
const int K = 1500; // Maximum number of knights in a chessboard

// Direction a Knight can move
const int d1i[8] = {-2,-2,2,2,-1,1,-1,1};
const int d1j[8] = {1,-1,1,-1,2,2,-2,-2};

// Direction a King can move
const int d2i[8] = {-1,-1,-1,1,1,1,0,0};
const int d2j[8] = {-1,0,1,-1,0,1,-1,1};

template<typename T, int MAX>
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

struct Point {
    int i,j;

    Point() : i(0), j(0) {}
    Point(int i, int j) : i(i), j(j) {}

    bool operator==(const Point &rhs) const {
        return i == rhs.i && j == rhs.j;
    }

    bool valid(int n, int m) const {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};

int solve(char (&)[N][M], int, int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    //freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> m >> n;

        char mat[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << solve(mat, n, m) << endl;
    }

    return 0;
}

int solve(char (&mat)[N][M], int n, int m) {
    int cnt = 0; // count number of knights the in the chessboard (Z)
    Point Knights[K];
    Point A, B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'Z')
                Knights[cnt++] = Point(i, j);

            else if (mat[i][j] == 'A')
                A = Point(i, j);

            else if (mat[i][j] == 'B')
                B = Point(i, j);
        }
    }

    int marked[N][M] = {}; // mark where the knights can reach in 1 move.
    for (int k = 0; k < cnt; k++) {
        Point prev = Knights[k];
        marked[prev.i][prev.j] = 1;
        for (int d = 0; d < 8; d++) {
            Point next(prev.i + d1i[d], prev.j + d1j[d]);
            if (next.valid(n, m) && mat[next.i][next.j] == '.' && !marked[next.i][next.j])
                marked[next.i][next.j] = 1;
        }
    }

    int visited[N][M] = {}; // Mark the position and the distance the king has gone through
    Queue<Point, 10000> q;
    int ans = -1;
    q.push(A);
    visited[A.i][A.j] = 1;

    while (!q.empty()) {
        Point prev = q.pop();
        for (int d = 0; d < 8; d++) {
            Point next(prev.i + d2i[d], prev.j + d2j[d]);
            if (next.valid(n, m) && !marked[next.i][next.j] && !visited[next.i][next.j]) {
                visited[next.i][next.j] = visited[prev.i][prev.j] + 1;
                if (next == B) {
                    ans = visited[next.i][next.j] - 1;
                    break;
                }
                q.push(next);
            }
        }
    }

    return ans;
}
