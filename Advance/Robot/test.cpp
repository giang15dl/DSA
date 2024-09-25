#include <iostream>

using namespace std;

#define DEBUG 1

#define MAX_N 5
#define MAX_K 10

int TEST_CASE = 10;

//Obtacle
const int WALL			= -1;

//Direction
const int UP			= 0;
const int LEFT			= 1;
const int DOWN			= 2;
const int RIGHT			= 3;

//Comands
const int MOVE			= 0;
const int TURN_LEFT		= 1;
const int TURN_180		= 1;
const int TURN_RIGHT	= 1;


struct Point{
	Point();
	Point(int row, int col);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int row,col;
};

int Execute(int house[MAX_N][MAX_N], const int& N, int commands[MAX_K],const int& k,const Point& start_point,const int& z);

int main(){
#if DEBUG
	freopen("test.txt", "r", stdin);
#endif // DEBUG

	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N=0;		//matrix size aka the house size
		int x, y ,z;	//robot's current position (x,y) and direction (z) 

		cin >> N >> x >> y >> z;

		Point start_point(x,y);

		int house[MAX_N][MAX_N] = {};

		for (int row = 0; row < N; row++){
			for (int col = 0; col < N; col++){
				cin >> house[row][col];
			}
		}

		int k=0;		//number of commands

		cin >> k;

		int commands[MAX_K] = {};

		for (int i = 0; i < k; i++){
			cin >> commands[i];
		}

		int clean_grid_count = Execute(house, N, commands, k, start_point, z);

		cout<< "#" << case_index+1 << " " << endl;
	}

	return 0;
}

int Execute(int house[MAX_N][MAX_N], const int& N, int commands[MAX_K],const int& k,const Point& start_point,const int& z){
	Point current_point = start_point;
	int current_direction = z;
	int count = 0;

	bool checked[MAX_N][MAX_N] = {};

	for(int i = 0; i < k; i++){
		int current_command = commands[i];
		int cleanness = house[current_point.row][current_point.col];
		bool moved = false;
		Point previous_point = current_point;
		if (current_command == MOVE){
			switch (current_direction) {
			case UP: 
				if ( current_point.row>0 && house[current_point.row-1][current_point.col] != WALL ){
					current_point.row--;
					moved = true;
				}
				break;
			case DOWN:
				if ( current_point.row<N-1 && house[current_point.row+1][current_point.col] != WALL ){
					current_point.row++;
					moved = true;
				}
				break;
			case LEFT:
				if ( current_point.col>0 && house[current_point.row][current_point.col-1] != WALL ){
					current_point.col--;
					moved = true;
				}
				break;
			case RIGHT:
				if ( current_point.col<N-1 && house[current_point.row][current_point.col+1] != WALL ){
					current_point.col++;
					moved = true;
				}
				break;	
			default:
				break;
			} //END OF SWITCH
		} //END OF MOVE COMMAND

		if(current_command == TURN_LEFT){
			(current_direction == 3) ? current_direction=0 : current_direction++;
		}

		if(current_command == TURN_RIGHT){
			(current_direction == 0) ? current_direction=3 : current_direction--;
		}
		if(current_command == TURN_180){
			(current_direction < 2) ? current_direction+=2 : current_direction-=2;
		}

		if(moved && cleanness > 0){
			house[previous_point.row][previous_point.col]--;
			cleanness--;
		}

		if(cleanness == 0 && checked[previous_point.row][previous_point.col] == 0){
			checked[previous_point.row][previous_point.col] == 1;
			count++;
		}
	}

	return count;
}

Point::Point(){
	row=0;
	col=0;
}

Point::Point(int row, int col){
	this->row = row;
	this->col = col;
}

bool Point::operator!=(const Point& rhs) const{
	if(row==rhs.row && col == rhs.col)
		return false;
	else
		return true;
}

bool Point::operator==(const Point& rhs) const {
	if(row==rhs.row && col == rhs.col)
		return true;
	else
		return false;
}