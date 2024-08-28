#define MAX_N 1000
#define MAX_M 20

struct Result {
    int y, x;
};

class Solution {
private:
    int N, M;
    int (*map)[MAXN];

public:
    Solution() {}
    Solution(int N, int M, int Map[MAXN][MAXN]) : N(N), M(M), map(Map) {

    }

    Result findConstellation(int stars[MAX_M][MAX_M]) {
        Result res;

        res.y = res.x = 0;
        return res;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int Map[MAXN][MAXN]) {
    solution = Solution(N, M, Map);
}

Result findConstellation(int stars[MAX_M][MAX_M]) {
    return solution.findConstellation(stars);
}