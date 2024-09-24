class Solution {
public:
    Solution(int N, int M, int mType[], int mTime[]) {}
    ~Solution() {}

    void update(int mID, int mNewTime) {
    }

    int updateByType(int mTypeID, int mRatio256) {
        return -1;
    }

    int calculate(int mA, int mB) {
        return -1;
    }

} *solution;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int mType[], int mTime[]) { solution = new Solution(N, M, mType, mTime); }
void destroy() { delete solution; }
void update(int mID, int mNewTime) { solution->update(mID, mNewTime); }
int updateByType(int mTypeID, int mRatio256) { return solution->updateByType(mTypeID, mRatio256); }
int calculate(int mA, int mB) { return solution->calculate(mA, mB); }
