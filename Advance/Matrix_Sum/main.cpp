#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define TEST_CASE 10
#define ROW 100
#define COL 100
using namespace std;
int arrSum(int arr[100]);
void bubbleSort(int arr[], int n);
int main(){
	freopen("test_input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int case_num, ans=0;
		cin >> case_num;
		int matrix[ROW][COL];
		for(int i=0;i<COL;i++){
			for(int j=0;j<ROW;j++){
				cin >> matrix[i][j];
			}
		}
		int temp[ROW+COL+2];
		for(int i=0;i<100;i++){
			temp[i]=arrSum(matrix[i]);
		}
		for(int col=0;col<100;col++){
			int temp_sum = 0;
			for(int row=0;row<100;row++){
				temp_sum += matrix[row][col];
			}
			temp[col+100] = temp_sum;
		}
		int temp_sum = 0;
		for(int col=0;col<100;col++){
			temp_sum+=matrix[col][col];
		}
		temp[200] = temp_sum;
		
		temp_sum = 0;
		for(int col=0;col<100;col++){
			temp_sum+=matrix[col][100-col];
		}
		temp[201] = temp_sum;
		bubbleSort(temp,202);
		ans = temp[201];
		cout << "#" << index+1 << " " << ans << endl;
	}

	return 0;
}

int arrSum(int arr[100]){
	int sum=0;
	for(int i=0 ; i<100 ;i++){
		sum+=arr[i];
	}
	return sum;
}

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
