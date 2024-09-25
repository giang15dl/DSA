#include <iostream>

const int N = 100; // MAX n
const int H = 110; // MAX height diff
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

template<typename T, int MAX = 10000>
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
    int i, j;

    Point() : i(0), j(0) {}

    Point(int i, int j) : i(i), j(j) {}

    bool operator==(const Point &rhs) const {
        return i == rhs.i && j == rhs.j;
    }

    bool valid(int n) const {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

};

int solve(const int (&)[N][N], const int);

bool BFS(const int (&)[N][N], const int, const Point &, const Point &, const int, const int);

int abs(int);

using namespace std;
int main(int argc, char **argv) {
    const char *in = (argc > 1) ? argv[1] : "input.txt"; 
    //freopen(in, "r", stdin);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++) {
        int n;
        cin >> n;

        int mat[N][N] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        cout << "#" << ti + 1 << " " << solve(mat, n) << endl;
    }
    return 0;
}

int solve(const int (&mat)[N][N], const int n) {
    Point s(0,0), d(n-1, n-1);

    int max = 0, min = H;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] < min)
                min = mat[i][j];
            if (mat[i][j] > max)
                max = mat[i][j];
        }
    }

    int left = 0;
    int right = max - min;

    while (left <= right) {
        int mid = (left + right) / 2;
        bool flag = false;
        for (int i = min; i <= max - mid; i++) {
            flag = BFS(mat, n, s, d, i, i + mid);
            if (flag)
                break;
        }
        if (flag)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

bool BFS(const int (&mat)[N][N], const int n, const Point &src, const Point &dst, int left, const int right) {
    int visited[N][N] = {};
    Queue<Point> q;
    q.push(src);
    visited[src.i][src.j] = 1;

    if (mat[src.i][src.j] < left || mat[src.i][src.j] > right)
        return false;

    while (!q.empty()) {
        Point curr = q.pop();
        if (curr == dst)
            return true;
        for (int d = 0; d < 4; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            if (next.valid(n) && mat[next.i][next.j] <= right && mat[next.i][next.j] >= left && !visited[next.i][next.j]) {
                visited[next.i][next.j] = 1;
                q.push(next);
            }

        }
    }

    return false;
}

//bool BFS(const int (&mat)[N][N], const int n, const Point &src, const Point &dst, int h) {
//    int visited[N][N] = {};
//    Queue<Point> q;
//    q.push(src);
//    visited[src.i][src.j] = 1;
//    int max_diff = 0;
//
//    while (!q.empty()) {
//        Point curr = q.pop();
//        if (curr == dst)
//            return true;
//        for (int d = 0; d < 4; d++) {
//            Point next(curr.i + di[d], curr.j + dj[d]);
//            if (!next.valid(n) || visited[next.i][next.j])
//                continue;
//            int diff = abs(mat[next.i][next.j] - mat[src.i][src.j]);
//            
//            if (diff > max_diff)
//                max_diff = diff;
//
//            if (max_diff > h)
//                continue;
//
//            visited[next.i][next.j] = 1;
//            q.push(next);
//        }
//    }
//
//    return false;
//}

int abs(int x) {
    return (x < 0) ? -x : x;
}
