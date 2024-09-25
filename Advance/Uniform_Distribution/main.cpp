#include "point.hpp"
#include "stack.hpp"
#include <iostream>

const int STACK_SIZE = 25;
const int MAX_SIZE = 5;

template <int max_size>
int contiguous_count(const int (&matrix)[max_size][max_size], const int &value, const int &size);

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N = 0;
        cin >> N;

        int matrix[MAX_SIZE][MAX_SIZE] = {};

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int x, y;
                cin >> x >> y;
                matrix[x - 1][y - 1] = i + 1;
            }
        }

        bool flag = true;

        for (int i = 0; i < N; i++) {
            int count = contiguous_count<MAX_SIZE>(matrix, i, N);
            if (count < N) {
                flag = false;
                break;
            }
        }

        cout << "Case #" << t + 1 << endl;
        (flag) ? cout << "good" << endl : cout << "wrong" << endl;
    }

    return 0;
}

template <int max_size>
int contiguous_count(const int (&matrix)[max_size][max_size], const int &value, const int &size) {
    bool checked[max_size][max_size] = {};
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == value) {
                Stack<Point, STACK_SIZE> s;
                s.push(Point(i, j));
                checked[i][j] = true;
                count++;
                while (!s.empty()) {
                    Point p = s.pop(); // previous
                    for (int d = 0; d < 4; d++) {
                        Point n(p.i + dx[d], p.j + dy[d]); // next
                        if (n.valid(size) && matrix[n.i][n.j] == value && !checked[n.i][n.j]) {
                            s.push(n);
                            checked[n.i][n.j] = 1;
                            count++;
                        }
                    }
                }
                return count;
            }
        }
    }
    return count;
}
