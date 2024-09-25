#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define DEBUG 1

using namespace std;

#define TEST_CASE	2
#define ROW			10
#define COL			10

struct Object {
    int x1, x2, y1, y2;
    bool vertical;
    void falldown(int table[ROW][COL]);
};

void print(int table[ROW][COL]);

int main() {
#ifdef DEBUG
    freopen("test_input.txt", "r", stdin);
#endif // DEBUG

    for (int case_index = 0; case_index < TEST_CASE; case_index++) {

        int grid[ROW][COL];

        Object obj[20];

        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                cin >> grid[row][col];
            }
        }
        int i = 0;
        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                if (grid[row][col] == 1 && grid[row + 1][col] == 1 && (row + 1) < ROW) {
                    obj[i].x1 = col;
                    obj[i].y1 = row;
                    obj[i].x2 = col;
                    obj[i].y2 = row + 1;
                    obj[i].vertical = false;
                    i++;
                }
                if (grid[row][col] == 1 && grid[row][col + 1] == 1 && (col + 1) < COL) {
                    obj[i].x1 = col;
                    obj[i].y1 = row;
                    obj[i].x2 = col + 1;
                    obj[i].y2 = row;
                    obj[i].vertical = true;
                    i++;
                }
            }
        }
#ifdef DEBUG
        print(grid);
#endif // DEBUG

        cout << "#" << case_index + 1 << " " << endl;
    }

    return 0;
}

void print(int table[ROW][COL]) {
    system("cls");
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (table[row][col] == 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "|" << row << endl;
    }
    for (int i = 0; i < COL; i++)
        cout << "__";

    cout << endl;
    for (int i = 0; i < COL; i++)
        cout << i << " ";

    cout << endl;
}

void Object::falldown(int table[ROW][COL]) {
    if (vertical == true) {
        bool blank = true;
        for (int col = y2; col < COL; col++) {
            if (table[x1][col] != 0)
                blank = false;
        }
        if (blank) {

        }
    }
}