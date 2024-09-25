#include <cstdlib>

class Solution {
private:
    static const int SIZE = 26; // letters in the alphabet
    struct Node {
        Node *child[SIZE];
        int count;
        Node() : count(0) {
            for (int i = 0; i < SIZE; i++)
                child[i] = NULL;
        }
        ~Node() {
            for (int i = 0; i < SIZE; i++) {
                delete child[i];
            }
        }
    } *root;

    void searching(char str[], Node *node, int pos, bool removed, int &count) {
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
                    searching(str, node->child[i], pos + 1, removed, count);
        } else {
            searching(str, node->child[str[pos] - 'a'], pos + 1, removed, count);
        }
    }

public:
    Solution() {
        root = new Node();
    }

    ~Solution() {
        delete root;
    }

    int add(char str[]) {
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

    int remove(char str[]) {
        int count = 0;
        searching(str, root, 0, true, count);
        return count;
    }

    int search(char str[]) {
        int count = 0;
        searching(str, root, 0, false, count);
        return count;
    }

} *solution;

////////////////////////////////////////////////////////////////////////////////
void init() {
    if (solution)
        delete solution;
    solution = new Solution();
}
int add(char str[]) { return solution->add(str); }
int remove(char str[]) { return solution->remove(str); }
int search(char str[]) { return solution->search(str); }
////////////////////////////////////////////////////////////////////////////////
