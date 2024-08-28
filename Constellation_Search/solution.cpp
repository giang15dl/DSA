#include <unordered_map>
#define MAXN 1000
#define SIZE 5

using namespace std;
class Solution {
private:
    int N;
    int (*map)[MAXN];

    unordered_map<int, int> hash;
    int types;
    int counter[(MAXN * MAXN) / (SIZE * SIZE)];
    int upper[(MAXN * MAXN) / (SIZE * SIZE)];
    int tile[SIZE][SIZE];

    int add_tile(int data[SIZE][SIZE], int row, int col) {
        int hash_code = 0;
        // 0 degree
        for (int k = 0; k < SIZE; ++k)
            for (int l = 0; l < SIZE; ++l)
                hash_code = hash_code * 2 + data[k][l];

        // exist
        if (hash.find(hash_code) != hash.end()) {
            int type = hash[hash_code];
            ++counter[type];
            return type;
        }
        // add new
        hash[hash_code] = types;
        // 90 degree
        hash_code = 0;
        for (int l = 4; l >= 0; --l)
            for (int k = 0; k < SIZE; ++k)
                hash_code = hash_code * 2 + data[k][l];

        hash[hash_code] = types;
        // 180 degree
        hash_code = 0;
        for (int k = 4; k >= 0; --k)
            for (int l = 4; l >= 0; --l)
                hash_code = hash_code * 2 + data[k][l];

        hash[hash_code] = types;
        // 270 degree
        hash_code = 0;
        for (int l = 0; l < SIZE; ++l)
            for (int k = 4; k >= 0; --k)
                hash_code = hash_code * 2 + data[k][l];

        hash[hash_code] = types;
        upper[types] = (row + 2) * 10000 + (col + 2);
        counter[types] = 1;
        return types++;
    }

public:
    Solution() {}
    Solution(int N, int mPlane[MAXN][MAXN]) : N(N), map(mPlane) {
        types = 0;
        for (int i = 0; i < N - 4; ++i) {
            for (int j = 0; j < N - 4; ++j) {
                int stars = 0;
                for (int k = i; k < i + SIZE; ++k)
                    stars += mPlane[k][j] + mPlane[k][j + 4];

                for (int k = j + 1; k < j + 4; ++k)
                    stars += mPlane[i][k] + mPlane[i + 4][k];

                if (stars == 0 || stars > 7)
                    continue; // edge check

                for (int k = i + 1; k < i + 4; ++k)
                    for (int l = j + 1; l < j + 4; ++l)
                        stars += mPlane[k][l];

                if (stars == 7) {
                    for (int k = i; k < i + SIZE; ++k)
                        for (int l = j; l < j + SIZE; ++l)
                            tile[k - i][l - j] = mPlane[k][l], mPlane[k][l] = 0; // remove stars

                    int type = add_tile(tile, i, j);
                    for (int k = i; k < i + SIZE; ++k)
                        for (int l = j; l < j + SIZE; ++l)
                            map[k][l] = upper[type];
                    j += 4;
                }
            }
        }
    }

    int getCount(int mPiece[SIZE][SIZE]) {
        int hash_code = 0;
        for (int k = 0; k < SIZE; ++k)
            for (int l = 0; l < SIZE; ++l)
                hash_code = hash_code * 2 + mPiece[k][l];

        if (hash.find(hash_code) == hash.end())
            return 0;

        int type = hash[hash_code];
        return counter[type];
    }

    int getPosition(int mRow, int mCol) {
        return map[mRow][mCol];
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mPlane[MAXN][MAXN]) { solution = Solution(N, mPlane); }
int getCount(int mPiece[SIZE][SIZE]) { return solution.getCount(mPiece); }
int getPosition(int mRow, int mCol) { return solution.getPosition(mRow, mCol); }