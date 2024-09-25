//Reflecting Mirrors

#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 4
#define MAX_N 100

// direction : right, down, left, up
const int dy[4] = {0,  1,  0, -1};
const int dx[4] = {1,  0, -1,  0};

int Mirror_1(int direction);
int Mirror_2(int direction);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "mirrors_input.txt", "r", stdin);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N = 0;
		cin >> N;
		int grid[MAX_N][MAX_N] = {};

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> grid[i][j];
			}
		}

		int bounce_count = 0;

		// Start from upper left connor
		int row=0;
		int col=0;

		// Start from right direction
		int direction = 0; //right, down, left, up
		while(row>=0 && row<N && col>=0 && col<N){
			if(grid[row][col]==1){
				direction = Mirror_1(direction);
				bounce_count++;
			}
			else if(grid[row][col]==2){
				direction = Mirror_2(direction);
				bounce_count++;
			}
			row += dy[direction];
			col += dx[direction];
		}

		cout<< "#" << case_index+1 << " " << bounce_count << endl;
	}

	fclose(input);

	return 0;
}

int Mirror_1(int direction){
	switch (direction){
	case 0:
		return 3;
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 0;
	default:
		break;
	}
}

int Mirror_2(int direction){
	switch (direction){
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	default:
		break;
	}
}