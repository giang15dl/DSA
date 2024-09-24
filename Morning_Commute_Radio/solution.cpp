class Solution {
private:
    static const int MAX_N = 100'000;
    static const int MAX_M = 1'000;

private:
    // Number of points on the roads. Point ID is numbered from 0 to N - 1.
    // N points means N - 1 sections. Section ID is numbered from 0 to N - 2.
    // 10 <= N <= 100.000
    int N;

    // Number of road types.
    // There is no more than 200 sections of the same road types.
    // 1 <= M <= 1.000
    int M;

    // The road type of each sections
    // 0 <= types[i] <= M - 1; 0 <= i <= N - 2
    int *mType;

    // The current expected passage times of each section
    // 1 <= times[i] <= 1.000; 0<= i <= N - 2
    int *mTime;

public:
    Solution(int N, int M, int mType[], int mTime[]) : N(N), M(M), mType(mType), mTime(mTime) {
    }

    ~Solution() {}

    // Update passage time of section mID to mNewTime
    void update(int mID, int mNewTime) {
        mTime[mID] = mNewTime;
    }

    // Update the passage time of all sections whose types are mTypeID.
    // Return sum of all updated sections' passage times.
    // sum <= 2.000.000.000
    int updateByType(int mTypeID, int mRatio256) {
        int sum = 0;

        for (int i = 0; i <= N - 2; i++) {
            if (mType[i] == mTypeID) {
                mTime[i] = mTime[i] * mRatio256 / 256;
                sum += mTime[i];
            }
        }

        return sum;
    }

    // Calculate the expected time it takes to move from Point mA to Point mB.
    // mA != mB is guaranteed
    // mA is not neccessary smaller than mB
    // Return the expected time.
    // Expected time <= 2.000.000.000
    int calculate(int mA, int mB) {
        int begin = (mA < mB) ? mA : mB;
        int end = (mA < mB) ? mB : mA;

        int totalTime = 0;
        for (int i = begin; i < end; i++) {
            totalTime += mTime[i];
        }

        return totalTime;
    }

} * solution;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int mType[], int mTime[]) { solution = new Solution(N, M, mType, mTime); }
void destroy() { delete solution; }
void update(int mID, int mNewTime) { solution->update(mID, mNewTime); }
int updateByType(int mTypeID, int mRatio256) { return solution->updateByType(mTypeID, mRatio256); }
int calculate(int mA, int mB) { return solution->calculate(mA, mB); }
