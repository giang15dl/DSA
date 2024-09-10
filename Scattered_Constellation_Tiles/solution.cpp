#include <unordered_map>
constexpr auto MAXN = 1000;
constexpr auto SIZE = 5;

using namespace std;
class Solution {
private:
    int N;
    int (*map)[MAXN];

    int used[MAXN][MAXN] = {};

    struct Tile {
        int ci = MAXN;
        int cj = MAXN;
        int count = 0;
    } tiles[(MAXN * MAXN) / SIZE * SIZE];

    int tileCount = 0;

    unordered_map<int, int> hashID;

    bool checkStar(int i, int j) {
        if (i < 0 || N <= i + 4 || j < 0 || N <= j + 4)
            return false;

        int count = 0;

        for (int r = 0; r < SIZE; r++)
            for (int c = 0; c < SIZE; c++)
                if (map[i + r][j + c] == 1)
                    count++;

        if (count != 7)
            return false;

        return true;
    }

    int getID(int data[SIZE][SIZE]) {
        int num[4] = {};

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                num[0] = num[0] * 2 + data[i][j];
                num[1] = num[1] * 2 + data[j][4 - i];
                num[2] = num[2] * 2 + data[4 - i][4 - j];
                num[3] = num[3] * 2 + data[4 - j][i];
            }
        }

        auto it = hashID.find(num[0]); 
        if (it != hashID.end())
            return it->second;

        int id = tileCount++;

        for (int i = 0; i < 4; i++)
            hashID[num[i]] = id;

        return id;
    }

    void calcTile(int i, int j) {
        int si = -1;
        int sj = -1;

        for (int k = -4; k <= 0; k++) {
            if (checkStar(i, j + k)) {
                si = i;
                sj = j + k;
                break;
            }
        }

        if (si == -1)
            return;

        int data[SIZE][SIZE] = {};

        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                data[i][j] = map[si + i][sj + j];

        int id = getID(data);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                used[si + i][sj + j] = id;
            }
        }

        int ci = si + 2;
        int cj = sj + 2;

        tiles[id].count++;
        if (ci < tiles[id].ci || (ci == tiles[id].ci && cj < tiles[id].cj)) {
            tiles[id].ci = ci;
            tiles[id].cj = cj;
        }
    }

public:
    Solution() {}
    Solution(int N, int mPlane[MAXN][MAXN]) : N(N), map(mPlane) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                used[i][j] = -1;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && used[i][j] == -1) {
                    calcTile(i, j);
                }
            }
        }
    }

    int getCount(int mPiece[SIZE][SIZE]) {
        int num = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                num = num * 2 + mPiece[i][j];
            }
        }

        auto it = hashID.find(num);
        if (it == hashID.end())
            return 0;

        int id = it->second;

        return tiles[id].count;
    }

    int getPosition(int mRow, int mCol) {
        int id = used[mRow][mCol];
        return tiles[id].ci * 10000 + tiles[id].cj;
    }
} *solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mPlane[MAXN][MAXN]) { if (solution) delete solution; solution = new Solution(N, mPlane); }
int getCount(int mPiece[SIZE][SIZE]) { return solution->getCount(mPiece); }
int getPosition(int mRow, int mCol) { return solution->getPosition(mRow, mCol); }