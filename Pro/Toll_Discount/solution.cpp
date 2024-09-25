#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
    static const int MAX_N = 300;
    static const int MAX_M = 10 + 1;

private:
    int N;
    struct Road {
        int u, v;
        int toll;
        bool del;

        Road() : u(0), v(0), toll(0), del(false) {}
        Road(int u, int v, int toll) : u(u), v(v), toll(toll), del(false) {}
    };

    struct State {
        int city;
        int cost;
        int discount;
        State() {}
        State(int city, int cost, int discount) : city(city), cost(cost), discount(discount) {}
    };

    struct less {
        bool operator()(const State &a, const State &b) const {
            return a.cost > b.cost;
        }
    };

    unordered_map<int, Road> roads;
    vector<Road *> adj[MAX_N];

public:
    Solution() {}
    Solution(int N, int K, int mId[], int sCity[], int eCity[], int mToll[]) : N(N) {
        for (int i = 0; i < K; i++) {
            roads[mId[i]] = Road(sCity[i], eCity[i], mToll[i]);
            adj[sCity[i]].push_back(&roads[mId[i]]);
        }
    }

    void add(int mId, int sCity, int eCity, int mToll) {
        roads[mId] = Road(sCity, eCity, mToll);
        adj[sCity].push_back(&roads[mId]);
    }

    void remove(int mId) {
        auto find = roads.find(mId);
        if (find != roads.end())
            find->second.del = true;
    }

    int cost(int M, int sCity, int eCity) {
        priority_queue<State, vector<State>, less> pq;
        int minCost[MAX_N][MAX_M] = {};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < MAX_M; j++) {
                minCost[i][j] = INT_MAX;
            }
        }

        minCost[sCity][M] = 0;

        pq.push(State(sCity, 0, M));

        while (!pq.empty()) {
            auto state = pq.top();
            pq.pop();
            int city = state.city;
            int cost = state.cost;
            int discount = state.discount;

            if (city == eCity)
                return cost;

            for (auto *road : adj[city]) {
                if (road->del)
                    continue;

                int nextCost = cost + road->toll; // Don't use discount

                if (nextCost < minCost[road->v][discount]) {
                    minCost[road->v][discount] = nextCost;
                    pq.push(State(road->v, nextCost, discount));
                }

                if (discount > 0) {
                    int discountedCost = cost + road->toll / 2;
                    if (discountedCost < minCost[road->v][discount - 1]) {
                        minCost[road->v][discount - 1] = discountedCost;
                        pq.push(State(road->v, discountedCost, discount - 1));
                    }
                }
            }
        }

        return -1;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////

void init(int N, int K, int mId[], int sCity[], int eCity[], int mToll[]) {
    solution = Solution(N, K, mId, sCity, eCity, mToll);
}

void add(int mId, int sCity, int eCity, int mToll) {
    solution.add(mId, sCity, eCity, mToll);
}

void remove(int mId) {
    solution.remove(mId);
}

int cost(int M, int sCity, int eCity) {
    return solution.cost(M, sCity, eCity);
}
