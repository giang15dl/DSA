#include <cstdlib>
#include <climits>
#include <algorithm>

class Solution {
    static const int MAX_N = 200000; // Maximum number of streamers
private:
    int N; // Number of streamers
    int *subscribers; // Number of subscribers of each streamers
    static int treeSum[MAX_N * 4], treeMax[MAX_N * 4], treeMin[MAX_N * 4];

    void build(int node, int left, int right) {
        if (left == right)
            treeSum[node] = treeMax[node] = treeMin[node] = subscribers[left];
        else {
            int mid = (left + right) / 2;
            build(2*node + 1, left, mid);
            build(2*node + 2, mid + 1, right);
            treeSum[node] = treeSum[2 * node + 1] + treeSum[2 * node + 2];
            treeMax[node] = std::max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
            treeMin[node] = std::min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
        }
    }

    void update(int node, int left, int right, int idx) {
        if (left == right)
            treeSum[node] = treeMax[node] = treeMin[node] = subscribers[idx];
        else {
            int mid = (left + right) / 2;
            if (idx <= mid)
                update(2 * node + 1, left, mid, idx);
            else
                update(2 * node + 2, mid + 1, right, idx);
            treeSum[node] = treeSum[2 * node + 1] + treeSum[2 * node + 2];
            treeMax[node] = std::max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
            treeMin[node] = std::min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
        }
    }

    int count(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return 0;
        if (i <= left && right <= j)
            return treeSum[node];

        int mid = (left + right) / 2;
        return count(2 * node + 1, left, mid, i, j) + count(2 * node + 2, mid + 1, right, i, j);
    }

    int max(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return 0;
        if (i <= left && right <= j)
            return treeMax[node];

        int mid = (left + right) / 2;
        return std::max(this->max(2 * node + 1, left, mid, i, j), this->max(2 * node + 2, mid + 1, right, i, j));
    }

    int min(int node, int left, int right, int i, int j) {
        if (i > right || j < left)
            return INT_MAX;
        if (i <= left && right <= j)
            return treeMin[node];

        int mid = (left + right) / 2;
        return std::min(this->min(2 * node + 1, left, mid, i, j), this->min(2 * node + 2, mid + 1, right, i, j));
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
        return max(0, 0, N - 1, sId, eId) - min(0, 0, N - 1, sId, eId);
    }

}solution;

int Solution::treeSum[MAX_N * 4];
int Solution::treeMax[MAX_N * 4];
int Solution::treeMin[MAX_N * 4];

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mSubscriber[]) {
    solution = Solution(N, mSubscriber);
}

int subscribe(int mId, int mNum) {
    mId--;
    return solution.subscribe(mId, mNum);
}

int unsubscribe(int mId, int mNum) {
    mId--;
    return solution.unsubscribe(mId, mNum);
}

int count(int sId, int eId) {
    sId--, eId--;
    return solution.count(sId, eId);
}

int calculate(int sId, int eId) {
    sId--, eId--;
    return solution.calculate(sId, eId);
}
