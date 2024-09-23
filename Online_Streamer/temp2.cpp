#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;
class Solution {
    static const int MAX_N = 200000;

private:
    int N;            // Number of streamers
    int *subscribers; // Number of subscribers of each streamers
    int TreeSum[MAX_N * 4], TreeMax[MAX_N * 4], TreeMin[MAX_N * 4];

    void build(int node, int left, int right) {
        if (left == right)
            TreeSum[node] = TreeMax[node] = TreeMin[node] = subscribers[left];
        else {
            int mid = (left + right) / 2;
            build(2 * node + 1, left, mid);
            build(2 * node + 2, mid + 1, right);
            TreeSum[node] = TreeSum[2 * node + 1] + TreeSum[2 * node + 2];
            TreeMax[node] = max(TreeMax[2 * node + 1], TreeMax[2 * node + 2]);
            TreeMin[node] = min(TreeMin[2 * node + 1], TreeMin[2 * node + 2]);
        }
    }

    void update(int node, int left, int right, int idx) {
        if (left == right) {
            TreeSum[node] = TreeMax[node] = TreeMin[node] = subscribers[idx];
        } else {
            int mid = (left + right) / 2;
            if (idx <= mid) {
                update(2 * node + 1, left, mid, idx);
            } else {
                update(2 * node + 2, mid + 1, right, idx);
            }
            TreeSum[node] = TreeSum[2 * node + 1] + TreeSum[2 * node + 2];
            TreeMax[node] = max(TreeMax[2 * node + 1], TreeMax[2 * node + 2]);
            TreeMin[node] = min(TreeMin[2 * node + 1], TreeMin[2 * node + 2]);
        }
    }

    int count(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return 0;
        if (i <= left && right <= j)
            return TreeSum[node];

        int mid = (left + right) / 2;
        return count(2 * node + 1, left, mid, i, j) + count(2 * node + 2, mid + 1, right, i, j);
    }

    int getMax(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return 0;
        if (i <= left && right <= j)
            return TreeMax[node];

        int mid = (left + right) / 2;
        return max(getMax(2 * node + 1, left, mid, i, j), getMax(2 * node + 2, mid + 1, right, i, j));
    }

    int getMin(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return INT_MAX;
        if (i <= left && right <= j)
            return TreeMin[node];

        int mid = (left + right) / 2;
        return min(getMin(2 * node + 1, left, mid, i, j), getMin(2 * node + 2, mid + 1, right, i, j));
    }

public:
    Solution() : N(0), subscribers(NULL) {}

    Solution(int N, int mSubscriber[]) : N(N), subscribers(mSubscriber) {
        build(0, 0, N - 1);
    }

    int subscribe(int mId, int mNum) {
        subscribers[mId] += mNum;
        update(0, 0, N - 1, mId);
        return subscribers[mId];
    }

    int unsubscribe(int mId, int mNum) {
        subscribers[mId] -= mNum;
        update(0, 0, N - 1, mId);
        return subscribers[mId];
    }

    int count(int sId, int eId) {
        return count(0, 0, N - 1, sId, eId);
    }

    int calculate(int sId, int eId) {
        int max = getMax(0, 0, N - 1, sId, eId);
        int min = getMin(0, 0, N - 1, sId, eId);
        return max - min;
    }

} * solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mSubscriber[]) {
    if (solution)
        delete solution;
    solution = new Solution(N, mSubscriber);
}

int subscribe(int mId, int mNum) {
    mId--;
    return solution->subscribe(mId, mNum);
}

int unsubscribe(int mId, int mNum) {
    mId--;
    return solution->unsubscribe(mId, mNum);
}

int count(int sId, int eId) {
    sId--, eId--;
    return solution->count(sId, eId);
}

int calculate(int sId, int eId) {
    sId--, eId--;
    return solution->calculate(sId, eId);
}
