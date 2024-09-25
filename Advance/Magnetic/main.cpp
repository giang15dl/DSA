#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define TEST_CASE	10
#define LENGTH		100

int object_count(int table[][LENGTH],const int& length);
void apply_magnetic_field(int table[][LENGTH], const int& length);
bool isSouth(int table[][LENGTH],const int& row,const int& col);
bool isNorth(int table[][LENGTH],const int& row,const int& col);
void moveUp(int table[][LENGTH],const int& row,const int& col);
void moveDown(int table[][LENGTH],const int& row,const int& col);
void print(int table[][LENGTH]);
int standstill_count(int table[][LENGTH], const int& length);

void apply_magnetic_field(int table[][100], const int& length);
int main(){
	ios::sync_with_stdio(false);
	freopen("magnetic_test_input.txt", "r", stdin);
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int size_length;
		cin >> size_length;

		int table[LENGTH][LENGTH];

		for (int row = 0; row < size_length; row++){
			for(int col = 0; col < size_length; col++){
				cin >> table[row][col];
			}
		}

		//print(table);

		for(int i=0; i< size_length ; i++)
			apply_magnetic_field(table, size_length);

		//print(table);

		int ans = standstill_count(table, size_length);

		//cout << object_count(table, size_length);

		cout<< "#" << case_index+1 << " " << ans << endl;
	}

	return 0;
}

int object_count(int table[][LENGTH],const int& length){
	int count=0;

	for (int row = 0; row < length; row++){
		for(int col = 0; col < length; col++){
			if(table[row][col] != 0)
				count++;
		}
	}

	return count;
}

int standstill_count(int table[][LENGTH], const int& length){
	int count = 0;
	bool isStandstill = false;
	for (int col = 0; col < length; col++){
		for(int row = 0; row < length; row++){
			bool temp = isStandstill;
			if(table[row][col]!=0){
				isStandstill=true;
				if(temp == false)
					count++;
			}
			else
				isStandstill=false;
		}
	}
	return count;
}

void apply_magnetic_field(int table[][LENGTH], const int& length){
	for (int row = 0; row < length; row++){
		for(int col = 0; col < length; col++){
			if(isSouth(table, row, col))
				moveUp(table, row, col);
			if(isNorth(table, row, col))
				moveDown(table, row, col);
		}
	}
}

// check if object has North property and attracted to the S polar ( move Down )
bool isNorth(int table[][LENGTH],const int& row,const int& col){
	if(table[row][col]==1)
		return true;
	else
		return false;
}

// check if object has South property and attracted to the N polar ( move Up )
bool isSouth(int table[][LENGTH],const int& row,const int& col){
	if(table[row][col]==2)
		return true;
	else
		return false;
}

void moveUp(int table[][LENGTH],const int& row,const int& col){
	if(row == 0)
		table[row][col] = 0;
	if(row > 0 && table[row-1][col] == 0){
		int temp = table[row][col];
		table[row][col] = 0;
		table[row-1][col]=temp;
	}
}

void moveDown(int table[][LENGTH],const int& row,const int& col){
	if(row == LENGTH-1)
		table[row][col] = 0;
	if(row < LENGTH-1 && table[row+1][col] == 0){
		int temp = table[row][col];
		table[row][col] = 0;
		table[row+1][col]=temp;
	}
}

void print(int table[][LENGTH]){
	system("cls");
	for (int row = 0; row < LENGTH; row++){
		for(int col = 0; col < LENGTH; col++){
			if (isSouth(table,row,col))
				cout << "- " ;
			else if (isNorth(table,row,col))
				cout << "+ " ;
			else 
				cout << "  " ;
		}
		cout << "|"<< endl;
	}
	for(int i=0;i<LENGTH;i++)
		cout << "__";
	cout<<endl;
}

