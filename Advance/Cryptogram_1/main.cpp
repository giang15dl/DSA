#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define TEST_CASE		10
#define ORIGINAL_LENGTH	20
#define MAX_LENGTH		100
#define MAX_COMMANDS	10
#define FINAL_LENGTH	10

using namespace std;

void insert(int original[], int& length, const char& c, const int& x, const int& y, int s[]);
void display ( int arr[], int length);

int main(){
	ios::sync_with_stdio(false);
	freopen("pwd1_test_input.txt", "r", stdin);
	for(int case_index = 0 ; case_index<TEST_CASE ; case_index++){
		int cryptogram_length = 0;
		int command_length = 0;
		int original_cryptograms[MAX_LENGTH] = {0};

		cin >> cryptogram_length;

		for(int i=0; i<cryptogram_length; i++){
			cin >> original_cryptograms[i];
		}

		cin >> command_length;

		for (int i = 0; i < command_length; i++){
			char c; 
			int x,y;
			int s[MAX_COMMANDS] = {0};
			cin >> c;
			cin >> x;
			cin >> y;
			for (int i = 0; i < y; i++){
				cin >> s[i];
			}
			insert(original_cryptograms, cryptogram_length, c, x, y, s);
			//display(original_cryptograms, cryptogram_length);
		}

		cout << "#" << case_index+1 << " ";
		display(original_cryptograms, FINAL_LENGTH);
	}

	return 0;
}

void insert(int* original, int& length, const char& c, const int& x, const int& y, int* s){
	int temp[MAX_LENGTH] = {0};
	length += y;

	for (int i = 0; i < x; i++){
		temp[i] = original[i];
	}
	for(int i=x; i<x+y; i++){
		temp[i] = s[i-x];
	}
	for(int i=x+y; i<length;  i++){
		temp[i] = original[i-y];
	}

	for(int i=0; i<length;  i++){
		original[i] = temp[i];
	}
}

void display ( int arr[], int length){
	for (int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}