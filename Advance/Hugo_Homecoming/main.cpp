#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define INT_MAX 2147483647

const int SIZE = 20;

struct Soldier {
    int soldier;
    int fought;

    Soldier() : soldier(0), fought(0){};
};

struct Gate {
    int price, soldier;

    Gate() : price(0), soldier(0) {}
    Gate(int p, int s) : price(p), soldier(s) {}
};

class Solution {
public:
    Solution(Gate (&G)[SIZE], int N);

    int solve();

private:
    int ans;
    int N;
    Soldier S[SIZE];
    Gate (&G)[SIZE];
    void BackTracking(int gate = 0, int price = 0, int soldier = 0);
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

        Gate gates[SIZE];

        for (int i = 0; i < N; i++)
            cin >> gates[i].soldier >> gates[i].price;

        Solution s(gates, N);

        cout << "#" << t + 1 << " " << s.solve() << endl;
    }

    return 0;
}

Solution::Solution(Gate (&G)[SIZE], int N) : G(G), N(N), ans(0){};

int Solution::solve() {
    ans = INT_MAX;

    BackTracking();

    return ans;
}

void Solution::BackTracking(int i, int price, int soldier) {
    if (i == N) {
        if (price < ans)
            ans = price;
        return;
    }

    if (price > ans)
        return;

    for (int x = 0; x < 3; x++) {
        switch (x) {
        case 0:
            BackTracking(i + 1, price + G[i].price, soldier);
            break;
        case 1:
            S[i].soldier = G[i].soldier;
            S[i].fought = 3;
            BackTracking(i + 1, price + 2 * G[i].price, soldier + G[i].soldier);
            S[i].soldier = 0;
            S[i].fought = 0;
            break;
        case 2:
            if (soldier < G[i].soldier)
                break;
            int soldier_temp = G[i].soldier;
            int qq = 0;

            Soldier temp[SIZE] = {};

            for (int j = 0; j < i; j++) {
                temp[j].soldier = S[j].soldier;
                temp[j].fought = S[j].fought;
            }

            for (int j = 0; j < i; j++) {
                if (S[j].fought > 0 && S[j].soldier > 0) {
                    if (soldier_temp > S[j].soldier) {
                        soldier_temp -= S[j].soldier;
                        S[j].soldier = 0;
                    } else {
                        S[j].soldier -= soldier_temp;
                        soldier_temp = 0;
                    }
                    S[j].fought--;
                    if (S[j].fought <= 0)
                        S[j].soldier = 0;
                }
            }

            for (int j = 0; j < i; j++) {
                qq += S[j].soldier;
            }

            BackTracking(i + 1, price, qq);

            for (int j = 0; j < i; j++) {
                S[j].soldier = temp[j].soldier;
                S[j].fought = temp[j].fought;
            }
            break;
        }
    }
}
