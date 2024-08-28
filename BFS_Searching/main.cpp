#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int N_MAX = 30;

const int MAX = 10000;
template<typename T>
class queue {
public:
    queue() : _front(-1), _rear(-1) {}

    void push(T a) {
        _rear++;
        data[_rear] = a;
    }
    
    void pop() {
        _front++;
    }
    
    T front() const {
        return data[_front];
    }

    bool empty() const {
        return _front == _rear;
    }

private:
    int _front, _rear;
    T data[MAX];
};

using namespace std;
int main(int argc, char** argv) {
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    for (int t = 0; t < T; t++) {
        cout << "#" << t + 1 << " ";
        int N; // number of Vertices
        int s; // Starting vertex
        cin >> N >> s;
        s--;

        int adj[N_MAX][N_MAX] = {};

        while (true) {
            int u, v;
            cin >> u >> v;
            if (u == -1 && v == -1)
                break;

            u--, v--;
            adj[u][v] = 1;
        }

        int vst[N_MAX] = {};
        queue<int> q;
        q.push(s);
        vst[s] = 1;
        cout << s + 1 << " ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < N; v++) {
                if (adj[u][v] && !vst[v]) {
                    vst[v] = 1;
                    cout << v + 1 << " ";
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    return 0;
}