class Trie {
    static const int SIZE = 'z' - 'a' + 1; // letters in the alphabet

    struct Node {
        int count;
        Node *child[SIZE];

        Node() : count(0) {
            for (int i = 0; i < SIZE; i++)
                child[i] = nullptr;
        }

        ~Node() {}
    };

    int countNode = 0;
    Node *newNode() {
        static const int MAX = 300000;
        static Node nodes[MAX];
        for (int i = 0; i < SIZE; i++) {
            nodes[countNode].child[i] = nullptr;
        }

        nodes[countNode].count = 0;
        return &nodes[countNode++];
    }

    Node *root;

    void clear(Node *node) {
        if (node == nullptr)
            return;
        for (int i = 0; i < SIZE; i++)
            clear(node->child[i]);
        delete node;
    }

    void search(const char str[], Node *node, int &count, int pos = 0) {
        if (node == nullptr)
            return;

        if (str[pos] == 0) {
            count += node->count;
            return;
        }

        if (str[pos] == '?') {
            for (int i = 0; i < SIZE; i++)
                if (node->child[i] != nullptr)
                    search(str, node->child[i], count, pos + 1);
        } else {
            search(str, node->child[str[pos] - 'a'], count, pos + 1);
        }
    }

    void remove(const char str[], Node *node, int &count, int pos = 0) {
        if (node == nullptr)
            return;

        if (str[pos] == 0) {
            count += node->count;
            node->count = 0;
            return;
        }

        if (str[pos] == '?') {
            for (int i = 0; i < SIZE; i++)
                if (node->child[i] != nullptr)
                    remove(str, node->child[i], count, pos + 1);
        } else {
            remove(str, node->child[str[pos] - 'a'], count, pos + 1);
        }
    }

public:
    Trie() {
        root = newNode();
    }

    ~Trie() {
        clear(root);
    }

    int add(const char str[]) {
        Node *node = root;
        for (int i = 0; str[i] != 0; i++) {
            int index = str[i] - 'a';
            if (node->child[index] == nullptr)
                node->child[index] = newNode();

            node = node->child[index];
        }
        node->count++;
        return node->count;
    }

    int remove(const char str[]) {
        int count = 0;
        remove(str, root, count);
        return count;
    }

    int search(const char str[]) {
        int count = 0;
        search(str, root, count);
        return count;
    }
};

////////////////////////////////////////////////////////////////////////////////
Trie *trie;
void init() {
    trie = new Trie();
}
int add(char str[]) { return trie->add(str); }
int remove(char str[]) { return trie->remove(str); }
int search(char str[]) { return trie->search(str); }
////////////////////////////////////////////////////////////////////////////////
