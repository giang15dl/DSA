#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern void addProduct(int mPrice, int tagNum, char tagName[][10]);
extern int buyProduct(char tag1[], char tag2[], char tag3[]);
extern void adjustPrice(char tag1[], int changePrice);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define ADD		1
#define BUY		2
#define ADJ		3

static void mstrcpy(char dst[], const char src[]) {
    int c = 0;
    while ((dst[c] = src[c]) != '\0') ++c;
}
static int mstrcmp(const char str1[], const char str2[]) {
    int c = 0;
    while (str1[c] != '\0' && str1[c] == str2[c]) ++c;
    return str1[c] - str2[c];
}

static bool run()
{
    int N, cmd, ans, ret, tnum, price;
    char tag[5][10];

    int Q = 0;
    bool okay = false;

    ret = ans = 0;
    okay = false;

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case INIT:
            scanf("%d", &N);
            init(N);
            okay = true;
            break;
        case ADD:
            scanf("%d %d", &price, &tnum);
            for (int m = 0; m < tnum; m++) {
                scanf("%s", tag[m]);
            }
            addProduct(price, tnum, tag);
            break;
        case BUY:
            scanf("%d", &ans);
            for (int m = 0; m < 3; m++) {
                scanf("%s", tag[m]);
            }
            ret = buyProduct(tag[0], tag[1], tag[2]);
            if (ans != ret) {
                okay = false;
            }
            break;
        case ADJ:
            scanf("%s %d", tag[0], &price);
            adjustPrice(tag[0], price);
            break;
        default:
            okay = false;
        }
    }

    return okay;
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
