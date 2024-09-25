#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern int allocate(int mSize);
extern int release(int mAddr);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ALLOCATE 2
#define CMD_RELEASE 3

static bool run() {
    int q;
    scanf("%d", &q);

    int n, addr, size;
    int cmd, ans, ret = 0;
    bool okay = false;

    for (int i = 0; i < q; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
        case CMD_INIT:
            scanf("%d", &n);
            init(n);
            okay = true;
            break;
        case CMD_ALLOCATE:
            scanf("%d %d", &size, &ans);
            ret = allocate(size);
            if (ans != ret)
                okay = false;
            break;
        case CMD_RELEASE:
            scanf("%d %d", &addr, &ans);
            ret = release(addr);
            if (ans != ret)
                okay = false;
            break;
        default:
            okay = false;
            break;
        }
    }
    return okay;
}

int main() {
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++) {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
