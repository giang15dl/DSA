#include <iostream>

using namespace std;

#define TEST_CASE	10
#define LENGTH		100

int main() {
    //ios::sync_with_stdio(false);
    //freopen("cal2_test_input.txt", "r", stdin);
    for (int case_index = 0; case_index < TEST_CASE; case_index++) {
        int length = 0, ans = 0;
        cin >> length;

        char string[200];

        cin >> string;

        bool flag = 0;
        int product = 1;
        for (int i = 0; i < length; i++) {
            if (string[i] == '*') {
                flag = 1;
                continue;
            }

            if (string[i] == '+') {
                flag = 0;
                continue;
            }

            if (flag == 0 && string[i + 1] != '*') {
                ans += (string[i] - '0');
                continue;
            }

            if (flag == 0 && string[i + 1] == '*') {
                product *= (string[i] - '0');
                continue;
            }
            if (flag == 1 && string[i + 1] == '*') {
                product *= (string[i] - '0');
                continue;
            }
            if (flag == 1 && string[i + 1] != '*') {
                product *= (string[i] - '0');
                ans += product;
                product = 1;
            }

        }


        cout << "#" << case_index + 1 << " " << ans << endl;
    }

    return 0;
}