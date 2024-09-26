#include <malloc.h>
#include <stdio.h>

#define MAX_SIZE (102)

////////////////////////////////////////////////////////
////////////  TRIES ////////////////////////////////////

// Initialize the Trie
extern void init_trie();

// Insert a string "key" in trie
extern void Tries_insert(const char *key);

// Returns true if whole "key" presents in trie, else false
extern bool Tries_search(const char *key);

// Returns number of keys having "key" as a prefix
extern int Tries_CountofkeysWithPrefix(const char *key);

// deletes a key from trie
extern void Tries_deleteKey(const char *key);

int main() {
    setbuf(stdout, NULL);

    freopen("input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    init_trie();

    for (int tc = 1; tc <= T; tc++) {
        int cmd, val;
        char *str;
        str = (char *)malloc(sizeof(char) * MAX_SIZE);
        scanf("%d %s", &cmd, str);

        switch (cmd) {
        case 0:
            Tries_insert(str);
            break;
        case 1:
            val = Tries_search(str);
            printf("%d\n", val);
            break;
        case 2:
            val = Tries_CountofkeysWithPrefix(str);
            printf("%d\n", val);
            break;
        case 3:
            Tries_deleteKey(str);
            break;
        }
    }
    return 0;
}
