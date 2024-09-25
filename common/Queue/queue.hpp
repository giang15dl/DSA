#pragma once
#include <iostream>

template <typename T = int, int MAX = 10000>
class Queue {
private:
    int front, rear, count;
    T data[MAX] = {};

public:
    Queue();
    ~Queue();

    void push(const T &item);
    T pop();
    T peek() const;
    bool full() const;
    bool empty() const;
    int size() const;
    bool has(const T &item) const;
    void clear();
};

template <typename T, int MAX>
Queue<T, MAX>::Queue() : front(-1), rear(-1), count(0) {}

template <typename T, int MAX>
Queue<T, MAX>::~Queue() {}

template <typename T, int MAX>
bool Queue<T, MAX>::empty() const {
    return front == rear;
}

template <typename T, int MAX>
bool Queue<T, MAX>::full() const {
    return front == 0 && rear == MAX - 1;
}

template <typename T, int MAX>
void Queue<T, MAX>::push(const T &item) {
    if (full()) {
        std::cerr << "Queue is full\n";
        return;
    }
    rear++;
    count++;
    data[rear] = item;
}

template <typename T, int MAX>
T Queue<T, MAX>::pop() {
    T item{};
    if (empty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }

    front++;
    count--;
    item = data[front];
    return item;
}

template <typename T, int MAX>
T Queue<T, MAX>::peek() const {
    T item{};
    if (empty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }
    item = data[front];
    return item;
}

template <typename T, int MAX>
int Queue<T, MAX>::size() const {
    return count;
}

template <typename T, int MAX>
bool Queue<T, MAX>::has(const T &item) const {
    for (int i = 0; i < this->size(); ++i) {
        if (data[(front + i) % MAX] == item) {
            return true;
        }
    }
    return false;
}

template <typename T, int MAX>
void Queue<T, MAX>::clear() {
    front = -1;
    rear = -1;
    count = 0;
}
