#include <iostream>
using namespace std;

#define TEST_CASE 1
#define WIDTH 11
#define MAX_HEIGHT 100

int sum_boxes(int arr[], int n);

int partition(int arr[], int start, int end);
void quick_sort(int arr[], int start, int end);
int height_difference(int arr[], int n);
int sum_boxes(int arr[], int n);
float flattened(int arr[], int n);

int main() {
    ios::sync_with_stdio(false);
    freopen("input", "r", stdin);
    for (int index = 0; index < TEST_CASE; index++) {
        int dump_count = 0, ans = 0;
        cin >> dump_count;
        int boxes[WIDTH];
        for (int i = 0; i < WIDTH; i++) {
            cin >> boxes[i];
        }

        cout << flattened(boxes, MAX_HEIGHT);

        cout << "#" << index + 1 << " " << ans << endl;
    }
    return 0;
}

int sum_boxes(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

float flattened(int arr[], int n) {
    float average = sum_boxes(arr, n) / n;
    return average;
}

int height_difference(int arr[], int n) {
    quick_sort(arr, 0, n - 1);
    return arr[n - 1] - arr[0];
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quick_sort(int arr[], int start, int end) {
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quick_sort(arr, start, p - 1);

    // Sorting the right part
    quick_sort(arr, p + 1, end);
}
