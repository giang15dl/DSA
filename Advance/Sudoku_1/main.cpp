#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define GRID_SIZE	9

char matrix[GRID_SIZE*GRID_SIZE]={};
char numbers[9]={'1','2','3','4','5','6','7','8','9'};
int check[9] = {0,3,6,27,30,33,54,57,60};

bool check_by_row(int row);
bool check_by_col(int col);
bool check_by_grid(int top_left);
void print(int top_left);

int main(){
	freopen("input.txt", "r", stdin);
	int TEST_CASE=0;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		for(int i=0; i<GRID_SIZE; i++){
			for(int j=0; j<GRID_SIZE; j++){
				cin >> matrix[9*i + j];
			}
		}
		bool flag=true;

		for(int i=0; i<GRID_SIZE; i++){
			if(check_by_row(i)==false){
				flag=false;
				break;
			}
			if(check_by_col(i)==false){
				flag=false;
				break;
			}
			if(check_by_grid(check[i])==false){
				flag=false;
				break;
			}
		}

		cout<< "#" << case_index+1 << " " << flag << endl;
	}

	return 0;
}

bool check_by_row(int row){
	int frequency[GRID_SIZE]={};
	for(int col=0; col<GRID_SIZE; col++){
		for(int j=0; j<GRID_SIZE; j++){
			if(matrix[9*row+col]==numbers[j]){
				frequency[j]++;
				if(frequency[j]>1)
					return false;
			}
		}
	}
	return true;
}

bool check_by_col(int col){
	int frequency[GRID_SIZE]={};
	for(int row=0; row<GRID_SIZE; row++){
		for(int j=0; j<GRID_SIZE; j++){
			if(matrix[9*row+col]==numbers[j]){
				frequency[j]++;
				if(frequency[j]>1)
					return false;
			}
		}
	}
	return true;
}

bool check_by_grid(int top_left){
	int frequency[GRID_SIZE]={};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<GRID_SIZE; k++){
				if(matrix[top_left+ 9*i +j]==numbers[k]){
					frequency[k]++;
					if(frequency[k]>1){
						return false;
					}
				}
			}
		}
	}
	return true;
}

void print(int top_left){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << matrix[top_left+j+9*i];
		}
		cout << endl;
	}
}
