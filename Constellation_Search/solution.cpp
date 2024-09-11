#define MAX_N 1000
#define MAX_M 20
#define MAX_STARS 20000

struct Result {
    int y, x;
};

class Solution {

private:
    int N, M;
    int (*map)[MAX_N] = {};

    struct Star {
        int y, x;
        Star(int y = -1, int x = -1) : y(y), x(x) {}
        void operator-=(const Star &that) {
            y -= that.y;
            x -= that.x;
        }
    } stars[MAX_STARS];
    int starCount = 0;

    bool find(int constCount, Star constStars[MAX_M], Result &result) {
        bool found = 0;
        int i;
        for (i = 0; i < starCount; ++i) {
            found = 1;
            for (int j = 0; j < constCount; ++j) {
                int Y = constStars[j].y + stars[i].y;
                int X = constStars[j].x + stars[i].x;
                if (Y < 0 || Y >= N || X < 0 || X >= N || map[Y][X] != 1) {
                    found = 0;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found) {
            result.y = stars[i].y;
            result.x = stars[i].x;
        }
        return found;
    }

    void rotate(int constCount, Star constStars[MAX_M]) {
        for (int i = 0; i < constCount; ++i) {
            int ny = -constStars[i].x;
            int nx = constStars[i].y;
            constStars[i].y = ny;
            constStars[i].x = nx;
        }
    }

public:
    Solution() {}
    Solution(int N, int M, int Map[MAX_N][MAX_N]) : N(N), M(M), map(Map) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (map[i][j])
                    stars[starCount++] = Star(i, j);
    }

    Result findConstellation(int stars[MAX_M][MAX_M]) {
        Star reference;
        Star constStars[MAX_M];
        int constCount = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                if (stars[i][j] == 1)
                    constStars[constCount++] = Star(i, j);
                else if (stars[i][j] == 9)
                    reference = Star(i, j);
            }
        }

        for (int i = 0; i < constCount; ++i)
            constStars[i] -= reference;

        Result result;
        if (!find(constCount, constStars, result)) {
            rotate(constCount, constStars);
            if (!find(constCount, constStars, result)) {
                rotate(constCount, constStars);
                if (!find(constCount, constStars, result)) {
                    rotate(constCount, constStars);
                    find(constCount, constStars, result);
                }
            }
        }
        return result;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int Map[MAX_N][MAX_N]) { solution = Solution(N, M, Map); }
Result findConstellation(int stars[MAX_M][MAX_M]) { return solution.findConstellation(stars); }