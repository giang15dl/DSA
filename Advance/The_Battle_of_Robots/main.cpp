#include <iostream>
#include <cstdio> 

using namespace std;

#define DEFAULT_TEST_CASE 50
#define SIZE 100

const int RED =		2; // robot that moves to the left
const int BLUE =	1; // robot that moves to the right
const int BLANK =	0; // no robot at all

int Robot_Count(const int (&matrix)[SIZE][SIZE]);
void Fighting(int (&matrix)[SIZE][SIZE]);

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "Rb2__input.txt", "r", stdin);
	if(error)
		exit(EXIT_FAILURE);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int case_num;
		cin >> case_num;

		int matrix[SIZE][SIZE];

		for (int row = 0; row < SIZE; row++){
			for (int col = 0; col < SIZE; col++){
				cin >> matrix[row][col];
			}
		}

		Fighting(matrix);

		int count =  Robot_Count(matrix);

		cout<< "#" << case_index+1 << " " << count << endl;
	}

	fclose(input);

	return 0;
}

int Robot_Count(const int (&matrix)[SIZE][SIZE]){
	int count = 0;
	for(int i=0; i<SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if(matrix[i][j] != BLANK)
				count++;
		}
	}
	return count;
}

void Fighting(int (&matrix)[SIZE][SIZE]){
	for (int row = 0; row < SIZE; row++){
		for (int relay = 0; relay < SIZE-1; relay++){
			for (int col = 0; col < SIZE-1; col++){
				if(matrix[row][col] == BLUE){
					if(matrix[row][col+1] == BLANK){
						matrix[row][col] = BLANK;
						matrix[row][col+1] = BLUE; 
					}
					else if(matrix[row][col+1] == RED){
						matrix[row][col] = BLANK;
						matrix[row][col+1] = BLANK; 
					}
				}
			}
		}
	}
}