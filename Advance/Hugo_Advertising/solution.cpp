#include<iostream>
using namespace std;

int t, tc,n;
int L[4], P[4];
int minT, maxT;
int adv[4][2];
int V[51][2];
int res;

void reset(){
	for(int i=1; i<=3; i++){
		adv[i][0] = adv[i][1] = 0;
	}
}

int calc(){
	int point =0;
	for(int i=1; i<=n; i++){
		int maxPoint =0;
		for(int j=1; j<=3; j++){
			if(adv[j][0] >= V[i][0] && adv[j][1]<= V[i][1]){
				maxPoint = max(maxPoint, P[j]);
			}
		}
		point += maxPoint;
	}
	return point;
}

int check(int k, int st_slot) {
	for (int i = 1; i < k; i++) {
		int ed_slot = st_slot + L[k]-1;

		if (adv[i][0] <= st_slot && st_slot <= adv[i][1]) return 0;
		if (adv[i][0] <= ed_slot && ed_slot <= adv[i][1]) return 0; 
		if (st_slot <= adv[i][0] && adv[i][0] <= ed_slot) return 0; 
		if (st_slot <= adv[i][1] && adv[i][1] <= ed_slot) return 0;
	}
	return 1; 
}

void set(int k, int st_slot) { 
	adv[k][0] = st_slot;
	adv[k][1] = st_slot + L[k]-1;
}

void unset(int k, int st_slot) { 
	adv[k][0] = adv[k][1] = 0;
}

void backtrack(int k) {
	if (k == 4) { 
		int point = calc();
		if (point > res)
			res = point; 
		return;
	}

	for (int i = minT; i <= maxT+1; i++) {
		if (check(k, i)) {
			set(k, i);
			backtrack(k + 1);
			unset(k, i);

		}
	}
}


int main(){
	//freopen("input.txt", "r", stdin);
	cin>>t;
	for(tc =1; tc<=t; tc++){
		cin>>n;
		cin>>L[1]>>L[2]>>L[3];
		cin>>P[1]>>P[2]>>P[3];
		minT = 1000000, maxT = -1;
		int a, d;
		for(int i =1; i<=n; i++){
			cin>>a>>d;
			V[i][0] = a;
			V[i][1] = a + d -1;
			if (V[i][1] > maxT) maxT = V[i][1];
			if (V[i][0] < minT) minT = V[i][0];
		}
		reset();
		res =0;
		backtrack(1);
		cout<<"Case #"<<tc<<endl;
		cout<<res<<endl;
	}


	return 0;
}