#include<iostream>
using namespace std;
int N, M;
int arr[51][51];
int visited[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int xStart, yStart; 
int xEnd, yEnd; 
bool check = false;
int QX[1000001];
int QY[1000001]; 
int front, rear;
void clear_visit(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            visited[i][j] = 0;
        }
    }
}

bool isSafe(int x, int y){
    if(0<x && x<=N && 0<y && y<=M) return true;
    else return false;
}

void bfs(int row, int col, int step){
    front = rear = 0;
    QX[rear] = row;
    QY[rear++] = col;
    visited[row][col] = 1;
    while(front != rear){
        int x = QX[front]; 
        int y = QY[front++];
        for (int st = 1; st <= step; st++){ 
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i]*st;
                int ny = y + dy[i];
                if(isSafe(nx,ny) && visited[nx][ny] == 0 && arr[nx][ny] != 0){ 
                    QX[rear] = nx; 
                    QY[rear++] = ny;
                    visited[nx][ny] = 1;
                    if(visited[xEnd][yEnd] == 1){ 
                        check = true;
                        break; 
                    }
                }
            }
            if(check) break; 
        }
        if(check) break;
    }
}

int main(){
    int tc;
    int T;
    int Answer;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for(tc = 1; tc <= T; ++tc){
        cin >> N >> M;
        check = false;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <=M; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 2){
                    xStart = i;
                    yStart = j;
                }
                if(arr[i][j] == 3){
                    xEnd = i;
                    yEnd = j;
                }
            }
        }
        int step = 1;
        while(!check){
            clear_visit();
            bfs(xStart, yStart, step); 
            if(check){
                break;
            }
            step++;
        }
        cout << "Case #" << tc << endl << step << endl;
    }
    return 0;
}