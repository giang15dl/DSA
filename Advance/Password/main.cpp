#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define TEST_CASE 10

int find_max(int arr[], int n);
void shorten_password(char arr[], int& n, int& index);

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int length;
		cin >> length;
		char password[100]={'0'};
		char c;
		cin.get(c);
		for(int i=0;i<length;i++){
			cin.get(password[i]);
		}

		for(int i=0;i<length;i++){
			if(password[i]==password[i+1]){
				shorten_password(password,length,i);
			}
		}


		cout<< "#" << index+1 << " " << password << endl;
	}

	return 0;
}

void shorten_password(char arr[], int& n, int& index){
	int i=0;
	for (i = index; i < n-2; i++){
		arr[i]=arr[i+2];
	}
	arr[n-2]='\0';
	n -= 2;
	index -= 2;
}
