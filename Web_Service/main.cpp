#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mPostingIDs[], int mHashTagNum[], char mHashTags[][5][10]);
extern void addPosting(int ID, int mHashTagNum, char mHashTags[][10]);
extern void removePosting(int ID);
extern int findPostingList(int M, char mKeyWords[][10], int mPageNum, int mAnsIDs[]);

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_FIND 400

static int postingIDs[10000];
static int postingNums[10000];
static char initHashTags[10000][5][10];

static bool run()
{
    bool is_ok = false;
    int query_num = 0;
    scanf("%d", &query_num);

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            int N;
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
            {
                scanf("%d %d", &postingIDs[i], &postingNums[i]);
                for (int j = 0; j < postingNums[i]; j++)
                {
                    scanf("%s", initHashTags[i][j]);
                }
            }

            init(N, postingIDs, postingNums, initHashTags);
            is_ok = true;
        }
        else if (query == CMD_ADD)
        {
            int ID = 0, postingNUM = 0;
            char hashTags[5][10] = { 0, };
            scanf("%d %d", &ID, &postingNUM);
            for (int i = 0; i < postingNUM; i++)
                scanf("%s", hashTags[i]);

            addPosting(ID, postingNUM, hashTags);
        }
        else if (query == CMD_REMOVE)
        {
            int ID = 0;
            scanf("%d", &ID);
            removePosting(ID);
        }
        else if (query == CMD_FIND)
        {
            int M = 0;
            char keyWords[2][10] = { 0, };

            int pageNum = 0;
            scanf("%d", &M);
            for (int i = 0; i < M; i++)
            {
                scanf("%s", keyWords[i]);
            }
            scanf("%d", &pageNum);
            int user_ans_list[10] = { 0, };
            int user_ans = findPostingList(M, keyWords, pageNum, user_ans_list);
            int correct_ans = 0;
            int correct_ans_list[10] = { 0, };
            scanf("%d", &correct_ans);

            if (user_ans != correct_ans)
                is_ok = false;

            for (int i = 0; i < correct_ans; i++)
            {
                scanf("%d", correct_ans_list + i);
                if (correct_ans_list[i] != user_ans_list[i])
                    is_ok = false;
            }
        }
    }

    return is_ok;
}

int main() {
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int TC, MARK;

    scanf("%d %d", &TC, &MARK);
    for (int tc = 1; tc <= TC; ++tc)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
