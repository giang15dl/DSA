#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mHeight[]);
extern int countPosition(int mLen, int mTank[]);
extern int buildAndPourOut(int mLen, int mTank[], int mWater);

#define CMD_INIT 1
#define CMD_COUNT 2
#define CMD_BUILD 3

#define MAX_N 50000

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int N;
            int mHeight[MAX_N];
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
            {
                scanf("%d", &mHeight[i]);
            }
            init(N, mHeight);
            ok = true;
        }
        else if (query == CMD_COUNT)
        {
            int mLen, mTank[5];
            scanf("%d", &mLen);
            for (int i = 0; i < mLen; i++)
            {
                scanf("%d", &mTank[i]);
            }
            int ret = countPosition(mLen, mTank);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_BUILD)
        {
            int mLen, mTank[5], mWater;
            scanf("%d", &mLen);
            for (int i = 0; i < mLen; i++)
            {
                scanf("%d", &mTank[i]);
            }
            scanf("%d", &mWater);
            int ret = buildAndPourOut(mLen, mTank, mWater);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
     freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);
    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
