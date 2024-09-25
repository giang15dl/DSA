#include <iostream>
using namespace std;

#define MAX_N 30
#define USER 0
#define COM 1

int num[MAX_N];

struct score {
    int user;
    int com;
    score() {
        user = 0;
        com = 0;
    }
    void init() {
        user = 0;
        com = 0;
    }
    bool valid() {
        if (user == 0)
            return false;
        return true;
    }
};

score easy[MAX_N][MAX_N];
score hard[MAX_N][MAX_N];

score Max(score a, score b, int turn) {
    if (turn == USER)
        return a.user > b.user ? a : b;
    return a.com > b.com ? a : b;
}

score Min(score a, score b, int turn) {
    if (turn == USER)
        return a.user < b.user ? a : b;
    return a.com < b.com ? a : b;
}

score playHard(int i, int j, int turn) {
    if (i > j)
        return score();
    if (hard[i][j].valid())
        return hard[i][j];
    if (turn == USER) {
        score sumL = playHard(i + 1, j, COM);
        sumL.user += num[i];
        score sumR = playHard(i, j - 1, COM);
        sumR.user += num[j];
        return hard[i][j] = Max(sumL, sumR, USER);
    } else if (turn == COM) {
        score sumL = playHard(i + 1, j, USER);
        sumL.com += num[i];
        score sumR = playHard(i, j - 1, USER);
        sumR.com += num[j];
        return hard[i][j] = Max(sumL, sumR, COM);
    }
}

score playEasy(int i, int j, int turn) {
    if (i > j)
        return score();
    if (easy[i][j].valid())
        return easy[i][j];
    if (turn == USER) {
        score sumL = playEasy(i + 1, j, COM);
        sumL.user += num[i];
        score sumR = playEasy(i, j - 1, COM);
        sumR.user += num[j];
        return easy[i][j] = Max(sumL, sumR, USER);
    } else if (turn == COM) {
        score sumL = playEasy(i + 1, j, USER);
        sumL.com += num[i];
        score sumR = playEasy(i, j - 1, USER);
        sumR.com += num[j];
        return Min(sumL, sumR, COM);
    }
}

int main(void) {
    int test_case;
    int T, N;
    freopen("Text.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num[i];
            for (int j = 0; j < N; j++) {
                hard[i][j].init();
                easy[i][j].init();
            }
        }
        printf("Case #%d\n%d %d\n", test_case, playEasy(0, N - 1, 0).user, playHard(0, N - 1, 0).user);
    }
    return 0;
}
