#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N 101
#define MAX_STEP 101 //Mỗi step = 10 giờ

int N;
int maxStep;
//danh sách kề
int adjCnt[MAX_N]; //adjCnt[i], số đỉnh kề với đỉnh i

int next[MAX_N][MAX_N]; //Nếu next[i][j] = k thì từ đỉnh i nối đến đỉnh k với trọng số là weight[i][j]
float weight[MAX_N][MAX_N];

//changeByStep[i][j]: Khả năng đi đến căn hộ thứ j tại bước thứ i (thời gian từ i * 10 tới i * 10 + 9)
float chanceByStep[MAX_STEP][MAX_N];

///////Cách 1: BFS dùng queue
//Queue
int verticeQ[20010];
int stepQ[20010];
int front, rear;

int lastVisitedStep[MAX_N]; //Bảng trạng thái visit

void calculateChances()
{
	int u, v, step;
	front = rear = 0;
	verticeQ[0] = 1;
	stepQ[0] = 0;
	while (front <= rear) {
		u = verticeQ[front];
		step = stepQ[front++];
		for (int i = 0; i < adjCnt[u]; ++i) {
			v = next[u][i];
			chanceByStep[step + 1][v] += chanceByStep[step][u] * weight[u][i]; //update khả năng tại đỉnh v và bước step + 1

			//nếu next step vượt qua maxStep, không cần đưa v vào queue
			if (lastVisitedStep[v] < step + 1 && step < maxStep) {
				lastVisitedStep[v] = step + 1;
				verticeQ[++rear] = v;
				stepQ[rear] = step + 1;
			}
		}
	}
}
////////////////////////////////////


//Cách 2: BFS không dùng queue
//void calculateChances2()
//{
//	int v;
//	for (int step = 0; step < maxStep; ++step) {
//		for (int u = 1; u <= N; ++u) {
//			//nếu tại bước step có khả năng đi vào đỉnh u, tính toán khả năng từ đỉnh u đi vào các đỉnh kề của nó tại bước step + 1
//			if (chanceByStep[step][u] > 0) { 
//				for (int i = 0; i < adjCnt[u]; ++i) {
//					v = next[u][i];
//					chanceByStep[step + 1][v] += chanceByStep[step][u] * weight[u][i];
//				}
//			}
//		}
//	}
//}
///////////////////////////////

//Tìm căn hộ có khả năng cao nhất tại 1 bước nào đó (tìm kiếm tuần tự)
float maxChange;
int maxIdx;
void findMax(int step)
{
	maxIdx = 0;
	maxChange = 0.0;
	for (int i = 1; i <= N; i++) {
		if (chanceByStep[step][i] > maxChange) {
			maxChange = chanceByStep[step][i];
			maxIdx = i;
		}
	}
}


int bruh()
{
	int tc, T = 10;
	int st, en;
	float w;
	int E, K, mTime;
	
	freopen("department_input.txt", "r", stdin);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d%d%d%d", &N, &E, &K, &mTime);
		for (int i = 1; i < MAX_N; i++) {
			adjCnt[i] = 0;
			lastVisitedStep[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			scanf("%d%d%f", &st, &en, &w);
			next[st][adjCnt[st]] = en;
			weight[st][adjCnt[st]++] = w;
		}

		//if (mTime < 10) {
		//	printf("#%d 1 1.000000 1 1.000000\n", tc);
		//	continue;
		//}

		maxStep = mTime / 10;
		//reset DP table
		for (int i = 0; i <= maxStep; i++)
			for (int j = 1; j <= N; j++)
				chanceByStep[i][j] = 0;
		chanceByStep[0][1] = 1; //tại step 0, khả năng tại căn hộ 1 luôn là 100%

		//Gọi 1 trong 2 hàm này đều được
		calculateChances(); //dùng queue
		//calculateChances2(); //không dùng queue

		findMax(maxStep);
		printf("#%d %d %f ", tc, maxIdx, maxChange);
		findMax((mTime - K) / 10);
		printf("%d %f\n", maxIdx, maxChange);
	}
	return 0;
}