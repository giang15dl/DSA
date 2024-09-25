#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 10;

void detectCycle(int currNode, int nodeSum, unordered_map<int, vector<int>> &adjList, vector<int> visited, vector<int> pathVisited, int &minNodeSum, set<int> &temp, set<int> &path, bool &isCycle);

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int V, E; // Vertices, Edges
        cin >> V >> E;

        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u - 1].push_back(v - 1);
        }

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        int minNodeSum = INT_MAX;
        set<int> path;
        bool isCycle = 0;
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                set<int> temp = {};
                detectCycle(v, 0, adjList, visited, pathVisited, minNodeSum, temp, path, isCycle);
            }
        }
        if (isCycle)
            for (auto itr : path)
                cout << itr + 1 << " ";
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}

void detectCycle(int currNode, int nodeSum, unordered_map<int, vector<int>> &adjList, vector<int> visited, vector<int> pathVisited, int &minNodeSum, set<int> &temp, set<int> &path, bool &isCycle) {
    temp.insert(currNode);
    visited[currNode] = 1;
    pathVisited[currNode] = 1;

    for (auto neighbour : adjList[currNode]) {
        if (!visited[neighbour]) {
            detectCycle(neighbour, nodeSum + currNode, adjList, visited, pathVisited, minNodeSum, temp, path, isCycle);
            if (isCycle)
                return;
        } else if (pathVisited[neighbour]) {
            if (nodeSum < minNodeSum) {
                minNodeSum = nodeSum;
                path = temp;
                isCycle = 1;
            }
        }
    }
}

void findCircleUnit(unordered_map<int, vector<int>> &G, int start, int v, bool *visited, vector<int> &path) {
    if (visited[v]) {
        if (v == start) {
            for (auto c : path)
                cout << c << " ";
            cout << endl;
            return;
        } else
            return;
    }
    visited[v] = true;
    path.push_back(v);
    for (auto i : G[v])
        findCircleUnit(G, start, i, visited, path);
    visited[v] = false;
    path.pop_back();
}