#include <memory>
#include <string>

using namespace std;
class Trie {
    static const int SIZE = 'z' - 'a' + 1;
    struct Node {
        bool isLeaf;
        int count;
        shared_ptr<Node> parent;
        shared_ptr<Node> child[SIZE];

        Node() : isLeaf(false), count(0), parent(shared_ptr<Node>()) {
            for (int i = 0; i < SIZE; i++)
                child[i] = shared_ptr<Node>();
        }
    };

    shared_ptr<Node> root;
    int count;

    int to_integer(char c) const {
        return static_cast<int>(c - 'a');
    }

    bool part_delete(const string &word, shared_ptr<Node> &checkout) {
        // Word is not present in the Trie then returns false and stops further recursion
        if (checkout == nullptr)
            return false;

        // At the end of the word if the word is present in trie then setting isWord to false either returning false
        if (word.size() == 0) {
            if (checkout->isLeaf == true) {
                checkout->isLeaf = false;
                return true;
            }
            return false;
        }

        // String excluding first character
        string substr = word.substr(1);

        // Recursive call to Partdelete for rest of the string(part)
        if (part_delete(substr, checkout->child[to_integer(word[0])])) {

            // Checks whether it is empty node then delete this node
            if (empty(checkout->child[to_integer(word[0])])) {

                // Resetting memory and making it nullptr
                checkout->child[to_integer(word[0])].reset();

                checkout->child[to_integer(word[0])] = nullptr;

                return true;
            } else
                return true;
        } else
            return false;

        return false;
    }

public:
    Trie() : count(0) {
        root = shared_ptr<Node>(new Node());
    }

    ~Trie() {}

    void insert(const string &word) {
        shared_ptr<Node> node = root;

        for (size_t i = 0; i < word.size(); i++) {
            int index = to_integer(word[i]);
            // If word after some prefix is not present then creates new node
            if (node->child[index] == shared_ptr<Node>(nullptr))
                node->child[index] = shared_ptr<Node>(new Node());

            node = (node->child[index]);
        }

        // Now word is added in Trie so at leaf node for that word isWord=true
        node->isLeaf = true;
    }

    // Searching for word whether it is present in Trie
    bool find(const string &word) {
        shared_ptr<Node> node = root;

        for (size_t i = 0; i < word.size(); i++) {
            int index = to_integer(word[i]);
            // If at any point in Trie Node for particular character is not present means nullptr then return false
            if (node->child[index] == shared_ptr<Node>(nullptr))
                return false;
            node = node->child[index];
        }

        // At the end of the word checking whether this word is really present or not
        if (node->isLeaf == true)
            return true;

        return false;
    }

    // For ease of recursion; passing root to Partdelete
    bool erase(const string &word) {
        if (part_delete(word, root))
            return true;
        return false;
    }

    // Checks whether there is no children present
    bool empty(shared_ptr<Node> node) const {
        for (int i = 0; i < SIZE; i++)
            if (node->child[i] != nullptr || node->isLeaf == true)
                return false;
        return true;
    }
};

int main() {
    shared_ptr<Trie> trie(new Trie());
    // Trie *trie = new Trie();

    string word1 = "aaa";
    string word2 = "aab";
    string word3 = "aac";

    trie->insert(word1);
    trie->insert(word2);
    trie->insert(word3);

    trie->find(word1);
    trie->find(word2);
    trie->find(word3);

    trie->erase(word1);
    trie->erase(word2);
    trie->erase(word3);

    return 0;
}
