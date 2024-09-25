#include "utils.hpp"
#include <iostream>

const int MAX_DIGITS = 11;
const int MAX = 100000;

int FindBiggesstPrize(char num[], int swaps);
void FindBiggesstPrize(int (&num_arr)[MAX_DIGITS], int digits, int swaps, int &max);
int Num2Arr(int num, int (&num_arr)[MAX_DIGITS]);
int Arr2Num(int (&num_arr)[MAX_DIGITS], int length);
void Reverse(int (&arr)[MAX_DIGITS], int length);
bool CheckInsert(int num, int swaps);

int checked[MAX_DIGITS][MAX] = {};

using namespace std;
using utils::pow;
using utils::swap;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    // const char *output = "output.txt";
    freopen(input, "r", stdin);
    // freopen(output, "w", stdout);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        char num_arr[MAX_DIGITS] = {};
        cin >> num_arr;
        int swaps;
        cin >> swaps;

        for (int i = 0; i < MAX_DIGITS; i++)
            for (int j = 0; j < MAX_DIGITS; j++)
                checked[i][j] = 0;

        int max = FindBiggesstPrize(num_arr, swaps);

        cout << "Case #" << tc + 1 << endl;
        cout << max << endl;
    }
    return 0;
}

bool CheckInsert(int num, int swaps) {
    for (int i = 0; i < MAX; i++) {
        if (checked[swaps][i] == num)
            return true;

        else if (checked[swaps][i] == 0) {
            checked[swaps][i] = num;
            break;
        }
    }
    return false;
}

void FindBiggesstPrize(int (&num_arr)[MAX_DIGITS], int digits, int swaps, int &max) {
    if (swaps == 0) {
        if (Arr2Num(num_arr, digits) > max)
            max = Arr2Num(num_arr, digits);
        return;
    }

    for (int i = 0; i < digits - 1; i++) {
        for (int j = i + 1; j < digits; j++) {
            if (num_arr[i] != num_arr[j]) {
                swap(num_arr[i], num_arr[j]);
                int num = Arr2Num(num_arr, digits);
                if (!CheckInsert(num, swaps))
                    FindBiggesstPrize(num_arr, digits, swaps - 1, max);
                swap(num_arr[i], num_arr[j]);
            }
        }
    }
}

int FindBiggesstPrize(char num[], int swaps) {
    int num_arr[MAX_DIGITS] = {};
    int length = 0;

    for (int i = 0; num[i] != 0; i++) {
        length++;
        num_arr[i] = num[i] - '0';
    }

    int max = 0;

    FindBiggesstPrize(num_arr, length, swaps, max);

    return max;
}

int Arr2Num(int (&num_arr)[MAX_DIGITS], int length) {
    int num = 0;
    for (int i = 0; i < length; i++)
        num += num_arr[i] * pow(10, length - 1 - i);
    return num;
}

int Num2Arr(int num, int (&num_arr)[MAX_DIGITS]) {
    int digits = 0;
    while (num) {
        num_arr[digits] = num % 10;
        num /= 10;
        digits++;
    }
    Reverse(num_arr, digits);
    return digits;
}

void Reverse(int (&arr)[MAX_DIGITS], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
