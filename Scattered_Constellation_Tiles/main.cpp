#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_SIZE 1000
extern void init(int N, int mPlane[MAX_SIZE][MAX_SIZE]);
extern int getCount(int mPiece[5][5]);
extern int getPosition(int mRow, int mCol);

#define CMD_INIT 0
#define CMD_CNT 1
#define CMD_POSITION 2

static int Map[MAX_SIZE][MAX_SIZE];
static int Piece[5][5];
static int Data[40000];

static void init_map(int N) {
    int idx = 0;

    int x = 0;
    for (int i = 0; i < (N / 25); i++) {
        for (int y = 0; y < N; y++) {
            int data = Data[idx++];
            int bit = 1;
            for (int m = 0; m < 25; m++) {
                if ((data & bit) != 0)
                    Map[y][x + m] = 1;
                else
                    Map[y][x + m] = 0;
                bit <<= 1;
            }
        }
        x += 25;
    }

    int dcnt = N % 25;
    if (dcnt != 0) {
        for (int y = 0; y < N; y++) {
            int data = Data[idx++];
            int bit = 1;
            for (int m = 0; m < dcnt; m++) {
                if ((data & bit) != 0)
                    Map[y][x + m] = 1;
                else
                    Map[y][x + m] = 0;
                bit <<= 1;
            }
        }
    }
}

static void make_piece(int data) {
    int bit = 1;
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            if ((data & bit) != 0)
                Piece[i][k] = 1;
            else
                Piece[i][k] = 0;
            bit <<= 1;
        }
    }
}

static bool run() {
    int Q, N, row, col, cnt;
    int ret, ans;

    bool ok = false;

    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == CMD_INIT) {
            scanf("%d %d", &N, &cnt);
            for (int i = 0; i < cnt; i++)
                scanf("%d", &Data[i]);
            init_map(N);
            init(N, Map);
            ok = true;
        } else if (cmd == CMD_CNT) {
            scanf("%d", &Data[0]);
            make_piece(Data[0]);
            ret = getCount(Piece);
            scanf("%d", &ans);
            if (ans != ret) {
                ok = false;
            }
        } else if (cmd == CMD_POSITION) {
            scanf("%d %d", &row, &col);
            ret = getPosition(row, col);
            scanf("%d", &ans);
            if (ans != ret) {
                ok = false;
            }
        } else
            ok = false;
    }
    return ok;
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
