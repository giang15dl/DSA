#define MAX_L 8

struct RESULT {
    int success;
    char word[MAX_L + 1];
};

class Solution {
public:
    Solution() {}
    Solution(int N, char mWordList[][MAX_L + 1]) {}

    int add(char mWord[]) {
        return -1;
    }

    int erase(char mWord[]) {
        return -1;
    }

    RESULT find(char mInitial, int mIndex) {
        RESULT res;

        res.success = -1;
        res.word[0] = '\0';

        return res;
    }

    int getIndex(char mWord[]) {
        return -1;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Solution solution;
void init(int N, char mWordList[][MAX_L + 1]) { solution = Solution(N, mWordList); }
int add(char mWord[]) { return solution.add(mWord); }
int erase(char mWord[]) { return solution.erase(mWord); }
RESULT find(char mInitial, int mIndex) { return solution.find(mInitial, mIndex); }
int getIndex(char mWord[]) { return solution.getIndex(mWord); }
