#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
private:
    int H, W;
    list<char> str;
    unsigned int cursor;
public:
    Solution(int H = 0, int W = 0, char mStr[] = "") : H(H), W(W), cursor(0) {
        for (int i = 0; mStr[i] != 0; i++) {
            str.push_back(mStr[i]);
        }
    }

    void insert(char mChar) {
        auto it = str.begin();
        std::advance(it, cursor);
        str.insert(it, mChar);
        cursor++;
    }

    char moveCursor(int mRow, int mCol) {
        cursor = mRow * W + mCol;
        auto it = str.begin();
        if (cursor >= str.size()) {
            cursor = str.size();
            return '$';
        }
        std::advance(it, cursor);
        return *it;
    }

    int countCharacter(char mChar) {
        auto it = str.begin();
        std::advance(it, cursor);
        std::vector<char> matches;
        copy_if(it, str.end(), back_inserter(matches), [&](char c){ return c == mChar; });
        return matches.size();
    }

}solution;

///////////////////////////////////////////////////////////////////////////////
void init(int H, int W, char mStr[]) { solution = Solution(H, W, mStr); }
void insert(char mChar) { solution.insert(mChar); }
char moveCursor(int mRow, int mCol) { return solution.moveCursor(mRow - 1, mCol - 1); }
int countCharacter(char mChar) { return solution.countCharacter(mChar); }