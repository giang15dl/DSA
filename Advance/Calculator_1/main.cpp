#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int TEST_CASES = 10;
const int MAX_LENGTH = 200;
const int MAX_OPERAND = 100;

struct operands {
    int value[MAX_OPERAND];
    int count;
};

int calculate(char str[], int length);

operands get_operands(char str[], int length);

int main() {
    //FILE *stream;
    //freopen_s(&stream, "cal1_test_input.txt", "r", stdin);

    for (int tc = 0; tc < TEST_CASES; tc++) {
        int length = 0;
        char str[MAX_LENGTH] = {};
        cin >> length;

        for (int i = 0; i < length; i++) {
            cin >> str[i];
        }
        int ans = calculate(str, length);

        cout << "#" << tc + 1 << " " << ans << endl;
    }

    return 0;
}

operands get_operands(char str[], int length) {
    operands o;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != '+') {
            o.value[count] = (int) (str[i]) - 48;
            count++;
        }
    }
    o.count = count;

    return o;
}

int calculate(char str[], int length) {
    int result = 0;
    operands o = get_operands(str, length);

    for (int i = 0; i < o.count; i++) {
        result += o.value[i];
    }
    return result;
}