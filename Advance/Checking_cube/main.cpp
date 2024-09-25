#include "utils.hpp"
#include <iostream>

int solve(int N);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Totol number of Test cases
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        cout << "#" << t + 1 << " " << solve(N) << endl;
    }

    return 0;
}

int solve(int N) {
    using utils::cbrt;
    int count = 0;
    int limit = static_cast<int>(cbrt(N)); // upper bound for cube root

    for (int a = 0; a <= limit; a++)
        for (int b = a; b <= limit; b++)
            for (int c = b; c <= limit; c++)
                for (int d = c; d <= limit; d++)
                    for (int e = d; e <= limit; e++)
                        if (a * a * a + b * b * b + c * c * c + d * d * d + e * e * e == N)
                            count++;

    return count;
}
