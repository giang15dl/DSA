#include <iostream>
using namespace std;

const int MAX_N = 30; // Should be 30

int find_max(int (&)[MAX_N], int, int);

int main() {
    freopen("input1.txt", "r", stdin);
    int TEST_CASE;
    cin >> TEST_CASE;
    for (int index = 0; index < TEST_CASE; index++) {
        int known_days = 0;
        cin >> known_days;

        int stock_price[MAX_N];
        for (int i = 0; i < known_days; i++)
            cin >> stock_price[i];

        int money = 0, stock = 0;
        for (int date = 0; date < known_days; date++) {
            int highest_stock_day = find_max(stock_price, date, known_days);
            while (date < highest_stock_day) {
                money -= stock_price[date];
                stock++;
                date++;
            }
            money += stock * stock_price[date];
            stock = 0;
        }

        cout << "#" << index + 1 << " " << money << endl;
    }

    return 0;
}

int find_max(int (&arr)[MAX_N], int start, int end) {
    int max = 0, max_index = 0;
    for (int i = start; i < end; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}
