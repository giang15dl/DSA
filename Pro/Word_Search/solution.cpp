#include <cstdlib>

class Trie {
    static const int SIZE = 'z' - 'a' + 1; // letters in the alphabet

    struct Node {
        int count;
        Node *child[SIZE];

        Node() : count(0) {
            for (int i = 0; i < SIZE; i++)
                child[i] = nullptr;
        }

        ~Node() {
            for (int i = 0; i < SIZE; i++)
                delete child[i];
        }
    };

    Node *root;

    void search(const char str[], Node *node, int pos, bool removed, int &count) {
        if (node == NULL)
            return;

        if (str[pos] == 0) {
            count += node->count;
            if (removed)
                node->count = 0;
            return;
        }

        if (str[pos] == '?') {
            for (int i = 0; i < SIZE; i++)
                if (node->child[i] != NULL)
                    search(str, node->child[i], pos + 1, removed, count);
        } else {
            search(str, node->child[str[pos] - 'a'], pos + 1, removed, count);
        }
    }

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    int add(const char str[]) {
        Node *it = root;
        for (int i = 0; str[i] != 0; i++) {
            char index = str[i] - 'a';
            if (it->child[index] == NULL) {
                it->child[index] = new Node();
            }
            it = it->child[index];
        }
        it->count++;
        return it->count;
    }

    int remove(const char str[]) {
        int count = 0;
        search(str, root, 0, true, count);
        return count;
    }

    int search(const char str[]) {
        int count = 0;
        search(str, root, 0, false, count);
        return count;
    }
};

////////////////////////////////////////////////////////////////////////////////
Trie *trie;
void init() {
    if (trie)
        delete trie;
    trie = new Trie();
}
int add(char str[]) { return trie->add(str); }
int remove(char str[]) { return trie->remove(str); }
int search(char str[]) { return trie->search(str); }
////////////////////////////////////////////////////////////////////////////////
