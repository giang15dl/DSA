#include<iostream>
using namespace std;

int t, tc, n, m, u, v;
int a[105][105];
int visited[105];
int cntTime[105];
int cntRoad;

void reset(){
	cntRoad =0;
	for(int i =1; i<=n; i++){
		visited[i] = cntTime[i] = 0;
		for(int j =1; j<=n; j++){
			a[i][j] = a[j][i] = 0;
		}

	}

}

void DFS(int start, int end){
	if(start == end){
		cntRoad ++;
		for(int i =1; i<=n; i++){
			if(visited[i]){
				cntTime[i]++;
			}
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(a[start][i] == 1 && !visited[i]){
			visited[i] =1;
			DFS(i, end);
			visited[i] = 0;
		}

	}


}



int main(){
	freopen("input.txt", "r", stdin);
	cin>>t;
	for(tc=1; tc<=t; tc++){
		cin>>n>>m>>u>>v;
		reset();
		for(int i =0; i <m; i++){
			int x, y;
			cin>>x>>y;
			a[x][y] = 1;
		}
		visited[u] = 1;
		DFS(u, v);
		visited[u] = 0;
		int ans =0;
		for(int i =1; i<=n; i++){
			if(i!= u && i !=v && cntTime[i] == cntRoad){
				ans++;
			}
		}
		cout<<ans<<endl<<endl;
	}



	return 0;
}
