#include <cstdio>
#include <iostream>

using namespace std;

#define INPUT_FROM_FILE 1

#define DEFAULT_TEST_CASE 10

const int SIZE = 100;

int Black_Pink_View(int houses[SIZE][SIZE]);
int dy[] = {-2, -1, +1, +2, +0, +0, +0, +0};
int dx[] = {+0, +0, +0, +0, -2, -1, +1, +2};

int main() {
#if INPUT_FROM_FILE
    FILE *input;
    errno_t error = freopen_s(&input, "BpV_input.txt", "r", stdin);
    if (error)
        exit(EXIT_FAILURE);
#endif // INPUT_FROM_FILE

    int TEST_CASE = DEFAULT_TEST_CASE;
    cin >> TEST_CASE;
    for (int case_index = 0; case_index < TEST_CASE; case_index++) {
        int test_case;
        cin >> test_case;

        int houses[SIZE][SIZE] = {};

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cin >> houses[row][col];
            }
        }

        int black_pink_view = Black_Pink_View(houses);

        cout << "#" << case_index + 1 << " " << black_pink_view << endl;
    }

#if INPUT_FROM_FILE
    fclose(input);
#endif // INPUT_FROM_FILE

    return 0;
}

int Black_Pink_View(int houses[SIZE][SIZE]) {
    int total = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            bool skip = false;
            int center = houses[row][col];
            int surrounds[8] = {};
            for (int i = 0; i < 8; i++) {
                int y = row + dx[i];
                int x = col + dy[i];
                if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                    surrounds[i] = houses[y][x];
                    if (surrounds[i] >= center) {
                        skip = true;
                        break;
                    }
                }
            }

            if (skip)
                continue;

            int max = 0;
            for (int i = 0; i < 8; i++) {
                if (surrounds[i] > max)
                    max = surrounds[i];
            }
            total += (center - max);
        }
    }
    return total;
}