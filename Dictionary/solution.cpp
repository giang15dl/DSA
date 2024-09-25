#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <set>
#include <string.h>
#include <string>
#define MAX_L 8

struct RESULT {
    int success;
    char word[MAX_L + 1];
};

using namespace std;
class Solution {
private:
    static const int SIZE = 'z' - 'a' + 1;

private:
    set<string> dict[SIZE];

public:
    Solution() {}
    Solution(int N, char mWordList[][MAX_L + 1]) {
        for (int i = 0; i < N; i++) {
            const char *word = mWordList[i];
            const char initial = word[0];
            const int letterIndex = initial - 'a';
            auto &words = dict[letterIndex];
            words.insert(word);
        }
    }

    int add(char word[]) {
        const char initial = word[0];
        const int letterIndex = initial - 'a';
        auto &words = dict[letterIndex];
        auto pair = words.insert(word);
        return pair.second;
    }

    int erase(char word[]) {
        const char initial = word[0];
        const int letterIndex = initial - 'a';
        auto &words = dict[letterIndex];
        int count = words.erase(word);
        return count;
    }

    RESULT find(char initial, int mIndex) {
        mIndex--;
        RESULT res;
        const int letterIndex = initial - 'a';
        auto &words = dict[letterIndex];

        if (words.size() <= mIndex) {
            res.success = 0;
            res.word[0] = '\0';
            return res;
        }

        auto it = words.begin();

        for (int i = 0; i < mIndex; i++) {
            it++;
        }

        auto word = *it;

        res.success = 1;
        strcpy(res.word, word.c_str());

        return res;
    }

    int getIndex(char word[]) {
        const char initial = word[0];
        const int letterIndex = initial - 'a';

        auto &words = dict[letterIndex];
        auto find = words.find(word);

        if (find == words.end())
            return 0;

        int index = 0;

        for (int i = 0; i < letterIndex; i++) {
            auto &words = dict[i];
            index += words.size();
        }

        for (auto it = words.begin(); it != find; it++) {
            index++;
        }

        return index + 1;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Solution solution;
void init(int N, char mWordList[][MAX_L + 1]) { solution = Solution(N, mWordList); }
int add(char mWord[]) { return solution.add(mWord); }
int erase(char mWord[]) { return solution.erase(mWord); }
RESULT find(char mInitial, int mIndex) { return solution.find(mInitial, mIndex); }
int getIndex(char mWord[]) { return solution.getIndex(mWord); }
