#define INT_MAX 2147483647
template<typename T>
class list {
private:
    T m_size;

    struct Node {
        T m_data;
        Node *p_prev, *p_next;

        Node() : m_data(0), p_prev(NULL), p_next(NULL) {}
        Node(T data) : m_data(data), p_prev(NULL), p_next(NULL) {}
    }*p_head;

public:
    list() : m_size(0), p_head(NULL) {}

    bool empty() const {
        return p_head == NULL;
    }

    int size() const {
        return m_size;
    }

    void push_front(const T& data){
        Node* newNode = new Node(data);
        if(empty()){
            p_head = newNode;
            m_size++;
            return;
        }

        newNode->p_next = p_head;
        p_head->p_prev = newNode;
        p_head = newNode;
        m_size++;
    }

    void push_back(const T& data){
        Node* newNode = new Node(data);
        if (empty()) {
            p_head = newNode;
            m_size++;
            return;
        }

        Node* temp = p_head;
        while (temp->p_next != NULL)
            temp = temp->p_next;

        temp->p_next = newNode;
        newNode->p_prev = temp;
        m_size++;
    }

    void insert(const int &pos, const T &data) {
        if (pos < 1)
            return;

        if (m_size == 0)
            p_head = NULL;

        if(pos == 1){ 
            push_front(data);
            return;
        }

        if(pos > m_size ){
            push_back(data);
            return;
        }

        Node* temp = p_head;
        for (int i = 1; temp != NULL && i < pos; i++)
            temp = temp->p_next;

        Node* newNode = new Node(data);
        newNode->p_next = temp;
        newNode->p_prev = temp->p_prev;
        newNode->p_prev->p_next = newNode;
        temp->p_prev = newNode;
        m_size++;
    }

    void pop_front() {
        if (empty())
            return;

        Node* temp = p_head;
        p_head = p_head->p_next;
        if (p_head != NULL)
            p_head->p_prev = NULL;

        delete temp;
        m_size--;
    }

    void pop_back() {
        if (empty())
            return;

        Node* temp = p_head;
        if (temp->p_next == NULL) {
            p_head = NULL;
            delete temp;
            return;
        }

        while (temp->p_next != NULL)
            temp = temp->p_next;

        temp->p_prev->p_next = NULL;
        m_size--;
        delete temp;
    }

    void erase(int pos) {
        if (pos > m_size)
            return;

        if (pos == 1) {
            pop_front();
            return;
        }

        if(pos == m_size){
            pop_back();
            return;
        }

        if (empty())
            return;

        Node* temp = p_head;
        for (int i = 1; temp != NULL && i < pos; i++)
            temp = temp->p_next;

        if (temp->p_next != NULL)
            temp->p_next->p_prev = temp->p_prev;

        if (temp->p_prev != NULL)
            temp->p_prev->p_next = temp->p_next;

        m_size--;
        delete temp;
    }

    void print(int pos = INT_MAX){
        if (empty()) {
            std::cout << "empty ";
            return;
        }

        Node* temp = p_head;
        if (pos >= m_size) {
            while(temp != NULL) {
                std::cout << temp->m_data << " ";
                temp = temp->p_next;
            }
        }
        else {
            while(pos != 0) {
                std::cout << temp->m_data << " ";
                temp = temp->p_next;
                pos--;
            }
        }
    }
};