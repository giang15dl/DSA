#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

/////////////////////////////////////////////////////////////////////////

extern void init(int N, int M, int mRoads[][2]);
extern void addRestaurant(int mCityID, char mName[]);
extern void addValue(char mName[], int mScore);
extern int bestValue(char mStr[]);
extern int regionalValue(int mCityID, int mDist);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD_RESTAURANT 2
#define CMD_ADD_VALUE 3
#define CMD_BEST_VALUE 4
#define CMD_REGIONAL_VALUE 5

static int mRoads[50][2]; // City Adjacent List
static char mName[6];
static char mStr[6];

using namespace std;

static bool run() {
    int numQuery; // Total number of command in a test case
    cin >> numQuery;

    int mCityID, mScore, mDist;

    int userAns, ans;

    bool isCorrect = false;

    for (int i = 0; i < numQuery; ++i) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
        case CMD_INIT:
            int N; // Number of cities
            int M; // Number of roads
            cin >> N >> M;
            for (int j = 0; j < M; j++)
                cin >> mRoads[j][0] >> mRoads[j][1];
            init(N, M, mRoads);
            isCorrect = true;
            break;

        case CMD_ADD_RESTAURANT:
            cin >> mCityID >> mName;
            addRestaurant(mCityID, mName);
            break;

        case CMD_ADD_VALUE:
            cin >> mName >> mScore;
            addValue(mName, mScore);
            break;

        case CMD_BEST_VALUE:
            cin >> mStr;
            userAns = bestValue(mStr);
            cin >> ans;
            if (userAns != ans)
                isCorrect = false;
            break;

        case CMD_REGIONAL_VALUE:
            cin >> mCityID >> mDist;
            userAns = regionalValue(mCityID, mDist);
            cin >> ans;
            if (userAns != ans)
                isCorrect = false;
            break;

        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Total Number of Test cases
    int MARK; // Total Mark
    cin >> T >> MARK;

    for (int t = 0; t < T; t++) {
        int score = run() ? MARK : 0;
        cout << "#" << t+1 << " " << score << endl;
    }

    return 0;
}