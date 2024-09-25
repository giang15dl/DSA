#include <iostream>

using namespace std;

#define DEBUG 1

#define K_MAX 5000
#define N_MAX 100
#define M_MAX 100

//up, down, left, right
int type_1_row[4] = {-1, +1, 0 , 0};
int type_1_col[4] = { 0, 0 , -1, 1};

//top_left, top_right, down_left, down_right
int type_2_row[4] = {-1, -1, +1, +1};
int type_2_col[4] = {-1, +1, -1, +1};

const int TYPE1 = 1;
const int TYPE2 = 2;

struct Point{
	Point();
	Point(int _row, int _col, int _type);

	int row, col, type;
};

int Painted_count(int wall[N_MAX][M_MAX],const int& N,const int& M);
void shooting(int wall[N_MAX][M_MAX],const int& N,const int& M, Point bullets[], int K);
void dropDown(int wall[N_MAX][M_MAX],const int& N,const int& M);

int main(){
#if DEBUG
	freopen("input.txt", "r", stdin);
#endif // DEBUG
	int TEST_CASE = 0;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N, M, K;	//row, col, bullets count
		cin >> N >> M >> K;

		int wall[N_MAX][M_MAX] = {};

		Point bullets[K_MAX];

		for (int i = 0; i < K; i++){
			cin >> bullets[i].row >> bullets[i].col >> bullets[i].type;
		}

		shooting(wall, N, M, bullets, K);
		dropDown(wall, N, M);

		int count = Painted_count(wall, N, M);
		cout<< "#" << case_index+1 << " " << count << endl;
	}

#if DEBUG
	fclose(stdin);
#endif //DEBUG

	return 0;
}

int Painted_count(int wall[N_MAX][M_MAX],const int& N,const int& M){
	int count=0;
	for (int row = 0; row < N; row++){
		for (int col = 0; col < M; col++){
			if(wall[row][col] != 0)
				count++;
		}
	}
	return count;
}

void shooting(int wall[N_MAX][M_MAX],const int& N,const int& M, Point bullets[], int K){
	for (int i = 0; i < K; i++){
		Point bullet = bullets[i];
		
		//center where bullet hit
		wall[bullet.row][bullet.col] += 2;
		
		//4 side bullets
		for (int j = 0; j < 4; j++){
			int row = bullet.row; 
			int col = bullet.col;
			switch (bullet.type){
			case TYPE1:
				if(bullet.type == TYPE1){
					row += type_1_row[j];
					col += type_1_col[j];
				}
				break;
			case TYPE2:
				if(bullet.type == TYPE2){
					row += type_2_row[j];
					col += type_2_col[j];			
				}
				break;
			default:
				exit(EXIT_FAILURE);
				break;
			}

			if(row >= 0 && row < N && col >= 0 && col < M)
				wall[row][col]++;
		}
	}
}

void dropDown(int wall[N_MAX][M_MAX],const int& N,const int& M){
	for (int col = 0; col < M; col++){
		for (int row = 0; row < N; row++){
			if(wall[row][col] > 2){
				int remain = wall[row][col] - 2;
				wall[row][col] = 2;
				if(row != N-1)
					wall[row+1][col] += remain ;
			}
		}
	}
}

Point::Point(){
	row = 0;
	col = 0;
	type = 0;
}

Point::Point(int _row, int _col, int _type){
	row = _row;
	col = _col;
	type = _type;
}