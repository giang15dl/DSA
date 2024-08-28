#include <queue>
using namespace std;

#define MAX_N 350
#define MAX_GATE 201

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

struct Point {
    int i, j;
    Point () : i(0), j(0) {}
    Point (int i, int j) : i(i), j(j) {}
};

int (*map)[MAX_N];

struct Gate {
    Gate* adj[MAX_GATE];
    int dist[MAX_GATE];
    int adjCnt;
    bool isDel;
    //For dijsktra
    int heapIdx;
    int visited;
    int D; //current length of the path from start to this gate

    void init() {
        adjCnt = heapIdx = 0;
        isDel = false;
    }

    void addNeighbor(Gate* neighbor, int mDist) {
        adj[adjCnt] = neighbor;
        dist[adjCnt++] = mDist;
    }
} gates[MAX_GATE];

int maxStamina, gateNum;

int mTime = 0;

void BFS(Gate* gate, int r, int c) {
    int visited[MAX_N][MAX_N] = {};
    int steps[MAX_N][MAX_N] = {};
    register Gate* neighbor;

    queue<Point> q;
    q.push(Point(r,c));
    steps[r][c] = 0;
    visited[r][c] = ++mTime;

    while (!q.empty()) {
        Point t = q.front();
        q.pop();
        for (register int d = 0; d < 4; ++d) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (visited[n.i][n.j] == mTime || map[n.i][n.j] == 1)
                continue;

            visited[n.i][n.j] = mTime;
            steps[n.i][n.j] = steps[t.i][t.j] + 1;

            if (map[n.i][n.j] > 1 && !gates[map[n.i][n.j] - 1].isDel) {
                neighbor = &gates[map[n.i][n.j] - 1];
                gate->addNeighbor(neighbor, steps[n.i][n.j]);
                neighbor->addNeighbor(gate, steps[n.i][n.j]);
            }
            if (steps[n.i][n.j] != maxStamina) {
                q.push(n);
            }
        }
    }
}


Gate* heap[MAX_GATE]; //priority-queue for Dijsktra
int hSize = 0;

void hSwap(int i, int j) {
    register Gate* tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
    heap[i]->heapIdx = i;
    heap[j]->heapIdx = j;
}

void upHeapify(int curr) {
    for ( ; curr > 1 && heap[curr]->D < heap[curr >> 1]->D; curr >>= 1) 
        hSwap(curr, curr >> 1);
}

void hPush(Gate* gate) {
    gate->heapIdx = ++hSize;
    heap[hSize] = gate;
    upHeapify(hSize);
}

Gate* hPop() {
    Gate* ret = heap[1];
    heap[1] = heap[hSize--];
    heap[1]->heapIdx = 1;

    register int curr = 1, child;
    while ((child = curr << 1) <= hSize) {
        if (child < hSize && heap[child + 1]->D < heap[child]->D)
            ++child;
        if (heap[child]->D < heap[curr]->D) {
            hSwap(curr, child);
            curr = child;
        } else
            break;
    }
    return ret;
}


void init(int N, int mMaxStamina, int mMap[MAX_N][MAX_N]) {
    maxStamina = mMaxStamina;
    map = mMap;
}

void addGate(int mGateID, int mRow, int mCol) {
    gateNum = mGateID;
    map[mRow][mCol] = mGateID + 1;
    gates[mGateID].init();
    BFS(&gates[mGateID], mRow, mCol);
}

void removeGate(int mGateID) {
    gates[mGateID].isDel = true;
}

int getMinTime(int mStartGateID, int mEndGateID) {
    register Gate *end = &gates[mEndGateID];
    register Gate *curr, *next;
    register int nextDist;
    ++mTime;

    heap[1] = &gates[mStartGateID];
    gates[mStartGateID].heapIdx = 1;
    gates[mStartGateID].D = 0;
    hSize = 1;

    //Dijkstra
    while (hSize) {
        curr = hPop();
        if (curr == end)
            return curr->D;

        for (register int i = 0; i < curr->adjCnt; ++i) {
            next = curr->adj[i];
            if (next->isDel)
                continue;
            nextDist = curr->dist[i];
            if (next->visited != mTime) {
                next->visited = mTime;
                next->D = curr->D + nextDist;
                hPush(next);
            } else if (next->D > curr->D + nextDist) {
                next->D = curr->D + nextDist;
                upHeapify(next->heapIdx);
            }
        }
    }
    return -1;
}
