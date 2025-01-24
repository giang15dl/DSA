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

    bool find(int constellationCount, Star constellation[MAX_M], Result &result) {
        bool found = 0;
        int i;
        for (i = 0; i < starCount; ++i) {
            found = 1;
            for (int j = 0; j < constellationCount; ++j) {
                int Y = constellation[j].y + stars[i].y;
                int X = constellation[j].x + stars[i].x;
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

    void rotate(int constellationCount, Star constellation[MAX_M]) {
        for (int i = 0; i < constellationCount; ++i) {
            int ny = -constellation[i].x;
            int nx = constellation[i].y;
            constellation[i].y = ny;
            constellation[i].x = nx;
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
        Star constellation[MAX_M];
        int constellationCount = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                if (stars[i][j] == 1)
                    constellation[constellationCount++] = Star(i, j);
                else if (stars[i][j] == 9)
                    reference = Star(i, j);
            }
        }

        for (int i = 0; i < constellationCount; ++i)
            constellation[i] -= reference;

        Result result;
        if (!find(constellationCount, constellation, result)) {
            rotate(constellationCount, constellation);
            if (!find(constellationCount, constellation, result)) {
                rotate(constellationCount, constellation);
                if (!find(constellationCount, constellation, result)) {
                    rotate(constellationCount, constellation);
                    if (!find(constellationCount, constellation, result))
                        return Result();
                }
            }
        }
        return result;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int Map[MAX_N][MAX_N]) { solution = Solution(N, M, Map); }
Result findConstellation(int stars[MAX_M][MAX_M]) { return solution.findConstellation(stars); }