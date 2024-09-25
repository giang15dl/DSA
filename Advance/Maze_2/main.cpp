#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define TEST_CASE	10
#define SIZE		100

const char ROAD		= '0';
const char WALL		= '1';
const char VISITED	= '#';
const char START	= '2';
const char END		= '3';

template <class T> class Stack {
public:
	Stack();
	bool push(T k);
	T pop();
	T topElement();
	bool isFull();
	bool isEmpty();
private:
	int top;
	T st[SIZE];
};

struct Point{
	Point();
	Point(int _row, int _col);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int row,col;
};

bool solveMaze(Point start_point, Point end_point, char matrix[SIZE][SIZE]);

int main(){
	freopen("maze2_test_input.txt", "r", stdin);
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int case_num;
		cin >> case_num;
		Point start_point;
		Point end_point;
		char matrix[SIZE][SIZE];
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<SIZE; j++){
				cin >> matrix[i][j];
				if(matrix[i][j] == START)
					start_point=Point(i,j);
				if(matrix[i][j] == END)
					end_point=Point(i,j);
			}
		}

		bool flag = solveMaze(start_point, end_point, matrix);

		cout<< "#" << case_index+1 << " " << flag << endl;
	}

	return 0;
}

bool solveMaze(Point start_point, Point end_point, char matrix[SIZE][SIZE]){
	//up, right, down, left
	const int dx[] = {0 ,1 ,0 ,-1};
	const int dy[] = {-1,0 ,1 ,0};
	Stack<Point> stack;
	stack.push(start_point);
		
	while(!stack.isEmpty()){
		Point current_point = stack.pop();

		if(current_point == end_point)
				return true;
		
		int col = current_point.col;
		int row = current_point.row;
		
		matrix[row][col] = VISITED;

		for(int direction=0; direction<4; direction++){
			int new_col = col + dx[direction];
			int new_row = row + dy[direction];

			if(matrix[new_row][new_col] != WALL && matrix[new_row][new_col] != VISITED){
				stack.push(Point(new_row,new_col));
			}
		}
	}

	return false;
}

Point::Point(){
	row=0;
	col=0;
}

Point::Point(int _row, int _col){
	row = _row;
	col = _col;
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

template <class T> Stack<T>::Stack() {
	top = -1; 
}

template <class T> bool Stack<T>::push(T k){

	if (isFull()) {
		return 1;
	}

	top = top + 1;

	st[top] = k;

	return 0;
}

template <class T> bool Stack<T>::isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T> bool Stack<T>::isFull(){
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T> T Stack<T>::pop(){
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T> T Stack<T>::topElement(){
	T top_element = st[top];
	return top_element;
}