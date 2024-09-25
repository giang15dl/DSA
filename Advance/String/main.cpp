#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define TEST_CASE	10
#define MAX_WORD	1000	

using namespace std;

int length(char str[]);
bool compare(char str1[], char str2[]);

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int case_num;
		cin>>case_num;
		char reference[10];
		char temp[10];

		char string[MAX_WORD];
		cin >> reference;

		cin.ignore(MAX_WORD, '\n');
		cin.getline(string, MAX_WORD);

		temp[length(reference)]='\0';

		int count = 0;

		for(int i=0 ; i<length(string) ; i++){
			for(int j=0 ; j<length(reference) ; ++j)
				temp[j] = string[j+i];

			if(compare(temp, reference))
				count++;
		}

		cout << "#" << index+1 << " " << count << endl;
	}

	return 0;
}

int length(char str[]){
	int i=0, count = 0;
	while(str[i]!='\0'){
		count++;
		i++;
	}

	return count;
}

bool compare(char str1[], char str2[]){
	bool flag=true;
	for(int i=0 ; i<length(str1) ; i++){
		if(str1[i]!=str2[i])
			flag=false;
	}

	return flag;
}
