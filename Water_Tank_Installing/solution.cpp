#include <vector>

using namespace std;
class Solution {
    static const int MAX_N = 50000;
    static const int MAX_HASH = 10000;
    static const int MAX_TANK = 30;
public:
    Solution() {}

    Solution(int N, int height[]) : N(N), height(height) {
        for (int i = 1; i <= N - 2; i++) {
            int delta = height[i + 1] - height[i] + 5;
            if (delta < 1 || delta > 9)
                continue;

            int value = delta;
            for (int j = 2; j < 5; j++) {
                if (i + j == N - 1)
                    break;

                delta = height[i + j] - height[i] + 5;
                if (delta < 1 || delta > 9)
                    break;

                value = value * 10 + delta;
                hash[value].push_back(i);
            }
        }
    }

    int countPosition(int len, int tank[]) {
        const auto& indexes = getHash(len, tank);
        return indexes.size();
    }

    int buildAndPourOut(int len, int tank[], int water) {
        const auto& indexes = getHash(len, tank);
        int max = 0;
        for (const auto &index : indexes) {
            int tankHeight = height[index] + tank[0];

            int left = countFromIndex(index, water, tankHeight, -1);
            if (left > max)
                max = left;

            int right = countFromIndex(index + len - 1, water, tankHeight, 1);
            if (right > max)
                max = right;
        }
        return max;
    }

private:
    int N;
    int *height;
    vector<int> hash[MAX_HASH];

    vector<int>& getHash(int len, int tank[]) {
        int value = 0;
        for (int i = 1; i < len; i++) {
            int delta = tank[0] - tank[i] + 5;
            value = value * 10 + delta;
        }

        return hash[value];
    }

    int countFromIndex(int index, int water, int tankHeight, int dir) {
        if (height[index + dir] >= tankHeight)
            return 0;

        int oldHeight = height[index];
        height[index] = tankHeight;

        int puddle = index + dir;

        while (height[puddle] >= height[puddle + dir])
            puddle += dir;

        int ret = countFromPuddle(puddle, tankHeight, water);
        height[index] = oldHeight;
        return ret;
    }

    int countFromPuddle(int puddle, int maxHeight, int water) {
        int total = 0;
        int left = puddle, right = puddle;

        for (int i = height[puddle]; i < maxHeight; i++) {
            while (height[left] == i) {
                if (height[left - 1] < height[left])
                    return total;
                left--;
            }

            while (height[right] == i) {
                if (height[right + 1] < height[right])
                    return total;
                right++;
            }

            int current = right - left - 1;
            if (total + current > water)
                break;

            total += current;
        }

        return total;
    }
}*solution;

///////////////////////////////////////////////////////////////////////////////
void init(int N, int mHeight[]) {
    if (solution) delete solution;
    solution = new Solution(N, mHeight);
}

int countPosition(int mLen, int mTank[]) {
    return solution->countPosition(mLen, mTank);
}

int buildAndPourOut(int mLen, int mTank[], int mWater) {
    return solution->buildAndPourOut(mLen, mTank, mWater);
}