#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N_MAX = 500; // Should be 500
const int M_MAX = 500; // Should be 500

const int di[4] = {0, -1, 1, 0};
const int dj[4] = {-1, 0, 0, 1};

class Point {
public:
    int i, j;

    Point();
    Point(int i, int j);
    bool operator==(const Point &rhs) const;
};

template <typename T = int, unsigned int MAX = 500>
class Queue {
public:
    Queue();
    ~Queue();

    bool isFull();
    bool isEmpty();
    void enQueue(T item);
    T deQueue();

    T peek();
    int size();

private:
    T items[MAX];
    int front, rear, count;
};

bool playable(int (&mat)[N_MAX][M_MAX], int n, int m, Point src, Point dst);
bool BFS(int (&mat)[N_MAX][M_MAX], int n, int m, Point src, Point dst);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;

        static int mat[N_MAX][M_MAX] = {};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Point start(r1, c1);
        Point exit(r2, c2);

        if (playable(mat, n, m, start, exit))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

bool playable(int (&mat)[N_MAX][M_MAX], int n, int m, Point src, Point dst) {
    int count = 0;

    for (int d = 0; d < 4; d++) {
        int ni = dst.i + di[d];
        int nj = dst.j + dj[d];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 1)
            count++;
    }

    if (count >= 2 || (count >= 1 && mat[dst.i][dst.j] == 0)) {
        if (BFS(mat, n, m, src, dst))
            return true;
        else
            return false;
    }

    return false;
}

bool BFS(int (&mat)[N_MAX][M_MAX], int n, int m, Point src, Point dst) {
    Queue<Point> q;
    q.enQueue(src);

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        for (int d = 0; d < 4; d++) {
            int ni = t.i + di[d];
            int nj = t.j + dj[d];
            Point next(ni, nj);
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (mat[ni][nj] == 1) {
                    mat[ni][nj]--;
                    q.enQueue(next);
                }
                if (next == dst && mat[next.i][next.j] == 0)
                    return true;
            }
        }
    }

    return false;
}

Point ::Point() : i(0), j(0) {}

Point ::Point(int i, int j) : i(i), j(j) {}

bool Point::operator==(const Point &rhs) const {
    return (this->i == rhs.i && this->j == rhs.j);
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue() {
    front = -1;
    rear = -1;
    count = 0;
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::~Queue() {
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isEmpty() {
    if (front == rear)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isFull() {
    if (front == 0 && rear == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::enQueue(T item) {
    if (isFull())
        return;
    rear++;
    count++;
    items[rear] = item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::deQueue() {
    T item;
    if (isEmpty())
        return item;

    front++;
    count--;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::peek() {
    T item;
    if (isEmpty())
        return item;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
int Queue<T, MAX>::size() {
    return count;
}