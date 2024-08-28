/* @C09 */
#include <unordered_map>

using namespace std;
#define MAX_SIZE 1000

unordered_map<int, int> table;
int types;
int counter[1000 * 1000 / (5 * 5)];
int upper[1000 * 1000 / (5 * 5)];
int tile_data[5][5];
int (*upper_map)[1000];
/*---------------------------------------------------------------------------*/
int add_tile(int data[5][5], int row, int col) {
    int hash_code = 0;
    // 0 degree
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            hash_code = hash_code * 2 + data[i][j];
        }
    // exist
    if (table.find(hash_code) != table.end()) {
        int type = table[hash_code];
        ++counter[type];
        return type;
    }
    // add new
    table[hash_code] = types;
    // 90 degree
    hash_code = 0;
    for (int j = 4; j >= 0; --j)
        for (int i = 0; i < 5; ++i) {
            hash_code = hash_code * 2 + data[i][j];
        }
    table[hash_code] = types;
    // 180 degree
    hash_code = 0;
    for (int i = 4; i >= 0; --i)
        for (int j = 4; j >= 0; --j) {
            hash_code = hash_code * 2 + data[i][j];
        }
    table[hash_code] = types;
    // 270 degree
    hash_code = 0;
    for (int j = 0; j < 5; ++j)
        for (int i = 4; i >= 0; --i) {
            hash_code = hash_code * 2 + data[i][j];
        }
    table[hash_code] = types;
    upper[types] = (row + 2) * 10000 + (col + 2);
    counter[types] = 1;
    return types++;
}
/*---------------------------------------------------------------------------*/
void init(int N, int mPlane[MAX_SIZE][MAX_SIZE]) {
    table = unordered_map<int, int>();
    types = 0;
    upper_map = mPlane;
    for (int y = 0; y < N - 4; ++y) {
        for (int x = 0; x < N - 4; ++x) {
            int star = 0;
            for (int i = y; i < y + 5; ++i)
                star += mPlane[i][x] + mPlane[i][x + 4];
            for (int i = x + 1; i < x + 4; ++i)
                star += mPlane[y][i] + mPlane[y + 4][i];
            if (star == 0 || star > 7)
                continue; // edge check

            for (int i = y + 1; i < y + 4; ++i)
                for (int j = x + 1; j < x + 4; ++j)
                    star += mPlane[i][j];
            if (star == 7) {
                for (int i = y; i < y + 5; ++i)
                    for (int j = x; j < x + 5; ++j) {
                        tile_data[i - y][j - x] = mPlane[i][j];
                        mPlane[i][j] = 0; // remove stars
                    }
                int type = add_tile(tile_data, y, x);
                for (int i = y; i < y + 5; ++i)
                    for (int j = x; j < x + 5; ++j)
                        upper_map[i][j] = upper[type];
                x += 4;
            }
        }
    }
}
/*---------------------------------------------------------------------------*/
int getCount(int mPiece[5][5]) {
    int hash_code = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            hash_code = hash_code * 2 + mPiece[i][j];
        }
    if (table.find(hash_code) == table.end())
        return 0;
    int type = table[hash_code];
    return counter[type];
}
/*---------------------------------------------------------------------------*/
int getPosition(int mRow, int mCol) {
    return upper_map[mRow][mCol];
}