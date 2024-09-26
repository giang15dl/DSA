#include <cstdlib>
#include <memory>

using std::shared_ptr;
class Trie {
    static const int SIZE = 'z' - 'a' + 1; // letters in the alphabet

    struct Node {
        int count;
        shared_ptr<Node> child[SIZE];

        Node() : count(0) {
            for (int i = 0; i < SIZE; i++)
                child[i] = shared_ptr<Node>();
        }

        ~Node() {}
    };

    shared_ptr<Node> root;

    void search(const char str[], shared_ptr<Node> node, int &count, int pos = 0) {
        if (node == shared_ptr<Node>(nullptr))
            return;

        if (str[pos] == 0) {
            count += node->count;
            return;
        }

        if (str[pos] == '?') {
            for (int i = 0; i < SIZE; i++)
                if (node->child[i] != shared_ptr<Node>())
                    search(str, node->child[i], count, pos + 1);
        } else {
            search(str, node->child[str[pos] - 'a'], count, pos + 1);
        }
    }

    void remove(const char str[], shared_ptr<Node> node, int &count, int pos = 0) {
        if (node == NULL)
            return;

        if (str[pos] == 0) {
            count += node->count;
            node->count = 0;
            return;
        }

        if (str[pos] == '?') {
            for (int i = 0; i < SIZE; i++)
                if (node->child[i] != shared_ptr<Node>(nullptr))
                    remove(str, node->child[i], count, pos + 1);
        } else {
            remove(str, node->child[str[pos] - 'a'], count, pos + 1);
        }
    }

public:
    Trie() {
        root = shared_ptr<Node>(new Node());
    }

    ~Trie() {}

    int add(const char str[]) {
        shared_ptr<Node> node = root;
        for (int i = 0; str[i] != 0; i++) {
            int index = str[i] - 'a';
            if (node->child[index] == shared_ptr<Node>(nullptr))
                node->child[index] = shared_ptr<Node>(new Node());

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
shared_ptr<Trie> trie;
void init() { trie = shared_ptr<Trie>(new Trie()); }
int add(char str[]) { return trie->add(str); }
int remove(char str[]) { return trie->remove(str); }
int search(char str[]) { return trie->search(str); }
////////////////////////////////////////////////////////////////////////////////
