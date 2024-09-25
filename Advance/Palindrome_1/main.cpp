#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define TEST_CASE 10
#define ROW 8
#define COL 8
using namespace std;

bool isPalindrome (char*, const int&);
bool isPalindrome (char*);
int stringLength (char*);
void printString(char* string,const int& length);

int main(){
	ios::sync_with_stdio(false);
	freopen("palindrome1_test_input.txt", "r", stdin);

	for(int test_case = 0 ; test_case <TEST_CASE ; test_case++){
		int palindrome_length = 0;
		cin >> palindrome_length;

		char horizontal[ROW][COL];
		for (int row = 0; row < ROW; row++){
			cin>>horizontal[row];
		}

		char vertical[COL][ROW];
		for (int col = 0 ; col < COL ; col++){
			for (int row = 0; row < ROW; row++){
				vertical[col][row] = horizontal[row][col];
			}
		}
		
		int loop = ROW - palindrome_length + 1 ;

		int word_count = 0;
		int palindrome_count = 0;
		int non_palindrome_count = 0;

		//check by row
		for (int row = 0 ; row < ROW ; row++){
			for (int i = 0; i < loop; i++){
				word_count++;
				//printString(horizontal[row]+i, palindrome_length);
				if(isPalindrome(horizontal[row]+i, palindrome_length)){
					palindrome_count++;
				}
				else{
					non_palindrome_count++;
				}
			}
		}

		//check by column
		for (int col = 0 ; col < COL ; col++){
			for (int i = 0; i < loop; i++){
				word_count++;
				//printString(horizontal[col]+i, palindrome_length);
				if(isPalindrome(vertical[col]+i, palindrome_length)){
					palindrome_count++;
				}
				else{
					non_palindrome_count++;
				}
			}
		}

		cout << "#" << test_case+1 << " " << palindrome_count << endl;
	}

	return 0;
}

bool isPalindrome (char* string, const int& length){
	for(int i=0 ; i <length/2 ; i++){
		if(string[i] != string[length-i-1]){
			return false;
		}
	}
	//printString(string, length);
	return true;
}

bool isPalindrome (char* string){
	int length = stringLength(string);
	for(int i=0 ; i <length/2 ; i++){
		if(string[i] != string[length-i-1]){
			return false;
		}
	}
	return true;
}

int stringLength(char* string){
	int i=0, count = 0;
	while(string[i]!='\0'){
		count++;
		i++;
	}

	return count;
}

void printString(char* string,const int& length){
	for(int i=0 ; i<length ; i++){
		cout << string[i];
	}
	cout << endl;
}