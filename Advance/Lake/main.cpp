//Lake

#include <iostream>

using namespace std;

#define DEFAULT_TEST_CASE 10
#define MAX_N 100

// direction : right, down, left, up
const int dy[4] = {0,  1,  0, -1};
const int dx[4] = {1,  0, -1,  0};

int findLand(const bool (&matrix)[MAX_N][MAX_N], const int &N, const int &_row, const int &_col);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "test.txt", "r", stdin);
	if(error)
		exit(EXIT_FAILURE);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N = 0;
		cin >> N;
		bool matrix[MAX_N][MAX_N] = {};

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> matrix[i][j];
			}
		}

		int total = 0;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if(matrix[i][j] == 1)
					total += findLand(matrix, N, i, j);
			}
		}

		cout<< "#" << case_index+1 << " " << total << endl;
	}

	fclose(input);

	return 0;
}

int findLand(const bool (&matrix)[MAX_N][MAX_N], const int &N, const int &_row, const int &_col){
	int min = MAX_N;
	for (int d = 0; d < 4; d++){
		int row = _row;
		int col = _col;
		int count = 0;
		while(row>=0 && row<N && col>=0 && col<N && matrix[row][col]==1){
			row += dy[d];
			col += dx[d];
			count++;
		}
		if(count < min)
			min = count;
	}
	return min;
}