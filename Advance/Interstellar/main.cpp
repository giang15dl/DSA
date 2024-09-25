#include <climits>
#include <iostream>

const int SIZE = 5;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}
};

struct WormHole {
    Point A, B;
    int time;

    WormHole() : A(), B(), time(0) {}
    WormHole(Point A, Point B, int time) : A(A), B(B), time(time) {}
};

class Solution {
public:
    Solution(Point S, Point D, WormHole (&W)[SIZE], int N) : S(S), D(D), W(W), N(N) {}

    int solve();

    Point S, D;
    WormHole (&W)[SIZE];
    int N;

private:
    int ans;
    int visited[SIZE];

    void BackTracking(Point X, int totalTime);

    int time(Point A, Point B) {
        return abs(A.x - B.x) + abs(A.y - B.y);
    }

    int abs(int x) {
        return (x < 0) ? -x : x;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        Point S, D;
        cin >> S.x >> S.y >> D.x >> D.y;
        WormHole W[SIZE];
        for (int i = 0; i < N; i++)
            cin >> W[i].A.x >> W[i].A.y >> W[i].B.x >> W[i].B.y >> W[i].time;

        Solution s(S, D, W, N);

        cout << "#" << t + 1 << " " << s.solve() << endl;
    }

    return 0;
}

int Solution::solve() {
    for (int i = 0; i < N; i++)
        visited[i] = 0;

    ans = INT_MAX;

    BackTracking(S, 0);

    return ans;
}

void Solution::BackTracking(Point X, int totalTime) {
    if (totalTime > ans)
        return;

    ans = min(ans, totalTime + time(X, D));

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            int timeToA = time(X, W[i].A);
            BackTracking(W[i].B, totalTime + timeToA + W[i].time);
            int timeToB = time(X, W[i].B);
            BackTracking(W[i].A, totalTime + timeToB + W[i].time);
            visited[i] = 0;
        }
    }
}