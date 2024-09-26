#include <string.h>

#define MAX_L 8

struct RESULT {
    int success;
    char word[MAX_L + 1];
};

const int MAX_DICT = 30000 + 10000;

int cntDict;
char dict[MAX_DICT][MAX_L + 1];

struct Node {
    int dictIdx;
    Node *parent;
    Node *child[26];
    int num[26];

    void init() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
            num[i] = 0;
        }

        parent = nullptr;
        dictIdx = 0;
    }

    int add(char str[], int pos);
    int erase(char str[], int pos);
    RESULT find(int order, int pos);
    int getIndex(char str[], int pos);
};

int cntTries;
Node tries[MAX_DICT * MAX_L];

Node *getTrie() {
    return &tries[cntTries++];
}

Node *root;

int Node::add(char str[], int pos) {
    if (str[pos] == '\0') {
        if (dictIdx != 0)
            return 0;

        dictIdx = cntDict++;
        strcpy(dict[dictIdx], str);
        return 1;
    }

    int c = str[pos] - 'a';
    if (child[c] == nullptr) {
        child[c] = getTrie();
        child[c]->init();
        child[c]->parent = this;
    }

    if (child[c]->add(str, pos + 1)) {
        ++num[c];
        return 1;
    }

    return 0;
}

int Node::erase(char str[], int pos) {
    if (str[pos] == '\0') {
        if (dictIdx == 0)
            return 0;
        dictIdx = 0;
        return 1;
    }

    int c = str[pos] - 'a';
    if (child[c] == nullptr || num[c] == 0)
        return 0;

    if (child[c]->erase(str, pos + 1)) {
        --num[c];
        return 1;
    }

    return 0;
}

RESULT Node::find(int order, int pos) {
    RESULT res;

    if (dictIdx != 0) {
        --order;
        if (order == 0) {
            res.success = 1;
            strcpy(res.word, dict[dictIdx]);
            return res;
        }
    }

    int sum = 0;
    for (int i = 0; i < 26; ++i) {
        if (sum + num[i] >= order)
            return child[i]->find(order - sum, pos + 1);
        sum += num[i];
    }

    res.success = 0;
    return res;
}

int Node::getIndex(char str[], int pos) {
    if (str[pos] == '\0')
        return dictIdx != 0 ? 0 : -1;

    int c = str[pos] - 'a';
    if (child[c] == nullptr)
        return -1;

    int add = child[c]->getIndex(str, pos + 1);
    if (add == -1)
        return -1;

    int ret = dictIdx != 0 ? 1 : 0;
    for (int i = 0; i < c; ++i)
        ret += num[i];

    return ret + add;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void init(int N, char mWordList[][MAX_L + 1]) {
    cntTries = 0;
    cntDict = 1;

    root = getTrie();
    root->init();

    for (int i = 0; i < N; ++i)
        root->add(mWordList[i], 0);
}

int add(char mWord[]) {
    return root->add(mWord, 0);
}

int erase(char mWord[]) {
    return root->erase(mWord, 0);
}

RESULT find(char mInitial, int mIndex) {
    int c = mInitial - 'a';
    if (root->child[c] != nullptr)
        return root->child[c]->find(mIndex, 0);

    RESULT res;

    res.success = 0;
    return res;
}

int getIndex(char mWord[]) {
    return root->getIndex(mWord, 0) + 1;
}
