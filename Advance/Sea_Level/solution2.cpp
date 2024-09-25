#include<iostream>

using namespace std;

int t, n, m, rear, front, k;
int a[101][101], visited[101][101], ngap[101][101], qX[10002], qY[10002], sX, sY, check, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initQueue() {
	rear = front = -1;
}

int isEmpty() {
	if (rear == front)
		return 1;
	return 0;
}

void enQueue(int x, int y) {
	rear++;
	qX[rear] = x;
	qY[rear] = y;
}

int deQueueX() {
	if (!isEmpty())
		return qX[front + 1];
	return -1;
}

int deQueueY() {
	if (!isEmpty()) {
		front++;
		return qY[front];
	}
	return -1;
}

void resetNgap(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ngap[i][j] = 0;
		}
	}
}
void resetV(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			visited[i][j] = 0;
		}
	}
}

void BFS(int h, int i, int j) {
	initQueue();
	enQueue(i, j);
	visited[i][j] = 1;
	ngap[i][j] = 1;
	int x, y, tx, ty, k;
	while (!isEmpty()) {
		x = deQueueX();
		y = deQueueY();
		for (k = 0; k < 4; k++) {
			tx = x + dx[k];
			ty = y + dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m && visited[tx][ty] == 0) {
				if (a[tx][ty] <= h) {
					enQueue(tx, ty);
					visited[tx][ty] = 1;
					ngap[tx][ty] = 1;
				}
				else{
					visited[tx][ty] = 1;
				}
			}

		}
	}


}
void BFS_check(int i, int j) {
	initQueue();
	enQueue(i, j);
	visited[i][j] = 1;
	int x, y, tx, ty, k;
	while (!isEmpty()) {
		x = deQueueX();
		y = deQueueY();
		for (k = 0; k < 4; k++) {
			tx = x + dx[k];
			ty = y + dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m && ngap[tx][ty] == 0 && visited[tx][ty] == 0) {
				enQueue(tx, ty);
				visited[tx][ty] = 1;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	t = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int i, j, max = 0, x;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cin >> a[i][j];
				if (a[i][j] > max){
					max = a[i][j];
				}
			}
		}
		check = true;
		ans = 0;
		for (x = 1; x < max ; x++) {
			resetNgap();
			resetV();
			for (i = 0; i < n ; i++){
				for (j = 0; j < m; j++){
					if ((i == 0 || j == 0 || i == n-1 || j == m-1) && visited[i][j] == 0 && a[i][j] <= x ){
						BFS(x, i, j);
					}
				}
			}
			resetV();
			int dem = 0;
			for (i = 0; i < n; i++){
				for (j = 0; j < m; j++){
					if (dem > 1){
						check = false;
						break;
					}
					if (ngap[i][j] == 0 && visited[i][j] == 0){
						BFS_check(i, j);
						dem++;
					}
				}
			}
			if (!check){
				ans = x;
				break;
			}
		}
		

		if (check)
			cout << "Case " << t << ": Island never splits." << endl;
		else 
			cout << "Case " << t << ": Island splits when ocean rises " << ans << " feet." << endl;
		t++;

	}
	return 0;
}