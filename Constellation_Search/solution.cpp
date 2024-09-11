#define MAX_N 1000
#define MAX_M 20

struct Result {
    int y, x;
};

class Solution {
private:
    int N, M;
    int (*map)[MAX_N] = {};

public:
    Solution() {}
    Solution(int N, int M, int Map[MAX_N][MAX_N]) : N(N), M(M), map(Map) {}

    Result findConstellation(int stars[MAX_M][MAX_M]) {
        Result res;

        res.y = res.x = 0;
        return res;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int Map[MAX_N][MAX_N]) {
    solution = Solution(N, M, Map);
}

Result findConstellation(int stars[MAX_M][MAX_M]) {
    return solution.findConstellation(stars);
}