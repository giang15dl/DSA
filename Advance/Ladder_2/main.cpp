#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define TEST_CASE 10
#define ROW 100
#define COL 100

int move_forward(int arr[ROW][COL],const int& start_row,const int& start_col);
void display (int arr[], int length);

int main(){
	ios::sync_with_stdio(false);
	freopen("ladder2_test_input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int case_num, ans=0;
		cin >> case_num;

		int ladder[ROW][COL];

		for(int row=0;row<ROW;row++){
			for(int col=0;col<COL;col++){
				cin >> ladder[row][col];
			}
		}

		int min = ROW*COL;
		int min_index;

		for (int i = 0; i < ROW; i++){
			if(ladder[0][i] == 1){
				int step = move_forward(ladder, 0, i);
				if(step<min){
					min=step;
					min_index=i;
				}
			}
		}
		cout<< "#" << case_num << " " << min_index << endl;
	}

	return 0;
}

int move_forward(int arr[ROW][COL],const int& start_row,const int& start_col){
	int step_count=0;
	int direction=0;
	int row = start_row;
	int col = start_col;
	int change_direction_count=0;
	int temp=0;
	while(row<ROW-1){
		temp=direction;
		if(col>0 && arr[row][col-1]==1 && direction != 2){
			col--;
			direction = 1;
		}

		if(col<COL-1 && arr[row][col+1]==1 && direction != 1){
			col++;
			direction = 2;
		}

		if(arr[row+1][col]==1){
			row++;
			direction = 0;
		}
		step_count++;
		if(direction!=temp)
			change_direction_count++;

	}
	return step_count;
}

void display (int arr[], int length){
	for (int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

