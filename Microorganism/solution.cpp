#include <queue>
#include <set>

using namespace std;
class Solution {
    static const int MAX_B = 30'000 + 1;
    static const int MAX_T = 1'000'000;

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

    struct compare {
        bool operator()(const Bacteria *a, const Bacteria *b) {
            return a->nextHalfTime > b->nextHalfTime;
        }
    };

    struct less {
        bool operator()(const Bacteria *a, const Bacteria *b) const {
            return (a->lifeSpan == b->lifeSpan) ? a->id < b->id : a->lifeSpan < b->lifeSpan;
        }
    };

    struct greater {
        bool operator()(const Bacteria *a, const Bacteria *b) const {
            return (a->lifeSpan == b->lifeSpan) ? a->id > b->id : a->lifeSpan > b->lifeSpan;
        }
    };

    priority_queue<Bacteria *, vector<Bacteria *>, compare> heapNextHalfTime;
    set<Bacteria *, less> tree;

    void update(int time) {
        while (!heapNextHalfTime.empty()) {
            Bacteria *bacteria = heapNextHalfTime.top();

            if (bacteria->nextHalfTime > time)
                break;

            heapNextHalfTime.pop();
            tree.erase(bacteria);

            int life = bacteria->lifeSpan / 2;

            if (life > 99) {
                bacteria->lifeSpan = life;
                bacteria->nextHalfTime += bacteria->halfTime;
                heapNextHalfTime.push(bacteria);
                tree.insert(bacteria);
            }
        }
    }

public:
    Solution() {}
    void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) {
        bacterias[mID] = Bacteria(mID, mLifeSpan, mHalfTime, tStamp + mHalfTime);
        heapNextHalfTime.push(&bacterias[mID]);
        tree.insert(&bacterias[mID]);
    }

    int getMinLifeSpan(int tStamp) {
        update(tStamp);
        auto min = tree.begin();
        auto bacteria = *min;
        return bacteria->id;
    }

    int getCount(int tStamp, int mMinSpan, int mMaxSpan) {
        update(tStamp);

        int count = 0;

        Bacteria min = Bacteria(0, mMinSpan, 0, 0);
        Bacteria max = Bacteria(INT_MAX, mMaxSpan, 0, 0);

        auto lower = tree.lower_bound(&min);
        auto upper = tree.lower_bound(&max);

        if (upper != tree.end() && (*upper)->lifeSpan == max.lifeSpan)
            count++;

        for (auto it = lower; lower != upper; lower++)
            count++;

        return count;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Solution solution;
void init() { solution = Solution(); }
void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) { solution.addBacteria(tStamp, mID, mLifeSpan, mHalfTime); }
int getMinLifeSpan(int tStamp) { return solution.getMinLifeSpan(tStamp); }
int getCount(int tStamp, int mMinSpan, int mMaxSpan) { return solution.getCount(tStamp, mMinSpan, mMaxSpan); }
