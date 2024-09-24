class Solution {
public:
    Solution() {}
    void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) {
    }

    int getMinLifeSpan(int tStamp) {
        return 0;
    }

    int getCount(int tStamp, int mMinSpan, int mMaxSpan) {
        return 0;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Solution solution;
void init() { solution = Solution(); }
void addBacteria(int tStamp, int mID, int mLifeSpan, int mHalfTime) { solution.addBacteria(tStamp, mID, mLifeSpan, mHalfTime); }
int getMinLifeSpan(int tStamp) { return solution.getMinLifeSpan(tStamp); }
int getCount(int tStamp, int mMinSpan, int mMaxSpan) { return solution.getCount(tStamp, mMinSpan, mMaxSpan); }
