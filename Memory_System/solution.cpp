#include <cstdlib>
using namespace std;
class Solution {
private:
    static const int MAX_NODE = 30000;
    static const int MAX_HASH_SIZE = 40000;
    const int N;

    struct Node {
        int addr;
        int size;
        bool free;
        Node *left;
        Node *right;
        Node *prev;
        Node *next;
        Node() : addr(0), size(0), free(true), left(NULL), right(NULL), prev(NULL), next(NULL) {}
        Node(int N) : addr(0), size(N), free(true), left(NULL), right(NULL), prev(NULL), next(NULL) {}

    } * ListHead, *TreeRoot, NodePool[MAX_NODE];
    int NodePoolCnt;

    struct HashId {
        int key;
        Node *data;
        HashId() : key(-1), data(NULL) {}
    } HashIdTbl[MAX_HASH_SIZE];

    Node *findAddr(int key) {
        unsigned long h = key % MAX_HASH_SIZE;
        int cnt = MAX_HASH_SIZE;

        while (HashIdTbl[h].key != -1 && cnt--) {
            if (HashIdTbl[h].key == key) {
                return HashIdTbl[h].data;
            }
            h = (h + 1) % MAX_HASH_SIZE;
        }
        return nullptr;
    }

    void addAddr(int key, Node *data) {
        unsigned long h = key % MAX_HASH_SIZE;

        while (HashIdTbl[h].key != -1) {
            if (HashIdTbl[h].key == key) {
                HashIdTbl[h].data = data;
                return;
            }
            h = (h + 1) % MAX_HASH_SIZE;
        }

        HashIdTbl[h].key = key;
        HashIdTbl[h].data = data;
    }

    Node *newNode(int size) {
        Node *ret = &NodePool[NodePoolCnt++];
        ret->size = size;
        ret->free = true;
        ret->left = ret->right = ret->prev = ret->next = nullptr;
        return ret;
    }

    Node *treeInsert(Node *node, Node *newNode) {
        if (node == nullptr) {
            node = newNode;
            node->left = node->right = nullptr;
        } else if (newNode->size < node->size)
            node->left = treeInsert(node->left, newNode);
        else if (newNode->size > node->size)
            node->right = treeInsert(node->right, newNode);
        else {
            if (newNode->addr < node->addr)
                node->left = treeInsert(node->left, newNode);
            else
                node->right = treeInsert(node->right, newNode);
        }

        return node;
    }

    Node *treeFindMax(Node *node) {
        if (node == nullptr)
            return nullptr;
        else if (node->right == nullptr)
            return node;
        else
            return treeFindMax(node->right);
    }

    Node *treeRemove(Node *node, Node *delNoe) {
        if (node == nullptr)
            return nullptr;

        if (delNoe->size < node->size)
            node->left = treeRemove(node->left, delNoe);
        else if (delNoe->size > node->size)
            node->right = treeRemove(node->right, delNoe);
        else {
            if (delNoe->addr < node->addr)
                node->left = treeRemove(node->left, delNoe);
            else if (delNoe->addr > node->addr)
                node->right = treeRemove(node->right, delNoe);
            else if (node->left && node->right) {
                Node *maxNode = treeFindMax(node->left);
                Node *newLeft = treeRemove(node->left, maxNode);
                Node *newRight = node->right;
                node = maxNode;
                node->left = newLeft;
                node->right = newRight;
            } else {
                if (node->left == nullptr)
                    node = node->right;
                else if (node->right == nullptr)
                    node = node->left;
            }
        }

        return node;
    }

    Node *treeSearch(int size) {
        Node *curr = TreeRoot;
        Node *candi = nullptr;

        while (curr) {
            if (curr->size < size) {
                curr = curr->right;
            } else if (curr->size >= size) {
                candi = curr;
                curr = curr->left;
            }
        }

        if (candi && candi->size >= size)
            return candi;
        return nullptr;
    }

    void listInsert(Node *node, Node *newNode) {
        newNode->prev = node;
        newNode->next = node->next;
        if (node->next) {
            node->next->prev = newNode;
        }
        node->next = newNode;
    }

    void listRemove(Node *delNode) {
        Node *prev = delNode->prev;
        Node *next = delNode->next;
        if (prev)
            prev->next = next;
        else
            ListHead = next;

        if (next)
            next->prev = prev;
    }

public:
    Solution(int N = 0) : N(N), NodePoolCnt(0) {
        ListHead = TreeRoot = newNode(N);
        ListHead->addr = 0;
    }

    int allocate(int mSize) {
        Node *freeNode = treeSearch(mSize);
        if (!freeNode)
            return -1;

        TreeRoot = treeRemove(TreeRoot, freeNode);
        addAddr(freeNode->addr, freeNode);

        if (mSize != freeNode->size) {
            Node *node = newNode(freeNode->size - mSize);
            node->addr = freeNode->addr + mSize;
            TreeRoot = treeInsert(TreeRoot, node);
            listInsert(freeNode, node);
        }

        freeNode->size = mSize;
        freeNode->free = false;
        return freeNode->addr;
    }

    int release(int mAddr) {
        Node *delNode = findAddr(mAddr);
        if (!delNode)
            return -1;

        addAddr(mAddr, nullptr);

        int ret = delNode->size;
        Node *left = delNode->prev;
        Node *right = delNode->next;
        if (left && left->free) {
            TreeRoot = treeRemove(TreeRoot, left);
            left->size += delNode->size;
            if (right && right->free) {
                left->size += right->size;
                listRemove(delNode);
                listRemove(right);
                TreeRoot = treeRemove(TreeRoot, right);
            } else {
                listRemove(delNode);
            }
            TreeRoot = treeInsert(TreeRoot, left);
        } else if (right && right->free) {
            TreeRoot = treeRemove(TreeRoot, right);
            right->addr = delNode->addr;
            right->size += delNode->size;
            listRemove(delNode);
            TreeRoot = treeInsert(TreeRoot, right);
        } else {
            delNode->free = true;
            TreeRoot = treeInsert(TreeRoot, delNode);
        }
        return ret;
    }
} * solution;

////////////////////////////////////////////////////////////////////////////////

void init(int N) {
    if (solution)
        delete solution;
    solution = new Solution(N);
}

int allocate(int mSize) {
    return solution->allocate(mSize);
}

int release(int mAddr) {
    return solution->release(mAddr);
}
