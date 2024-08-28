#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

struct Result {
    int current_rank;
    int best_rank;
    int worst_rank;
};

#define INIT 0
#define NEW_PLAYER 1
#define NEW_PROBLEM 2
#define CHANGE_PROBLEM_SCORE 3
#define ATTEMPT_PROBLEM 4
#define GET_RANK 5

extern void init();
extern void destroy();
extern void newPlayer(char mPlayerName[]);
extern void newProblem(char mProblemName[], int mScore);
extern void changeProblemScore(char mProblemName[], int mNewScore);
extern void attemptProblem(char mPlayerName[], char mProblemName[], int mAttemptResult);
extern Result getRank(char mPlayerName[]);
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int run(int tc_result)
{
    int N;
    scanf("%d",&N);
    init();

    for (int i = 0; i < N; ++i) {
        int cmd = 0;

        char mPlayerName[64], mProblemName[64];
        int mScore, mNewScore, mAttemptResult;
        int current_rank_ans, best_rank_ans, worst_rank_ans;
        Result res;

        scanf("%d",&cmd);
        switch (cmd) {
        case NEW_PLAYER:
            scanf("%s", mPlayerName);
            newPlayer(mPlayerName);
            break;
        case NEW_PROBLEM:
            scanf("%s %d", mProblemName, &mScore);
            newProblem(mProblemName, mScore);
            break;
        case CHANGE_PROBLEM_SCORE:
            scanf("%s %d", mProblemName, &mNewScore);
            changeProblemScore(mProblemName, mNewScore);
            break;
        case ATTEMPT_PROBLEM:
            scanf("%s %s %d", mPlayerName, mProblemName, &mAttemptResult);
            attemptProblem(mPlayerName, mProblemName, mAttemptResult);
            break;
        case GET_RANK:
            scanf("%s", mPlayerName);
            res = getRank(mPlayerName);
            scanf("%d %d %d", &current_rank_ans, &best_rank_ans, &worst_rank_ans);
            if ( !(res.current_rank == current_rank_ans && res.best_rank == best_rank_ans && res.worst_rank == worst_rank_ans) ) {
                tc_result = 0;
            }
            break;
        }        
    }

    destroy();

    return tc_result;
}

int main() {
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin); 

    int T, score;
    scanf("%d %d", &T, &score);
    for(int tc = 1; tc <= T; tc++) {
        printf("#%d %d\n", tc, run(score));
    }

    return 0;
}
