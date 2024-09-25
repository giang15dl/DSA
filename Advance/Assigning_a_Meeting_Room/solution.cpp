#include<iostream>
using namespace std;

int t, tc, n;
int a[1001][3];

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}


int main(){
	//freopen("input.txt", "r", stdin);
	cin>>t;
	for(tc =1; tc<=t; tc++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				if(a[j][2] <a[i][2]){
					swap(a[i][2], a[j][2]);
					swap(a[i][1], a[j][1]);
				}
			}
		}
		int nextTime = a[0][2];
		int cnt =1;
		for(int i=0;i<n; i++){
			if(nextTime <= a[i][1]){
				cnt++;
				nextTime = a[i][2];
			}
		}
		cout<<"Case #"<<tc<<endl;
		cout<<cnt<<endl;

	}

	return 0;
}
