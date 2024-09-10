#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX_BACTERIA 100
#define MAX_NAME 10
#define MAX_BATCH 15000

using namespace std;
class Solution {
private:
    struct Bacteria {
        int halfTime;
        int total;
        Bacteria() : total(0), halfTime() {}
        Bacteria(int halfTime) : total(0), halfTime(halfTime) {}
    } bacterias[MAX_BACTERIA]; // Yes, I know bacteria is a plural word, and it's singular should be bacterium

    struct Batch {
        int nextHalfTime;
        int id;
        int count;
        int life;
        Bacteria *bacteria;
    } batches[MAX_BATCH];
    int batchCount;

    struct HeapCompare {
        bool operator()(Batch *a, Batch *b) const {
            return a->nextHalfTime > b->nextHalfTime;
        }
    };

    struct TreeCompare {
        bool operator()(Batch *a, Batch *b) const {
            return (a->life != b->life) ? a->life < b->life : a->id < b->id;
        }
    };

    unordered_map<string, int> hash;
    priority_queue<Batch *, vector<Batch *>, HeapCompare> heap;
    set<Batch *, TreeCompare> tree;

    void update(int time) {
        while (heap.size() > 0) {
            Batch *batch = heap.top();
            if (batch->nextHalfTime > time)
                break;

            heap.pop();

            if (batch->count == 0)
                continue;

            tree.erase(batch);

            int life = batch->life / 2;

            Bacteria *bacteria = batch->bacteria;
            if (life > 9) {
                batch->life = life;
                batch->nextHalfTime += bacteria->halfTime;
                heap.push(batch);
                tree.insert(batch);
            } else {
                bacteria->total -= batch->count;
            }
        }
    }

    int getBacteriaID(char name[]) {
        return hash.find(name)->second;
    }

    Bacteria getBacteria(char name[]) {
        int id = getBacteriaID(name);
        return bacterias[id];
        ;
    }

public:
    Solution() {}

    Solution(int N, char bNameList[MAX_BACTERIA][MAX_NAME], int mHalfTime[MAX_BACTERIA]) {
        batchCount = 0;
        for (int i = 0; i < N; i++) {
            hash[bNameList[i]] = i;
            Bacteria *bacteria = &bacterias[i];
            bacteria->halfTime = mHalfTime[i];
        }
    }

    void addBacteria(int tStamp, char bName[MAX_NAME], int mLife, int mCnt) {
        update(tStamp);

        int id = getBacteriaID(bName);

        Bacteria *bacteria = &bacterias[id];
        bacteria->total += mCnt;

        Batch *batch = &batches[batchCount++];
        batch->nextHalfTime = tStamp + bacteria->halfTime;
        batch->id = batchCount;
        batch->count = mCnt;
        batch->life = mLife;
        batch->bacteria = bacteria;

        heap.push(batch);
        tree.insert(batch);
    }

    int takeOut(int tStamp, int mCnt) {
        update(tStamp);

        int ret = 0;

        auto it = tree.begin();
        while (it != tree.end() && mCnt > 0) {
            auto curr = it++;
            Batch *batch = *curr;
            int taken = batch->count < mCnt ? batch->count : mCnt;
            ret += batch->life * taken;
            batch->bacteria->total -= taken;
            batch->count -= taken;
            mCnt -= taken;

            if (batch->count == 0)
                tree.erase(curr);
        }
        return ret;
    }

    int checkBacteria(int tStamp, char bName[MAX_NAME]) {
        update(tStamp);
        int id = getBacteriaID(bName);
        return bacterias[id].total;
    }
} solution;

///////////////////////////////////////////////////////////////////////////////

void init(int N, char bNameList[MAX_BACTERIA][MAX_NAME], int mHalfTime[MAX_BACTERIA]) {
    solution = Solution(N, bNameList, mHalfTime);
}

void addBacteria(int tStamp, char bName[MAX_NAME], int mLife, int mCnt) {
    solution.addBacteria(tStamp, bName, mLife, mCnt);
}

int takeOut(int tStamp, int mCnt) {
    return solution.takeOut(tStamp, mCnt);
}

int checkBacteria(int tStamp, char bName[MAX_NAME]) {
    return solution.checkBacteria(tStamp, bName);
}