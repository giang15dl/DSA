template <typename T, int MAX>
class Deque {
public:
    Deque() : front(-1), rear(0) {}

    void push_front(T key) {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = MAX - 1;
        else
            front = front - 1;
        data[front] = key;
    }

    void push_back(T key) {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
        data[rear] = key;
    }

    T pop_front() {
        T temp = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;

        return temp;
    }

    T pop_back() {
        T temp = data[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = MAX - 1;
        else
            rear = rear - 1;

        return temp;
    }

    bool full() {
        return (front == 0 && rear == MAX - 1) || front == rear + 1;
    }

    bool empty() const {
        return front == -1;
    }

private:
    int front, rear;
    T data[MAX];
};
