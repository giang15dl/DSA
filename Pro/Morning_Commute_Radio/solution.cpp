#include <cmath>
#include <vector>

using namespace std;
class Solution {
private:
    static const int MAX_N = 100'000;
    static const int MAX_M = 1'000;
    static const int MAX_SEGMENT = 317; // sqrt(100000)

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

    vector<int> types[MAX_M];

    int segment[MAX_SEGMENT] = {};

    int rate;

public:
    Solution(int N, int M, int mType[], int mTime[]) : N(N), M(M), mType(mType), mTime(mTime) {
        rate = (int)sqrt(N);
        for (int i = 0; i <= N - 2; i++) {
            int segID = i / rate;
            segment[segID] += mTime[i];
            types[mType[i]].push_back(i);
        }
    }

    ~Solution() {}

    // Update passage time of section mID to mNewTime
    void update(int mID, int mNewTime) {
        int segID = mID / rate;
        int diff = mTime[mID] - mNewTime;
        segment[segID] -= diff;
        mTime[mID] = mNewTime;
    }

    // Update the passage time of all sections whose types are mTypeID.
    // Return sum of all updated sections' passage times.
    // sum <= 2.000.000.000
    int updateByType(int mTypeID, int mRatio256) {
        int sum = 0;

        auto &times = types[mTypeID];

        for (int id : times) {
            int oldTime = mTime[id];
            mTime[id] = oldTime * mRatio256 / 256;
            int diff = oldTime - mTime[id];
            int segID = id / rate;
            segment[segID] -= diff;
            sum += mTime[id];
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

        int sum = 0;

        for (int i = begin; i < end;) {
            if (i % rate == 0 && i + rate - 1 < end) {
                int segID = i / rate;
                sum += segment[segID];
                i += rate;
            } else {
                sum += mTime[i];
                i++;
            }
        }

        return sum;
    }

} *solution;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int mType[], int mTime[]) { solution = new Solution(N, M, mType, mTime); }
void destroy() { delete solution; }
void update(int mID, int mNewTime) { solution->update(mID, mNewTime); }
int updateByType(int mTypeID, int mRatio256) { return solution->updateByType(mTypeID, mRatio256); }
int calculate(int mA, int mB) { return solution->calculate(mA, mB); }
