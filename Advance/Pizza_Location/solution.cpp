#include <iostream>

const int LIM_M = 20;  // 20
const int LIM_N = 100; // 100

int K, R;
int M;
int N;

int ans;

int location[LIM_M][2] = {};
int solitaire[LIM_N][3] = {};
int adj[LIM_M][LIM_N] = {};
int p[LIM_M];

int squared(int x);

int squared(int a[2], int b[2]);

void calculateDistance(int (&adj)[LIM_M][LIM_N]);

void backTrack(int step = 0, int st = 0);

using namespace std;
int main(int argc, char **argv){
    const char *input = (argc > 1) ? argv[1] :  "input.txt";
    const char *output = "myout.txt";
    freopen(input, "r", stdin);
    //freopen(output, "w", stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> K >> R; // number of restaurants, Radius of delivery.

        cin >> M; // number of locations
        for (int i = 0; i < M; i++)
            cin >> location[i][0] >> location[i][1];

        cin >> N; // number of solitaires
        for (int i = 0; i < N; i++)
            cin >> solitaire[i][0] >> solitaire[i][1] >> solitaire[i][2];

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                adj[i][j] = 0;
            p[i] = 0;
        }

        ans = 0;
        calculateDistance(adj);
        backTrack();
        cout << "#" << t + 1 << " " << ans << endl;
    }

    return 0;
}

int squared(int x) {
    return x*x;
}

int squared(int a[2], int b[2]) {
    return squared(a[0] - b[0]) + squared(a[1] - b[1]);
}

void calculateDistance(int (&adj)[LIM_M][LIM_N]) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (squared(location[i], solitaire[j]) <= squared(R))
                adj[i][j] = solitaire[j][2];
}

void backTrack(int step, int st) {
    if(step == K) {
        int sum = 0;

        int visited[LIM_N] = {};

        for(int i = 0; i < K; i++) {
            int pl = p[i];
            for(int j = 0; j < N; j++) {
                if(!visited[j] && adj[pl][j]) {
                    sum += adj[pl][j];
                    visited[j] = 1;
                }
            }
        }

        if(sum > ans)
            ans = sum;

        return;
    }

    for(int i = st; i < M; i++) {
        p[step] = i;
        backTrack(step + 1, i + 1);
    }
}
