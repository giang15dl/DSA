#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main(){
	freopen("test_input.txt", "r", stdin);
	int index;
	while(cin >> index){
		int First, Second, Ans=1;
		cin >> First >> Second;
		for(int i=0 ; i< Second ; i++){
			Ans*=First;
		}
		cout << "#" << index << " " << Ans << endl;
	}

	return 0;
}