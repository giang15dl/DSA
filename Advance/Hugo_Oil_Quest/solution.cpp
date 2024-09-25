#include<iostream>

using namespace std;

int t, tc, n, m, sx, sy, p, dem, front, rear;
int a[55][55], visited[55][55], qx[3000], qy[3000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int d[8][4] ={{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0 , 0, 1}};

void initQ() {
	front = rear = -1;
}

int isEmpty() {
	if (front == rear)
		return 1;
	return 0;
}

void enQueue(int x, int y) {
	rear++;
	qx[rear] = x;
	qy[rear] = y;
}

int deQueueX() {
	if(!isEmpty())
		return qx[front + 1];
	return -1;
}

int deQueueY() {
	if(!isEmpty()) {
		front++;
		return qy[front];
	}
	return -1;
}

int check(int x, int y, int k) {
	if(k == 0 && d[x][k] == 1 && d[y][2] == 1)
		return 1;
	if(k == 1 && d[x][k] == 1 && d[y][3] == 1)
		return 1;
	if(k == 2 && d[x][k] == 1 && d[y][0] == 1)
		return 1;
	if(k == 3 && d[x][k] == 1 && d[y][1] == 1)
		return 1;
	return 0;
}

int dk(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int i, int j) {
	initQ();
	enQueue(i, j);
	visited[i][j] = 1;
	int x, y, tx, ty, k;
	while(!isEmpty()){
		x = deQueueX();
		y = deQueueY();
		if(visited[x][y] >= p)
			return;
		for (k = 0; k < 4; k++){
			tx = x + dx[k];
			ty = y + dy[k];
			if(dk(tx, ty) && visited[tx][ty] == 0 && check(a[x][y], a[tx][ty], k)) {
				enQueue(tx, ty);
				visited[tx][ty] = visited[x][y] + 1;
				dem++;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		cin >> sx >> sy >> p;
		int i, j;
		for (i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				cin >> a[i][j];
				visited[i][j] = 0;
			}
		}
		dem = 1;
		BFS(sx, sy);
		cout << "Case #" << tc << endl;
		cout << dem << endl;
	}
	return 0;
}