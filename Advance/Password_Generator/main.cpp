#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define TEST_CASE	10
#define DIGIT_COUNT 8
#define MAX_CYCLE	5

using namespace std;

int password_generator(int arr[DIGIT_COUNT]);
void rearrange_array(int arr[DIGIT_COUNT], int swap_count);

int main(){
	freopen("test_input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		//read input
		int case_num;
		cin>>case_num;
		int num[DIGIT_COUNT];
		for(int digit=0; digit < DIGIT_COUNT ; digit ++){
			cin>>num[digit];
		}
		int count = password_generator(num);
		rearrange_array(num, count);
		cout << "#" << index+1 ;
		for(int digit=0; digit < DIGIT_COUNT ; digit ++){
			cout << " " << num[digit];
		}
		cout<<endl;
	}

	return 0;
}

int password_generator(int arr[DIGIT_COUNT]){
	int swap_count=0;
	int index = 0;
	while (1){
		for(int cycle=1 ; cycle<=MAX_CYCLE ; cycle++){
			swap_count++;
			arr[index] -= cycle;
			if(arr[index] <= 0){
				arr[index] = 0;
				return swap_count;
			}
			(index==7) ? index=0 : index++;
		}
	}
}

void rearrange_array(int arr[DIGIT_COUNT], int swap_count){
	int diff = 8 - (swap_count%8);
	int temp[DIGIT_COUNT];
	for(int i=0 ; i< DIGIT_COUNT ; i++){
		int index=i+diff;
		if(index >= 8)
			index -= 8;
		temp[index]= arr[i];
	}
	for(int i=0 ; i< DIGIT_COUNT ; i++){
		arr[i]=temp[i];
	}
}