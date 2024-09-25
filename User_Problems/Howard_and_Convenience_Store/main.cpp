#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

const int N_MAX = 1000;

using namespace std;
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
    for (int t = 0; t < T; t++) {
        int N; // number of bags of chips
        int M; // limit on weight sum
        cin >> N >> M;

        int arr[N_MAX] = {};
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        int ans = -1;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int sum = arr[i] + arr[j];
                if (sum > ans && sum <= M)
                    ans = sum;
            }
        }

        cout << "#" << t+1 << " " << ans << endl;
    }

    return 0;
}