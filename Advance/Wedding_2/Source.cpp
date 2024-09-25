#include<iostream>
using namespace std;

int t, tc, n, m;
int a[26][26];
int visited1[26], visited2[26];
int ans;

void reset() {
	for (int i = 1; i <= n; i++) {
		visited1[i] = 0;
		visited2[i] = 0;
		for (int j = i; j <= n; j++)
			a[i][j] = a[j][i] = 0;
	}
}

int findV(){
	int cnt =0;
	for(int i =1; i<=n; i++){
		if(visited1[i] + visited2[i] >0){
			cnt++;
		}
	}
	return cnt;
}

void DFS1(int cur){
	if(findV() > ans){
		return;
	}
	if(cur == 1){
		int num = findV();
		if(num < ans){
			ans = num;
		}
		return;
	}
	for(int i =1; i<=n; i++){
		if(a[cur][i] == 1 && !visited1[i]){
			visited1[i] = 1;
			DFS1(i);
			visited1[i] = 0;
		}
	}
}

void DFS2(int cur){
	if(findV() > ans){
		return;
	}
	if(cur == 2){
		visited1[cur] = 1;
		DFS1(cur);
		visited1[cur] = 0;
		return;
	}
	for(int i =1; i<=n; i++){
		if(a[cur][i] == 1 && !visited2[i]){
			visited2[i] = 1;
			DFS2(i);
			visited2[i] = 0;
		}
	}
}

int bruh(){
	//freopen("input.txt", "r", stdin);
	cin>>t;
	for(tc=1; tc<=t; tc++){
		cin>>n>>m;
		reset();
		for(int i = 0; i<m; i++){
			int u, v;
			cin>>u>>v;
			a[u][v] = 1;
		}
		ans = 100;
		visited2[1] = 1;
		DFS2(1);
		visited2[1] = 0;
		cout<<ans<<endl;
	}

	return 0;
}
