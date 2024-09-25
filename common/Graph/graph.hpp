#pragma once
#include "queue.hpp"
#include "stack.hpp"
#include <iostream>

#define INT_MAX 2147483647

template <typename T = int, int MAX = 10000>
class Graph {
private:
    int size;
    T adj[MAX][MAX]; // adjacent matrix

    bool DFS(int vertex, int target, int (&vst)[MAX]);
    int minKey(int (&key)[MAX], bool (&mstSet)[MAX]);
    bool isSelfLoop(int vertex);

public:
    Graph(int n);
    T &operator()(int i, int j);
    T operator()(int i, int j) const;

    void add_edge(int u, int v);
    bool DFS(int start, int target);
    bool DFS_Stack(int start, int target);
    bool BFS(int start, int target);
    int primMST();
    bool hasCycle();
};

template <typename T, int MAX>
Graph<T, MAX>::Graph(int n) {
    size = n;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            adj[i][j] = 0;
}

template <typename T, int MAX>
T &Graph<T, MAX>::operator()(int i, int j) {
    return adj[i][j];
}

template <typename T, int MAX>
T Graph<T, MAX>::operator()(int i, int j) const {
    return adj[i][j];
}

template <typename T, int MAX>
void Graph<T, MAX>::add_edge(int u, int v) {
    adj[u][v] = 1; // Set edge from u to v
    // adj[v][u] = 1; // Set edge from v to u (if undirected graph)
}

template <typename T, int MAX>
int Graph<T, MAX>::minKey(int (&key)[MAX], bool (&mstSet)[MAX]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < size; i++)
        if (!mstSet[i] && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

template <typename T, int MAX>
bool Graph<T, MAX>::isSelfLoop(int vertex) {
    for (int i = 0; i < size; i++)
        if (adj[vertex][i])
            return DFS(i, vertex);

    return false;
}

template <typename T, int MAX>
bool Graph<T, MAX>::DFS(int start, int target) {
    int visited[MAX] = {};
    return DFS(start, target, visited);
}

template <typename T, int MAX>
bool Graph<T, MAX>::DFS(int vertex, int target, int (&visited)[MAX]) {
    if (vertex == target)
        return true;

    visited[vertex] = 1;

    for (int i = 0; i < size; i++)
        if (adj[vertex][i] && !visited[i])
            if (DFS(i, target, visited))
                return true;

    return false;
}

template <typename T, int MAX>
bool Graph<T, MAX>::DFS_Stack(int start, int target) {
    int visited[MAX] = {};
    Stack<int, MAX> s;

    visited[start] = 1;

    s.push(start);
    while (!s.empty()) {
        int t = s.pop();
        if (t == target)
            return true;

        for (int i = 0; i < size; i++) {
            if (adj[t][i] && !visited[i]) {
                visited[i] = 1;
                s.push(i);
            }
        }
    }

    return false;
}

template <typename T, int MAX>
bool Graph<T, MAX>::BFS(int start, int target) {
    int visited[MAX] = {};
    Queue<int, MAX> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int t = q.pop();
        if (t == target)
            return true;

        for (int i = 0; i < size; i++) {
            if (adj[t][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return false;
}

template <typename T, int MAX>
int Graph<T, MAX>::primMST() {
    int parent[MAX] = {};

    int key[MAX] = {};

    bool mstSet[MAX] = {};

    for (int i = 0; i < size; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < size - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < size; v++) {
            if (u != v && mstSet[v] == false && adj[u][v] < key[v])
                parent[v] = u, key[v] = adj[u][v];
        }
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += key[i];

    return sum;
}

template <typename T, int MAX>
bool Graph<T, MAX>::hasCycle() {
    for (int i = 0; i < size; i++) {
        if (isSelfLoop(i))
            return true;
    }
    return false;
}
