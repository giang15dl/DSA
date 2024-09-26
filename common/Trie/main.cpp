#include "trie.hpp"

int main() {
    shared_ptr<Trie> trie(new Trie());
    // Trie *trie = new Trie();

    trie->insert("aaa");
    trie->insert("aab");
    trie->insert("aac");
    trie->insert("abc");
    trie->insert("abd");

    int count = 0;
    count = trie->countPrefix("a");
    count = trie->countPrefix("aa");
    count = trie->countPrefix("aaa");
    count = trie->countPrefix("ab");

    trie->find("aaa");
    trie->find("abc");
    trie->find("aab");

    trie->erase("aaa");
    trie->erase("aab");
    trie->erase("aac");

    return 0;
}
