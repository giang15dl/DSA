#include <iostream>

const int N = 100;
const int E = 200;
const int K = 1000;
const int T = 1000;
const int STEP = 110;
const int Q = 20000; // Queue data size
const int TC = 10; // Totoal number of test cases

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair() : first(), second() {}

    Pair(T1 t1, T2 t2) : first(t1), second(t2) {}
};

template<typename T, int MAX=100000>
class Queue{
public:
    Queue() : front(-1), rear(-1) {}

    void push(T a) {
        data[++rear] = a;
    }

    T pop() {
        return data[++front];
    }

    bool empty() {
        return front == rear;
    }

private:
    int front, rear;
    T data[MAX];
};

typedef Pair<int, float> Dept; // dept index, probability
typedef Pair<Dept, Dept> Ans; // Jang, Kang.
typedef Pair<int, int> State; // vertex, step

Ans solve(float (&)[N][N], int, int, int);

Dept findMax(float (&)[N], int);

using namespace std;
int main(int argc, char **argv){
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);

    for (int ti = 0; ti < TC; ti++) {
        int n, e, k, t;
        cin >> n >> e >> k >> t;

        float adj[N][N] = {};
        for (int i = 0; i < e; i++) {
            int st, en;
            float w;
            cin >> st >> en >> w;
            st--;
            en--;
            adj[st][en] = w;
        }

        Ans ans = solve(adj, n, k, t);
        Dept Jang = ans.first;
        Dept Kang = ans.second;

        cout << "#" << ti + 1 << " " << Jang.first + 1 << " " << Jang.second << " " << Kang.first + 1 << " " << Kang.second << endl;
    }

    return 0;
}

Ans solve(float (&adj)[N][N], int n, int k, int t) {
    float chanceByStep[STEP][N] = {};
    int lastVisitedStep[N] = {};
    chanceByStep[0][0] = 1;
    int maxStep = t/10;

    Queue<State, Q> q;
    q.push(State(0,0));

    while (!q.empty()) {
        State curr = q.pop();
        int u = curr.first;
        int step = curr.second;
        for (int v = 0; v < n; v++) {
            if (!adj[u][v])
                continue;

            chanceByStep[step+1][v] += chanceByStep[step][u] * adj[u][v];

            if (lastVisitedStep[v] < step + 1 && step < maxStep) {
                lastVisitedStep[v] = step + 1;
                q.push(State(v, step + 1));
            }
        }
    }

    Dept Jang = findMax(chanceByStep[maxStep], n);
    Dept Kang = findMax(chanceByStep[(t-k)/10], n);

    return Ans(Jang, Kang);
}

Dept findMax(float (&arr)[N], int n) {
    float max = 0;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    return Dept(maxIndex, max);
}
