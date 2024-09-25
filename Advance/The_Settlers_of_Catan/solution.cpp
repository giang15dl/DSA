#include<iostream>
using namespace std;
int N, M;
int arr[26][26];
int maxCanh = 0;
int visit[26][26];
void BT(int dinh, int cntCanh){
	if(cntCanh > maxCanh){
		maxCanh = cntCanh;
	}
	for (int i = 0; i < N; i++)
	{
		if(arr[dinh][i] == 1 && visit[dinh][i] == 0){
			visit[dinh][i] = 1;
			visit[i][dinh] = 1;
			BT(i, cntCanh+1);
			visit[dinh][i] = 0;
			visit[i][dinh] = 0;
		}
	}
}

void clear_canh(){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int Answer;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	int node1, node2;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++)
		{
			cin >> node1 >> node2;
			arr[node1][node2] = 1;
			arr[node2][node1] = 1;
		}
		maxCanh = 0;
		for (int i = 0; i < N; i++)
		{
			clear_canh();
			BT(i, 0);
		}
		cout << maxCanh << endl;
	}
	return 0;
}