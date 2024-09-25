#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int TC, N;
int map1[101], map2[101], visited[101];
bool canPass;
int queue[101];
int front, rear;
int num;

void initQueue() {
    front = rear = -1;
}

int isEmpty() {
    if (front == rear)
        return 1;
    return 0;
}

void enQueue(int val) {
    rear++;
    printf("rear: %d", rear);
    queue[rear] = val;
}

int deQueue() {
    if (!isEmpty()) {
        front++;
        printf("front: %d", front);
        return queue[front];
    }
    return -1;
}

void bfs() {
    if (map1[0] != 0)
        enQueue(map1[0]);
    if (map2[0] != 0)
        enQueue(map2[0]);
    while (!isEmpty()) {
        num = deQueue();
        visited[num] = 1;
        if (visited[map1[num]] == 0 && map1[num] != 0)
            enQueue(map1[num]);
        if (visited[map2[num]] == 0 && map2[num] != 0)
            enQueue(map2[num]);
        if (map1[num] == 99 || map2[num] == 99) {
            canPass = true;
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++) {
        cin >> TC >> N;
        int index;
        for (int i = 0; i < 100; i++) {
            map1[i] = map2[i] = 0;
            visited[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            cin >> index;
            // cout<<index<<" ";
            if (map1[index] == 0) {
                cin >> map1[index];
                // cout<<map1[index]<<" ";
            } else {
                cin >> map2[index];
                // cout<<map2[index]<<" ";
            }
        }

        canPass = false;
        initQueue();
        bfs();
        if (canPass)
            cout << "#" << tc << " " << 1 << endl;
        else {
            cout << "#" << tc << " " << 0 << endl;
        }
    }
    return 0;
}