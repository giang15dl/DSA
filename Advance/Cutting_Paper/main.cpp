#include "point.hpp"
#include <iostream>

const int MAX_N = 128; // $N = 2^K; 1 \leq K \leq 7$; K is natural number. $N \leq 128$
const int WHITE = 0;
const int BLUE = 0;

template <const int MAX>
void Cut(const int (&mat)[MAX][MAX], const int N, const Point tl, const Point br);

template <const int MAX>
bool Check(const int (&mat)[MAX][MAX], const int N, const Point tl, const Point br);

int count_w, count_b;

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    // const char *output = "output.txt";
    // freopen(output, "w", stdout);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N;
        cin >> N;
        int mat[MAX_N][MAX_N] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];

        count_w = 0;
        count_b = 0;

        Cut<MAX_N>(mat, N, Point(0, 0), Point(N - 1, N - 1));

        cout << "Case #" << tc + 1 << endl;
        cout << count_w << " " << count_b << endl;
    }
    return 0;
}

template <const int MAX>
void Cut(const int (&mat)[MAX][MAX], const int N, const Point tl, const Point br) {
    int size = br.i - tl.i + 1;
    const Point d[4] = {Point(0, 0), Point(0, size / 2), Point(size / 2, 0), Point(size / 2, size / 2)};
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        Point tln = tl + d[i];
        Point brn = tln + Point(size / 2 - 1, size / 2 - 1);
        if (!Check(mat, N, tln, brn) || size == 1)
            Cut(mat, N, tln, brn);
    }
}

template <const int MAX>
bool Check(const int (&mat)[MAX][MAX], const int N, const Point tl, const Point br) {
    int size = (br.i - tl.i + 1) * (br.j - tl.j + 1);
    int count = 0;
    for (int i = tl.i; i <= br.i; i++)
        for (int j = tl.j; j <= br.j; j++)
            count += mat[i][j];

    if (count == 0)
        count_w++;
    if (count == size)
        count_b++;

    return (count == 0 || count == size);
}