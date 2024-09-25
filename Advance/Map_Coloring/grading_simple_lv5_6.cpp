#include <stdio.h>
#include <string.h>

char b1[3000005], b2[3000005], sol1[3000005], sol2[3000005];
bool isSpace(char c) {
    return c == '\n' || c == '\t' || c == '\r' || c == ' ';
}
void removeTrailingSpace(char *a) {
    int len = strlen(a);
    while (len > 0 && isSpace(a[len - 1])) {
        len--;
        a[len] = '\0';
    }
}
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "usagessss : %s system_input.txt correct_answer.txt user_output.txt",
                argc == 0 ? "grading" : argv[0]);
        return 0;
    }
    FILE *inp = fopen(argv[1], "r");
    if (inp == NULL) {
        fprintf(stderr, "No File %s", argv[1]);
        return 0;
    }
    FILE *sol = fopen(argv[2], "r");
    if (sol == NULL) {
        fprintf(stderr, "No File %s", argv[2]);
        return 0;
    }
    FILE *out = fopen(argv[3], "r");
    if (out == NULL) {
        fprintf(stderr, "No File %s", argv[3]);
        return 0;
    }

    int T;
    double score = 0;

    int ok = 0, i;

    fscanf(inp, "%d", &T);

    for (i = 0; i < T; i++) {
        fgets(sol1, 3000000, sol);
        fgets(b1, 3000000, out);
        b1[3000000] = sol1[3000000] = '\0';
        removeTrailingSpace(b1);
        removeTrailingSpace(sol1);
        if (strcmp(b1, sol1) == 0)
            score += 100.0 / T;
        else
            score += 0;
    }
    printf("%.3lf", score);
    fclose(inp);
    fclose(out);
    fclose(sol);
    return 0;
}
