#include <stdio.h>
#define MAX_N 21
#define MAX_M 31
#define INF 1000000000

// Thông tin về các linh kiện
int N;
int itemPrice[MAX_N];
int needed[MAX_N]; // Số lượng cần mua của từng linh kiện

// Thông tin về các combo
int M;
int setPrice[MAX_M];           // Giá combo
int setSize[MAX_M];            // Số lượng linh kiện trong combo
int setItemList[MAX_M][MAX_N]; // Danh sách linh kiện của combo

// Số linh kiện cần mua và danh sách
int requireCnt;
int require[MAX_N];

int minCost; // Answer

// Hàm back track truyền vào 3 tham số:
// setId: combo,
// cost: tổng giá hiện tại
// boughtCnt: số linh kiện cần thiết đã mua
void backtrack(int setId, int cost, int boughtCnt) {
    if (cost >= minCost) // nếu tổng giá lớn hơn min hiện tại
        return;
    if (boughtCnt == requireCnt) { // nếu đã mua đủ
        minCost = cost;
        return;
    }
    if (setId == M) { // nếu đã kiểm tra hết các combo, mua lẻ số còn lại
        for (int i = 0; i < requireCnt; ++i) {
            if (needed[require[i]] > 0) {
                cost += itemPrice[require[i]];
                if (cost >= minCost)
                    return;
            }
        }
        minCost = cost;
        return;
    }

    backtrack(setId + 1, cost, boughtCnt); // không mua combo này
    int usefulCnt = 0;                     // số linh kiện cần và chưa được mua
    for (int k = 0; k < setSize[setId]; k++) {
        if (needed[setItemList[setId][k]] > 0)
            ++usefulCnt; // cần mua linh kiện này
        needed[setItemList[setId][k]]--;
    }
    if (usefulCnt > 0) // nếu không có linh kiện nào cần thiết, bỏ qua combo này
        backtrack(setId + 1, cost + setPrice[setId], boughtCnt + usefulCnt);
    // Reset trạng thái
    for (int k = 0; k < setSize[setId]; k++)
        needed[setItemList[setId][k]]++;
}

int main() {
    int T;

    freopen("nangcap_input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {

        scanf("%d", &N); // nhập thông tin về các linh kiện
        for (int i = 1; i <= N; i++) {
            needed[i] = 0;
            scanf("%d", &itemPrice[i]);
        }

        scanf("%d", &M); // nhập thông tin về các combo
        for (int i = 0; i < M; i++) {
            scanf("%d", &setPrice[i]);
            scanf("%d", &setSize[i]);
            for (int j = 0; j < setSize[i]; j++)
                scanf("%d", &setItemList[i][j]);
        }

        // nhập thông tin về các linh kiện cần mua
        scanf("%d", &requireCnt);
        for (int i = 0; i < requireCnt; i++) {
            scanf("%d", &require[i]);
            needed[require[i]] = 1; // needed của linh kiện = 1
        }

        minCost = INF; // reset giá tiền nhỏ nhất

        // gọi backtrack từ combo 0, ban đầu tổng giá và số linh kiện đã mua được đều bằng 0
        backtrack(0, 0, 0);
        printf("#%d %d\n", tc, minCost);
    }

    return 0;
}