#include <queue>
#include <vector>

const int MAX_N = 350;
const int MAX_G = 200 + 1;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

using namespace std;
class Solution {
private:
    int N; // Map Size
    int Stamina; // Max Stamina
    int (*map)[MAX_N];

private:
    int time;
    int heapSize;

    struct Point {
        int i, j;
        Point() : i(0), j(0) {}
        Point(int i, int j) : i(i), j(j) {}
    };

    struct Gate {
        vector<Gate*> neighbors;
        vector<int> distances;
        bool removed;
        int heapIndex;
        int visited;
        int D; // current length of the path from start to this gate
        Gate() : heapIndex(0), removed(false) {}
        void addNeighbor(Gate *neighbor, int distance) {
            neighbors.push_back(neighbor);
            distances.push_back(distance);
        }
    } gates[MAX_G], *heap[MAX_G];

    void BFS(Gate *gate, int i, int j) {
        int visited[MAX_N][MAX_N] = {};
        int steps[MAX_N][MAX_N] = {};
        Gate *neighbor;

        queue<Point> q;
        q.push(Point(i, j));
        steps[i][j] = 0;
        visited[i][j] = ++time;

        while (!q.empty()) {
            Point t = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                Point n(t.i + di[d], t.j + dj[d]);
                if (visited[n.i][n.j] == time || map[n.i][n.j] == 1)
                    continue;

                visited[n.i][n.j] = time;
                steps[n.i][n.j] = steps[t.i][t.j] + 1;

                if (map[n.i][n.j] > 1 && !gates[map[n.i][n.j] - 1].removed) {
                    neighbor = &gates[map[n.i][n.j] - 1];
                    gate->addNeighbor(neighbor, steps[n.i][n.j]);
                    neighbor->addNeighbor(gate, steps[n.i][n.j]);
                }
                if (steps[n.i][n.j] < Stamina) {
                    q.push(n);
                }
            }
        }
    }

    void heapSwap(int i, int j) {
        Gate *tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
        heap[i]->heapIndex = i;
        heap[j]->heapIndex = j;
    }

    void upHeapify(int curr) {
        while (curr > 1 && heap[curr]->D < heap[curr >> 1]->D) {
            heapSwap(curr, curr >> 1);
            curr >>= 1;
        }
    }

    void heapPush(Gate *gate) {
        gate->heapIndex = ++heapSize;
        heap[heapSize] = gate;
        upHeapify(heapSize);
    }

    Gate *heapPop() {
        Gate *ret = heap[1];
        heap[1] = heap[heapSize--];
        heap[1]->heapIndex = 1;

        int curr = 1, child;
        while ((child = curr << 1) <= heapSize) {
            if (child < heapSize && heap[child + 1]->D < heap[child]->D)
                ++child;
            if (heap[child]->D < heap[curr]->D) {
                heapSwap(curr, child);
                curr = child;
            } else
                break;
        }
        return ret;
    }

public:
    Solution() {}

    Solution(int N, int M, int mMap[MAX_N][MAX_N]) : N(N), Stamina(M), map(mMap) {
        time = 0;
        heapSize = 0;
    }

    void addGate(int mGateID, int mRow, int mCol) {
        map[mRow][mCol] = mGateID + 1;
        BFS(&gates[mGateID], mRow, mCol);
    }

    void removeGate(int mGateID) {
        gates[mGateID].removed = true;
    }

    int getMinTime(int mStartGateID, int mEndGateID) {
        Gate *end = &gates[mEndGateID];
        Gate *curr, *next;
        int nextDist;
        ++time;

        heap[1] = &gates[mStartGateID];
        gates[mStartGateID].heapIndex = 1;
        gates[mStartGateID].D = 0;
        heapSize = 1;

        // Dijkstra
        while (heapSize) {
            curr = heapPop();
            if (curr == end)
                return curr->D;

            for (int i = 0; i < curr->neighbors.size(); ++i) {
                next = curr->neighbors[i];
                if (next->removed)
                    continue;
                nextDist = curr->distances[i];
                if (next->visited != time) {
                    next->visited = time;
                    next->D = curr->D + nextDist;
                    heapPush(next);
                } else if (next->D > curr->D + nextDist) {
                    next->D = curr->D + nextDist;
                    upHeapify(next->heapIndex);
                }
            }
        }
        return -1;
    }
} *solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mMaxStamina, int mMap[MAX_N][MAX_N]) {
    if (solution)
        delete solution;
    solution = new Solution(N, mMaxStamina, mMap);
}
void addGate(int mGateID, int mRow, int mCol) { solution->addGate(mGateID, mRow, mCol); }
void removeGate(int mGateID) { solution->removeGate(mGateID); }
int getMinTime(int mStartGateID, int mEndGateID) { return solution->getMinTime(mStartGateID, mEndGateID); }
////////////////////////////////////////////////////////////////////////////////