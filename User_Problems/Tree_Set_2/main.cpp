#include <iostream>
#define INT_MAX 2147483647

template <class T>
class set {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        Node(T data = 0) : data(data), left(NULL), right(NULL) {}
    } *p_root;

    int m_size;

public:
    set() : p_root(NULL), m_size(0) {}

    int size() const {
        return m_size;
    }

    void insert(const T &x) {
        if (!p_root) {
            p_root = new Node(x);
            m_size++;
            return;
        }

        Node *curr = p_root;
        Node *prev;

        while (curr) {
            if (curr->data == x)
                return;
            prev = curr;
            if (x < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (x < prev->data)
            prev->left = new Node(x);
        else
            prev->right = new Node(x);
        m_size++;
    }

    void erase(const T &x) {
        Node *curr = p_root;
        Node *prev;

        while (curr) {
            if (x == curr->data)
                break;
            prev = curr;
            if (x < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (!curr)
            return;

        m_size--;
        if (curr->left && curr->right) {
            Node *lower = curr->left;
            if (lower->right == NULL) {
                curr->left = lower->left;
            } else {
                prev = lower;
                while (lower->right) {
                    prev = lower;
                    lower = lower->right;
                }
                prev->right = lower->left;
            }
            curr->data = lower->data;
            delete lower;
            return;
        }

        Node *alter;
        if (curr->left == NULL)
            alter = curr->right;
        else
            alter = curr->left;

        if (curr == p_root) {
            p_root = alter;
        } else {
            if (x < prev->data)
                prev->left = alter;
            else
                prev->right = alter;
        }

        delete curr;
    }

    bool contains(const T &x) const {
        Node *curr = p_root;

        while (curr) {
            if (x == curr->data)
                return true;
            if (x < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        return false;
    }

    int lower(const T &x) const {
        Node *curr = p_root;
        int res = INT_MAX;

        while (curr) {
            if (x > curr->data) {
                res = curr->data;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return res;
    }

    int higher(const T &x) const {
        Node *curr = p_root;
        int res = INT_MAX;

        while (curr) {
            if (x < curr->data) {
                res = curr->data;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return res;
    }
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "#" << t + 1;
        int N;
        cin >> N;
        set<int> ts;
        for (int i = 0; i < N; i++) {
            char cmd[10];
            int x;
            bool flag;
            int ans;
            cin >> cmd;
            switch (cmd[0]) {
            case 'a':
                cin >> x;
                ts.insert(x);
                break;
            case 'r':
                cin >> x;
                ts.erase(x);
                break;
            case 'c':
                cin >> x;
                flag = ts.contains(x);
                if (flag)
                    cout << " true";
                else
                    cout << " false";
                break;
            case 'l':
                cin >> x;
                ans = ts.lower(x);
                if (ans == INT_MAX)
                    printf(" null");
                else
                    printf(" %d", ans);
                break;
            case 'h':
                cin >> x;
                ans = ts.higher(x);
                if (ans == INT_MAX)
                    cout << " null";
                else
                    cout << " " << ans;
                break;
            case 's':
                cout << " " << ts.size();
                break;
            default:
                break;
            }
        }
        cout << endl;
    }

    return 0;
}
