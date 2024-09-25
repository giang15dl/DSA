#include <iostream>
#include <cstdio> 

using namespace std;

#define DEFAULT_TEST_CASE 10
#define MAX_N 100

const char VINAPHONE	= 'A';
const char MOBIPHONE	= 'B';
const char VIETTEL		= 'C';
const char HOUSE		= 'H';
const char BLANK		= 'X';

// direction : right, left, up, down
const int dy[] = {+1, -1, +0, +0};
const int dx[] = {+0, +0, -1, +1};

template<int max_size>
int signal_check(const char (&matrix)[max_size][max_size], const int& N);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "VMV_input.txt", "r", stdin);
	if(error)
		exit(EXIT_FAILURE);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N = 0;
		cin >> N;
		char matrix[MAX_N][MAX_N] = {};
		int total_houses = 0;
		for (int row = 0; row < N; row++){
			for (int col = 0; col < N; col++){
				cin >> matrix[row][col];
				if(matrix[row][col] == HOUSE)
					total_houses++;
			}
		}
		int connected_house = signal_check<MAX_N>(matrix, N);
		int non_connected_house = total_houses - connected_house;
		cout<< "#" << case_index+1 << " " << non_connected_house << endl;
	}
	fclose(input);
	return 0;
}

template<int max_size>
int signal_check(const char (&matrix)[max_size][max_size],const int& N){
	int checked[max_size][max_size] = {};
	int connected_house_count = 0;
	for (int row = 0; row < N; row++){
		for (int col = 0; col < N; col++){
			int furthest = 0;
			if(matrix[row][col] == BLANK || matrix[row][col] == HOUSE)
				continue;
			else if(matrix[row][col] == VINAPHONE)
				furthest = 1;
			else if (matrix[row][col] == MOBIPHONE)
				furthest = 2;
			else if (matrix[row][col] == VIETTEL)
				furthest = 3;
			for(int distance = 1; distance <= furthest; distance++){
				for (int direction = 0; direction < 4; direction++){
					int new_y = row + dy[direction]*distance;
					int new_x = col + dx[direction]*distance;
					if( new_y >= 0 && new_y < N && new_x >= 0 && new_x < N && matrix[new_y][new_x] == HOUSE && checked[new_y][new_x] == 0){
						checked[new_y][new_x] = 1;
						connected_house_count++;
					}
				}
			}
		}
	}
	return connected_house_count;
}