#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#define MAX_L 8

struct RESULT {
    int success;
    char word[MAX_L + 1];
};

class Trie {
    static const int SIZE = 'z' - 'a' + 1;
    static const int MAX_DICT = 30000 + 10000;

    struct Node {
        int dictIndex = 0;
        Node *parent = nullptr;
        Node *child[SIZE];
        int num[SIZE] = {};
        Node() {
            for (int i = 0; i < SIZE; i++)
                child[i] = nullptr;
        }
    };

    Node *root;

    char dict[MAX_DICT][MAX_L + 1];
    int cntDict = 1;

    bool add(Node *node, const char str[], int pos = 0) {
        if (str[pos] == '\0') {
            if (node->dictIndex != 0)
                return false;

            node->dictIndex = cntDict++;
            strcpy(dict[node->dictIndex], str);
            return true;
        }

        int c = str[pos] - 'a';
        if (node->child[c] == nullptr) {
            node->child[c] = new Node();
            node->child[c]->parent = node;
        }

        if (add(node->child[c], str, pos + 1)) {
            ++node->num[c];
            return true;
        }

        return false;
    }

    bool erase(Node *node, char str[], int pos = 0) {
        if (str[pos] == '\0') {
            if (node->dictIndex == 0)
                return false;
            node->dictIndex = 0;
            return true;
        }

        int c = str[pos] - 'a';
        if (node->child[c] == nullptr || node->num[c] == 0)
            return false;

        if (erase(node->child[c], str, pos + 1)) {
            --node->num[c];
            return true;
        }

        return false;
    }

    RESULT find(Node *node, int order, int pos = 0) {
        RESULT res;

        if (node->dictIndex != 0) {
            --order;
            if (order == 0) {
                res.success = 1;
                strcpy(res.word, dict[node->dictIndex]);
                return res;
            }
        }

        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (sum + node->num[i] >= order)
                return find(node->child[i], order - sum, pos + 1);
            sum += node->num[i];
        }

        res.success = 0;
        return res;
    }

    int getIndex(Node *node, char str[], int pos = 0) {
        if (str[pos] == '\0')
            return node->dictIndex != 0 ? 0 : -1;

        int c = str[pos] - 'a';
        if (node->child[c] == nullptr)
            return -1;

        int add = getIndex(node->child[c], str, pos + 1);
        if (add == -1)
            return -1;

        int ret = node->dictIndex != 0 ? 1 : 0;
        for (int i = 0; i < c; ++i)
            ret += node->num[i];

        return ret + add;
    }

public:
    Trie() {
        root = new Node();
    }

    bool add(const char word[]) {
        return add(root, word);
    }

    bool erase(char word[]) {
        return erase(root, word);
    }

    RESULT find(char initial, int mIndex) {
        int c = initial - 'a';
        if (root->child[c] != nullptr)
            return find(root, mIndex);

        RESULT res;

        res.success = 0;
        return res;
    }

    int getIndex(char word[]) {
        return 0;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Trie *trie = nullptr;
void init(int N, char mWordList[][MAX_L + 1]) {
    if (trie != nullptr)
        delete trie;

    trie = new Trie();

    for (int i = 0; i < N; i++) {
        trie->add(mWordList[i]);
    }
}
int add(char mWord[]) { return trie->add(mWord); }
int erase(char mWord[]) { return trie->erase(mWord); }
RESULT find(char mInitial, int mIndex) { return trie->find(mInitial, mIndex); }
int getIndex(char mWord[]) { return trie->getIndex(mWord); }
