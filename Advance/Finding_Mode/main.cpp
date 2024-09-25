#include <iostream>

using namespace std;

#define TEST_CASE 10
#define STUDENTS 1000
#define RANGE 200

int find_max(int arr[], int n);

int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int case_num, ans=0;
		cin >> case_num;

		int scores[STUDENTS];
		for(int i=0 ; i<STUDENTS ; i++)
			cin >> scores[i];

		int frequency[RANGE+1] = {0};
		for(int i=0 ; i< STUDENTS ; i++){
			frequency[scores[i]]++;	
		}

		ans = find_max(frequency, RANGE+1);

		cout<< "#" << case_num << " " << ans << endl;
	}

	return 0;
}

int find_max(int arr[], int n){
	int max=0, max_index=0;

	for(int i=0;i<n;i++){
		if(arr[i]>=max){
			max=arr[i];
			max_index=i;
		}
	}
	return max_index;
}
