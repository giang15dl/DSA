const int MAX_N = 10000;
const int MAX_M = 10;

int N, M;
char (*images)[MAX_M][MAX_M];

void init(int mN, int mM, char mImageList[MAX_N][MAX_M][MAX_M]) {
    N = mN;
    M = mM;
    images = mImageList;
}

int findImage(char mImage[MAX_M][MAX_M]) {
    int minDIff = 3;
    int minID = 0;
    for (int id = 0; id < N; id++) {
        char(*image)[MAX_M] = images[id];
        int diffPixels = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (image[i][j] != mImage[i][j])
                    diffPixels++;
                if (diffPixels >= minDIff)
                    break;
            }
            if (diffPixels >= minDIff)
                break;
        }
        if (diffPixels == 0)
            return id + 1;
        if (diffPixels < minDIff)
            minDIff = diffPixels, minID = id;
    }
    return minID + 1;
}