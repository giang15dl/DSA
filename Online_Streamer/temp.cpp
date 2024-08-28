#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 200000;

int Data[MAX_N], N;
int TreeSum[MAX_N * 4], TreeMax[MAX_N * 4], TreeMin[MAX_N * 4];

void build(int node, int left, int right) {
    if (left == right) {
        TreeSum[node] = TreeMax[node] = TreeMin[node] = Data[left];
    } else {
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
        TreeSum[node] = TreeMax[node] = TreeMin[node] = Data[idx];
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

int queryCnt(int node, int left, int right, int i, int j) {
    if (i > right || j < left) return 0;
    if (i <= left && right <= j) return TreeSum[node];

    int mid = (left + right) / 2;
    return queryCnt(2 * node + 1, left, mid, i, j) + queryCnt(2 * node + 2, mid + 1, right, i, j);
}

int queryMax(int node, int left, int right, int i, int j) {
    if (i > right || j < left) return 0;
    if (i <= left && right <= j) return TreeMax[node];

    int mid = (left + right) / 2;
    return max(queryMax(2 * node + 1, left, mid, i, j), queryMax(2 * node + 2, mid + 1, right, i, j));
}

int queryMin(int node, int left, int right, int i, int j) {
    if (i > right || j < left) return INT_MAX;
    if (i <= left && right <= j) return TreeMin[node];

    int mid = (left + right) / 2;
    return min(queryMin(2 * node + 1, left, mid, i, j), queryMin(2 * node + 2, mid + 1, right, i, j));
}

void init(int N, int mSubscriber[]) {
    ::N = N;
    memcpy(Data, mSubscriber, sizeof(int) * N);
    build(0, 0, N - 1);
}

int subscribe(int mId, int mNum) {
    --mId;
    Data[mId] += mNum;
    update(0, 0, N - 1, mId);
    return Data[mId];
}

int unsubscribe(int mId, int mNum) {
    --mId;
    Data[mId] -= mNum;
    update(0, 0, N - 1, mId);
    return Data[mId];
}

int count(int sId, int eId) {
    --sId, --eId;
    int ret = queryCnt(0, 0, N - 1, sId, eId);
    return ret;
}

int calculate(int sId, int eId) {
    --sId, --eId;
    int maxV = queryMax(0, 0, N - 1, sId, eId);
    int minV = queryMin(0, 0, N - 1, sId, eId);
    return maxV - minV;
}
