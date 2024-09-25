#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char s[10][4]={"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

bool strCmp(char* str1, char* str2){
	for(int i=0; i<3; i++){
		if(str1[i] != str2[i])
			return false;
	}
	return true;
}

int main(){
	freopen("GNS_test_input.txt", "r", stdin);
	int TEST_CASE = 0;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		char sharp;
		int index;
		cin >> sharp >> index;
		
		int N;
		cin >> N;

		int numbers[10]={};

		for(int i=0; i<N; i++){
			char str[4]="NNN";
			cin >> str;
			for(int j=0; j<10; j++){
				if(strCmp(str,s[j])){
					numbers[j]++;
					break;
				}
			}
		}

		cout<< "#" << case_index+1 << endl;
	
		for(int i=0; i<10; i++){
			for(int j=0; j<numbers[i]; j++){
				cout << s[i] << " ";
			}
		}

		cout<<endl;
	}

	return 0;
}