#include<iostream>

using namespace std;

int t, tc, n, dem;
int a[30][30], mau[30];

int check(int v, int m) {
	for (int u = 0; u < n; u++) {
		if (a[v][u] == 1){
			if (mau[u] == m)
				return 0;
		}
	}
	return 1;
}

void bT(int v) {
	if (v == n){
		dem++;
		return;
	}
	for (int m = 1; m < 5; m++){
		if(check(v, m)){
			mau[v] = m;
			bT(v+1);
			mau[v] = 0;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (tc = 1; tc <= t; tc++){
		cin >> n;
		int i, j;
		for (i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				cin >> a[i][j];	
			}
			mau[i] = 0;
		}
		dem = 0;
		bT(0);
		cout << "Case #" << tc << endl;
		cout << dem << endl;
	}
	return 0;
}