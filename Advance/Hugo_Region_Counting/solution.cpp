#include<iostream>
using namespace std;

int N;
int map[105][105];
int temp[105][105];

int visit[105][105];

int cnt[6];

int dR[4] = {0, -1, 0, 1};
int dC[4] = {-1, 0, 1, 0};

struct COOR {
	int r, c;
} Queue[10005], Q[10005];


int front, rear;

void init() {
	front = rear = -1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;

	for (int i = 1; i < 6; i++)
		cnt[i] = 0;
}

void push(int r, int c) {
	rear++;
	Queue[rear].r = r;
	Queue[rear].c = c;
}

COOR pop() {
	return Queue[++front];
}

bool isEmpty() {
	return front == rear;
}

void BFS1(int r, int c) {
	int front1 = -1, rear1 = -1;

	visit[r][c] = 1;
	rear1++;
	Q[rear1].r = r; Q[rear1].c = c;
	cnt[map[r][c]]++;

	while (front1 != rear1) {
		front1++;
		int topR = Q[front1].r; int topC = Q[front1].c;

		for (int i = 0; i < 4; i++) {
			int nR = topR + dR[i];
			int nC = topC + dC[i];

			if (nR >= 0 && nR < N && nC >= 0 && nC < N && !visit[nR][nC]) {
				if (map[nR][nC] == map[topR][topC]) {
					visit[nR][nC] = 1;
					rear1++;
					Q[rear1].r = nR; Q[rear1].c = nC;
					cnt[map[nR][nC]]++;
				}
			}
		}
	}
}

void BFS(int r, int c) {
	init();

	visit[r][c] = 1;
	push(r, c);

	while (!isEmpty()) {
		COOR coor = pop();
		for (int i = 0; i < 4; i++) {
			int nR = coor.r + dR[i];
			int nC = coor.c + dC[i];

			if (nR >= 0 && nR < N && nC >= 0 && nC < N && !visit[nR][nC]) {
				if (temp[nR][nC] == 0) {
					visit[nR][nC] = 1;
					push(nR, nC);
				} else {
					BFS1(nR, nC);
				}
			}
		}
	}
}

void BFS2(int r, int c) {
	visit[r][c] = 1;
	push(r, c);

	while (!isEmpty()) {
		COOR coor = pop();
		for (int i = 0; i < 4; i++) {
			int nR = coor.r + dR[i];
			int nC = coor.c + dC[i];

			if (nR >= 0 && nR < N && nC >= 0 && nC < N && !visit[nR][nC]) {
				if (temp[nR][nC] == temp[coor.r][coor.c]) {
					visit[nR][nC] = 1;
					push(nR, nC);
				}
			}
		}
	}
}

int findMax() {
	int m = -1;
	int idx = 0;
	for (int i = 1; i < 6; i++) {
		if (cnt[i] >= m) {
			m = cnt[i];
			idx = i;
		}
	}
	return idx;
}

int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				temp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] == 0) {
					BFS(i, j);
					int val = findMax();
					for (int i = 0; i <= rear; i++) {
						temp[Queue[i].r][Queue[i].c] = val;
					}
				}
			}
		}

		init();
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					BFS2(i, j);
					ans++;
				}
			}
		}

		cout << "Case #" << test_case << endl << ans << endl;
	}
	return 0;
}