class Trie {
    static const int SIZE = 'z' - 'a' + 1;

    struct Node {
        int isLeaf;
        int count;
        Node *parent;
        Node *child[SIZE];

        Node() : isLeaf(0), count(0), parent(nullptr) {
            for (int i = 0; i < SIZE; i++)
                this->child[i] = nullptr;
        }
    };

    void clear(Node *root) {
        for (int i = 0; i < SIZE; i++)
            if (root->child[i])
                clear(root->child[i]);
        delete root;
    }

    Node *root;

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        clear(root);
    }

    void insert(const char *key) {
        Node *node = root;
        while (*key != '\0') {
            node->count++;
            int index = *key++ - 'a';
            if (!node->child[index]) {
                node->child[index] = new Node();
                node->child[index]->parent = node;
            }
            node = node->child[index];
        }
        node->isLeaf++;
        node->count++;
    }

    bool find(const char *key) {
        Node *node = root;
        while (*key != '\0') {
            int index = *key++ - 'a';
            if (!node->child[index] || !node->child[index]->count)
                return 0;
            node = node->child[index];
        }
        if (!node->isLeaf)
            return 0;
        return 1;
    }

    int count(const char *key) {
        Node *node = root;
        while (*key != '\0') {
            int index = *key++ - 'a';
            if (!node->child[index] || !node->child[index]->count)
                return 0;
            node = node->child[index];
        }
        return (node->count);
    }

    void erase(const char *key) {
        Node *node = root;
        while (*key != '\0') {
            int index = *key++ - 'a';
            if (!node->child[index] || !node->child[index]->count)
                return;
            node = node->child[index];
        }
        if (node->isLeaf) {
            node->isLeaf--;
            while (node != nullptr) {
                node->count--;
                node = node->parent;
            }
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Trie *trie;

void init_trie() {
    if (trie)
        delete trie;
    trie = new Trie();
}

void Tries_insert(const char *key) {
    trie->insert(key);
}

bool Tries_search(const char *key) {
    return trie->find(key);
}

int Tries_CountofkeysWithPrefix(const char *key) {
    return trie->count(key);
}

void Tries_deleteKey(const char *key) {
    trie->erase(key);
}
