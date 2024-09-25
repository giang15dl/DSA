#define _CRT_SECURE_NO_WARNINGS

// Array game: sequence search
#include <stdio.h>

int N; // số phần tử của dãy
int arr[20001];
int maxScore; // điểm số lớn nhất hiện tại

int findMid(int left, int right, long long halfSum) {
    int mid;
    long long tmpSum = 0; // tổng từ left đến vị trí mid hiện tại
    for (mid = left;; mid++) {
        tmpSum += arr[mid];
        if (tmpSum == halfSum)
            return mid;
        else if (tmpSum > halfSum) // không chia được
            return -1;
    }
}

void backtrack(int left, int right, long long sum, int score) {
    if (left == right || (sum % 2 == 1)) { // nếu có 1 phần tử hoặc tổng lẻ
        if (score > maxScore)
            maxScore = score;
        return;
    }

    // tìm vị trí mid sao cho tổng từ left đến mid bằng sum / 2
    int mid = findMid(left, right, sum / 2);

    if (mid == -1) { // nếu không thể chia được
        if (score > maxScore)
            maxScore = score;
        return;
    }
    // lặp lại thao tác với 2 nửa, với số điểm + 1
    backtrack(left, mid, sum / 2, score + 1);
    backtrack(mid + 1, right, sum / 2, score + 1);
}

int main() {
    freopen("arraygame_input.txt", "r", stdin);
    int tc, T;
    long long sum;
    scanf("%d", &T);
    for (tc = 1; tc <= T; tc++) {

        // nhập input, đồng thời tính tổng dãy
        scanf("%d", &N);
        sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if (sum == 0) // trường hợp đặc biệt: dãy toàn số 0
            maxScore = N - 1;
        else {
            maxScore = 0;
            // gọi backtrack, ban đầu xét dãy từ 0 đến N - 1 và điểm = 0
            backtrack(0, N - 1, sum, 0);
        }
        printf("%d\n", maxScore);
    }

    return 0;
}

////Array game: binary search
// #include <stdio.h>
//
// int N;
// int arr[20001];
// long long pref[20001]; //prefix sum: pref[i] = tổng từ 0 đến i
//
// int findMid(int left, int right)
//{
//	long long sum = pref[right] - pref[left - 1];
//	long long key = (sum >> 1) + pref[left - 1];
//	int mid;
//	while (left <= right) {
//		mid = (left + right) >> 1;
//		if (pref[mid] == key)
//			return mid;
//		if (key < pref[mid])
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return -1;
// }
//
// int maxScore;
// void go(int left, int right, int score)
//{
//	long long sum = pref[right] - pref[left - 1];
//	if (left == right || (sum & 1)) {
//		if (score > maxScore)
//			maxScore = score;
//		return;
//	}
//
//	int mid = findMid(left, right);
//	if (mid == -1) {
//		if (score > maxScore)
//			maxScore = score;
//		return;
//	}
//	go(left, mid, score + 1);
//	go(mid + 1, right, score + 1);
// }
//
// int main()
//{
//	freopen("arraygame_input.txt", "r", stdin);
//	int tc, T;
//	scanf("%d", &T);
//	for (tc = 1; tc <= T; tc++) {
//		scanf("%d", &N);
//		pref[0] = arr[0] = 0;
//		for (int i = 1; i <= N; i++) {
//			scanf("%d", &arr[i]);
//			pref[i] = pref[i - 1] + arr[i];
//		}
//		if (pref[N] == 0) {
//			maxScore = N - 1;
//		}  else {
//			maxScore = 0;
//			go(1, N, 0);
//		}
//		printf("%d\n", maxScore);
//	}
//
//	return 0;
// }