#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define TEST_CASE		10
#define ORIGINAL_LENGTH	4000
#define MAX_LENGTH		8000
#define MAX_COMMANDS	500
#define FINAL_LENGTH	10

using namespace std;

void insert		(int* original, int& length, const int& x, const int& y,const int* s);
void del		(int* original, int& length, const int& x, const int& y);
void display	(int* arr, int length);

int main(){
	ios::sync_with_stdio(false);
	freopen("pwd3_test_input.txt", "r", stdin);
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
			char c=0; 
			int x=0,y=0;
			int s[MAX_COMMANDS] = {0};
			cin >> c;

			if(c == 'I'){
				cin >> x;
				cin >> y;
				for (int i = 0; i < y; i++){
					cin >> s[i];
				}
				insert(original_cryptograms, cryptogram_length, x, y, s);
			}

			if(c == 'D'){
				cin >> x;
				cin >> y;
				del(original_cryptograms, cryptogram_length, x, y);
			}
			if(c == 'A'){
				cin >> y;
				for (int i = 0; i < y; i++){
					cin >> s[i];
				}
				insert(original_cryptograms, cryptogram_length, cryptogram_length, y, s);
			}

		}

		cout << "#" << case_index+1 << " ";
		display(original_cryptograms, FINAL_LENGTH);
	}

	return 0;
}

void insert(int* original, int& length, const int& x, const int& y,const int* s){
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

void del(int* original, int& length, const int& x, const int& y){
	length -= y;
	for(int i=x; i<length;  i++){
		original[i] = original[i+y];
	}
}


void display ( int arr[], int length){
	for (int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}