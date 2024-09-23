#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N (10000)
#define MAX_M (10)

extern void init(int, int, char mImage[MAX_N][MAX_M][MAX_M]);
extern int findImage(char cropImage[MAX_M][MAX_M]);

static unsigned int seed = 5;

static char ori_image_list[MAX_N][MAX_M][MAX_M];
static char bak_image_list[MAX_N][MAX_M][MAX_M];
static char dummy[5005];
static char bak_image[MAX_M][MAX_M];

static int pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7fff;
}

static int run(int _score) {
    int n;
    int m;
    int query_cnt;
    int ratio;
    scanf("%d%d%d%d%d", &n, &m, &seed, &ratio, &query_cnt);

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < m; x++) {
                ori_image_list[i][y][x] = 0;
                int v = pseudo_rand() % 100;
                if (v >= ratio)
                    ori_image_list[i][y][x] = 1;
                bak_image_list[i][y][x] = ori_image_list[i][y][x];
            }
        }
    }

    init(n, m, bak_image_list);

    int user_ans, correct_ans;

    for (int query = 0; query < query_cnt; query++) {
        int num = pseudo_rand() % n;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < m; x++) {
                bak_image[y][x] = ori_image_list[num][y][x];
            }
        }

        int bad_sector_cnt = pseudo_rand() % 2 + 1;

        for (int i = 0; i < bad_sector_cnt; i++) {
            int by = pseudo_rand() % m;
            int bx = pseudo_rand() % m;

            bak_image[by][bx] ^= 1;
        }

        user_ans = findImage(bak_image);
        scanf("%d", &correct_ans);

        if (user_ans != correct_ans)
            _score = 0;
    }

    return _score;
}

int main() {
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int tc, score;
    scanf("%d%d", &tc, &score);

    for (int t = 1; t <= tc; t++) {
        printf("#%d %d\n", t, run(score));
    }

    return 0;
}
