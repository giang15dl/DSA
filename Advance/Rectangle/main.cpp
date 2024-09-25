#include <iostream>
#include <cstdio> 

using namespace std;

#define DEFAULT_TEST_CASE	10
#define MATRIX_SIZE			100

// direction : right, down, left, up
const int next_row[4] = {0,  1,  0, -1};
const int next_col[4] = {1,  0, -1,  0};

template<int SIZE>
int square_count(const bool (&matrix)[SIZE][SIZE]);

template<int SIZE>
bool square_check(const bool (&matrix)[SIZE][SIZE], const int& tl_row, const int& tl_col);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "HCN_input.txt", "r", stdin);
	if(error)
		exit(EXIT_FAILURE);

	int TEST_CASE = DEFAULT_TEST_CASE;
	//cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int dont_care = 0;
		cin >> dont_care;

		bool matrix[MATRIX_SIZE][MATRIX_SIZE] = {};

		for (int row = 0; row < MATRIX_SIZE; row++){
			for (int col = 0; col < MATRIX_SIZE; col++){
				cin >> matrix[row][col];
			}
		}

		int squares = square_count<MATRIX_SIZE>(matrix);

		cout<< "#" << case_index+1 << " " << squares << endl;
	}
	fclose(input);
	return 0;
}

template<int SIZE>
int square_count(const bool (&matrix)[SIZE][SIZE]){
	int squares = 0;
	for (int row = 0; row < SIZE; row++){
		for (int col = 0; col < SIZE; col++){
			if(square_check(matrix, row, col))
				squares++;
		}
	}
	return squares;
}

//check square define by the top_left point, assumed that the top_left point is inside the matrix region
template<int SIZE>
bool square_check(const bool (&matrix)[SIZE][SIZE], const int& tl_row, const int& tl_col){
	int row = tl_row;
	int col = tl_col;

	int side[4] = {};

	// right, down, left, up
	for (int d = 0; d < 4; d++){
		while(row>=0 && row<SIZE && col>=0 && col<SIZE && matrix[row][col]==1){
			side[d]++;
			int new_row = row + next_row[d];
			int new_col = col + next_col[d];
			if(new_row>=0 && new_row<SIZE && new_col>=0 && new_col<SIZE && matrix[new_row][new_col]==1){
				row += next_row[d];
				col += next_col[d];
			}
			else
				break;
		}
	}

	for(int i=0; i<4; i++){
		if(side[i] < 3)
			return false;
	}

	if(side[0] == side[2] && side[1] == side[3]) return true;
	else return false;
}

