#include <iostream>
#define TEST_CASE 10

using namespace std;

int sufficient_count (int (&arr)[5]);

int main(){
	ios::sync_with_stdio(false);
	freopen("view_test_input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int test_length;
		cin >> test_length;

		int building[1000];

		for(int i=0; i<test_length ; i++){
			cin >> building[i];
		}

		int five_building[5];
		int ans=0;
		for(int i=0 ; i< test_length ; i++){
			for(int j=0 ; j<5 ; j++){
				five_building[j]=building[j+i];
			}
			ans += sufficient_count(five_building);
		}
		cout << "#" << index+1 << " " << ans << endl;
	}
	return 0;
}

int sufficient_count (int (&arr)[5]){
	int reference = arr[2];

	if(arr[0]>=reference)
		return 0;
	if(arr[1]>=reference)
		return 0;
	if(arr[3]>=reference)
		return 0;
	if(arr[4]>=reference)
		return 0;

	int second_tallest=0;
	
	if(arr[0]>second_tallest)
		second_tallest=arr[0];
	if(arr[1]>second_tallest)
		second_tallest=arr[1];
	if(arr[3]>second_tallest)
		second_tallest=arr[3];
	if(arr[4]>second_tallest)
		second_tallest=arr[4];
	
	return (reference-second_tallest);
}