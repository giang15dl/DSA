#include <string>
#include <unordered_map>

#define MAX_BCNT	100
#define MAX_NAME	10

using std::string;
using std::unordered_map;

class Solution {
private:
    int N;

    struct Type {
        string name;
        int halfTime;
        Type () : name(), halfTime(0) {}
        Type (char name[], int halfTime) : name(name), halfTime(halfTime) {}
    }types[MAX_BCNT];

    struct Bacteria {
        Type type;
        int count;
        int lifeForce;
        int time;
        Bacteria() : type(), count(0), lifeForce(0), time(0) {}
        int life(int timeStamp) {
            while (true) {
                if (timeStamp == time) 
                    return lifeForce;
                if (timeStamp < time) {
                    time-=type.halfTime;
                    lifeForce *= 2;
                    return lifeForce;
                }
                time += type.halfTime;
                lifeForce /= 2;
                if (lifeForce <= 9) {
                    if (timeStamp == time) {
                        lifeForce = 0;
                        return lifeForce;
                    }
                    if (timeStamp < time) {
                        time-=type.halfTime;
                        lifeForce *= 2;
                        return lifeForce;
                    }
                }
            }
        }
    }bacteria[15000];
    int cnt;

public:
    Solution() {}

    Solution(int N, char bNameList[MAX_BCNT][MAX_NAME], int mHalfTime[MAX_BCNT]) : N(N), cnt(0) {
        for (int i = 0; i < N; i++)
            types[i] = Type(bNameList[i], mHalfTime[i]);
    }

    void addBacteria(int tStamp, char bName[MAX_NAME], int mLife, int mCnt) {
        for (int i = 0; i < N; i++) {
            if (types[i].name == bName) {
                bacteria[cnt].type = types[i];
                break;
            }
        }
        bacteria[cnt].lifeForce = mLife;
        bacteria[cnt].count = mCnt;
        bacteria[cnt].time = tStamp;
        cnt++;
    }

    int takeOut(int tStamp, int mCnt) {
        int min = INT_MAX;
        int minIdx = 0;
        for (int i = 0; i < cnt; i++) {
            int life = bacteria[i].life(tStamp);
            if (life > 0 && life < min)
                min = life, minIdx = i;
        }
        if (min != INT_MAX)
            return (mCnt > bacteria[minIdx].count) ? bacteria[minIdx].count*min : mCnt*min ;
        return 0;
    }

    int checkBacteria(int tStamp, char bName[MAX_NAME]) {
        int total = 0;
        for (int i = 0; i < cnt; i++) {
            if (bacteria[i].type.name != bName)
                continue;
            int life = bacteria[i].life(tStamp);
            if (life > 0)
                total += bacteria[i].count;
        }
        return total;
    }
}solution;

///////////////////////////////////////////////////////////////////////////////

void init(int N, char bNameList[MAX_BCNT][MAX_NAME], int mHalfTime[MAX_BCNT]) {
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