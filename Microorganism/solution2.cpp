#include <queue>
#include <set>

using namespace std;
class Solution {
    static const int MAX_B = 30'000 + 1;
    static const int MAX_T = 1'000'000;
    static const int RATE = 1000;
    static const int MAX_S = MAX_T / RATE + 1;

private:
    struct Bacteria {
        int id;
        int lifeSpan;
        int halfTime;
        int nextHalfTime;
        Bacteria() : id(0), lifeSpan(0), halfTime(0), nextHalfTime(0) {}
        Bacteria(int id, int lifeSpan, int halfTime, int nextHalfTime) : id(id),
                                                                         lifeSpan(lifeSpan),
                                                                         halfTime(halfTime),
                                                                         nextHalfTime(nextHalfTime) {}
    } bacterias[MAX_B];

    struct greater {
        bool operator()(const Bacteria a, const Bacteria b) {
            return a.nextHalfTime > b.nextHalfTime;
        }
    };

    struct less {
        bool operator()(const Bacteria a, const Bacteria b) const {
            return (a.lifeSpan == b.lifeSpan) ? a.id < b.id : a.lifeSpan < b.lifeSpan;
        }
    };

    priority_queue<Bacteria, vector<Bacteria>, greater> heapNextHalfTime;
    set<Bacteria, less> treeLifeSpan[MAX_S];

    void update(int time) {
        while (!heapNextHalfTime.empty()) {
            Bacteria bacteria = heapNextHalfTime.top();
            if (bacteria.nextHalfTime > time)
                break;

            heapNextHalfTime.pop();
            treeLifeSpan[bacteria.lifeSpan / RATE].erase(bacteria);

            int nextlifespan = bacteria.lifeSpan / 2;

            if (nextlifespan > 99) {
                bacteria.lifeSpan = nextlifespan;
                bacteria.nextHalfTime += bacteria.halfTime;
                heapNextHalfTime.push(bacteria);
                treeLifeSpan[nextlifespan / RATE].insert(bacteria);
            }
        }
    }

public:
    Solution() {}
    void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) {
        bacterias[mID] = Bacteria(mID, mLifeSpan, mHalfTime, tStamp + mHalfTime);
        heapNextHalfTime.push(bacterias[mID]);
        treeLifeSpan[mLifeSpan / RATE].insert(bacterias[mID]);
    }

    int getMinLifeSpan(int tStamp) {
        update(tStamp);
        for (int i = 0; i < MAX_S; i++)
            if (!treeLifeSpan[i].empty())
                return treeLifeSpan[i].begin()->id;

        return -1;
    }

    int getCount(int tStamp, int mMinSpan, int mMaxSpan) {
        update(tStamp);
        int count = 0;
        int diff = (mMaxSpan / RATE) - (mMinSpan / RATE);
        if (diff == 0) {
            for (auto it : treeLifeSpan[mMinSpan / RATE]) {
                if (it.lifeSpan > mMaxSpan) {
                    break;
                }
                if (it.lifeSpan >= mMinSpan) {
                    count++;
                }
            }
        }
        if (diff == 1) {
            for (auto it : treeLifeSpan[mMinSpan / RATE]) {
                if (it.lifeSpan >= mMinSpan) {
                    count++;
                }
            }
            for (auto it : treeLifeSpan[mMaxSpan / RATE]) {
                if (it.lifeSpan > mMaxSpan) {
                    break;
                }
                count++;
            }
        }
        if (diff > 1) {
            for (auto it : treeLifeSpan[mMinSpan / RATE]) {
                if (it.lifeSpan >= mMinSpan) {
                    count++;
                }
            }
            for (auto it : treeLifeSpan[mMaxSpan / RATE]) {
                if (it.lifeSpan > mMaxSpan) {
                    break;
                }
                count++;
            }
            for (int i = (mMinSpan / RATE) + 1; i < (mMaxSpan / RATE); i++) {
                count += treeLifeSpan[i].size();
            }
        }

        return count;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Solution solution;
void init() { solution = Solution(); }
void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) { solution.addBacteria(tStamp, mID, mLifeSpan, mHalfTime); }
int getMinLifeSpan(int tStamp) { return solution.getMinLifeSpan(tStamp); }
int getCount(int tStamp, int mMinSpan, int mMaxSpan) { return solution.getCount(tStamp, mMinSpan, mMaxSpan); }
